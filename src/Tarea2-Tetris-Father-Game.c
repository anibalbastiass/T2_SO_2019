/*
 *  Tarea 2 - Sistemas Operativos
 *  1 Semestre, 2019
 * 
 *  Autor:      Anibal Bastias Soto
 *  ROL:        2604215-1
 *  Carrera:    Ingenieria de Ejecucion en Informatica
 * 
 *  Archivo:    Tarea2-Tetris-Father-Game.c 
 *  
 *  Archivo padre donde define las funciones de la inicializacion del juego
 *  Dibujando los caracteres en pantalla mediante la libreria ncurses y con 
 *  un timer dado para el refrezco de cada ciclo
 * 
 */

#include "include/Tarea2-Tetris-Settings.h"

// Inicializacion del juego Tetris
int game()
{
       // Inicializacion de la pantalla
       nodelay(stdscr, FALSE);

       // Dibujo de los paneles laterales y el central donde se desarrolla el juego
       init();

       // Seteo de teclas para interactuar con el juego
       setKeybind();
       clear();

       end = 0;
       level = startLevel;
       clrLines = 0;

       printw("\n\n\n       Presiona cualquier tecla para empezar\n");

       refresh();
       getch();

       // Se crean los procesos antes del while para que no se multipliquen
       // durante el tiempo, con pipes circulares

       // P0: Proceso Padre: Encargado del juego donde recibe la pieza mediante memoria compartida
       // del proceso hijo P3 en el pipe fd1

       /*
       pid_t pid = fork();
       int i;

       if (pid == 0)
       {
              
              // Proceso hijo
              close(fd1[PIPE_WRITE]); // no se usara para leer
              //write(fd1[PIPE_READ], read_msg, BUFF_SIZE);
              //printf("El mensaje dice %s\n", read_msg);

              for (i = 0; i < 3; i++)
              {
                     printf("hijo: %d\n", i);
                     sleep(1);
              }
              _exit(0); // nota: exit en lugar de _exit
       }
       else if (pid > 0)
       {
              close(fd1[PIPE_READ]); // no se usara para leer
              //write(fd1[PIPE_WRITE], write_msg, strlen(write_msg) + 1);
              close(fd1[PIPE_WRITE]); //ya no se usar ́a para escribir

              for (i = 0; i < 3; i++)
              {
                     printf("padre: %d\n", i);
                     //sleep(1);
              }
       }
       else
       {
              // ha ocurrido un error.
              fprintf(stderr, "no se ha podido bifurcar");
              exit(1);
       }
       */

       // P1: Proceso Hijo 1: Encargado de elegir la siguiente pieza y enviarla al proceso P2
       // por el pipe fd1

       // P2: Proceso Hijo 2: Recibe la pieza por el pipe fd1, rota la pieza y la envia al proceso
       // P3 mediante Pipe fd1

       // P3: Proceso Hijo 3: Recibe la pieza rotada y la envia al pipe fd1 en memoria compartida
       // al proceso padre P0 y sigue el flujo circular en el While

       wait(NULL);
       // Seta nivel indicado anteriormente
       updateLevel();

       // Inicia la pieza
       initPiece();

       // Actualiza pantalla mostrando la pieza
       updateScreen();

       nodelay(stdscr, TRUE);
       gettimeofday(&t1, NULL);

       // Acciones de teclas del teclado
       while (!usleep(DELAY))
       {
              switch (getch())
              {
              // Caso para bajar pieza
              case KEY_BIND_DROP:
                     if (moveDown())
                            continue;
                     ++dropped;
                     updateScreen();
                     continue;
              // Caso para salir del programa
              case KEY_BIND_EXIT:
                     return 1;
              // Caso para reiniciar juego
              case KEY_BIND_RESET:
                     return 0;
              // Caso para mover hacia la derecha la pieza
              case KEY_BIND_MOVE_RIGHT:
                     if (end)
                            continue;
                     moveRight();
                     updateScreen();
                     continue;
              // Caso para mover hacia la izquierda la pieza
              case KEY_BIND_MOVE_LEFT:
                     if (end)
                            continue;
                     moveLeft();
                     updateScreen();
                     continue;
              // Caso para rotar la pieza
              case KEY_BIND_ROTATE:
                     if (end || fixedPoint[0] < 2)
                            continue;
                     rotatePiece();
                     updateScreen();
                     continue;
              }

              // Si es end, entonces el juego ha terminado
              if (end)
              {
                     gameOver();
                     continue;
              }

              // Si cumple la regla de que ha logrado cierta cantidad
              // de borrar lineas, sube al siguiente nivel
              if (clrLines == LINESFORLVLUP)
              {
                     if (level < MAXLEVEL)
                     {
                            ++level;
                            updateLevel();
                            clrLines = 0;
                     }
              }

              // Inicia el timer para mover abajo de forma mas rapida
              gettimeofday(&t2, NULL);

              if ((((t2.tv_sec - t1.tv_sec) * 1000) + ((t2.tv_usec - t1.tv_usec) / 1000)) > DROPINTERVAL)
              {
                     if (moveDown())
                            continue;
                     updateScreen();
                     gettimeofday(&t1, NULL);
              }
       }
       return 1;
}

void init()
{
       // Inicializa la pantalla izquierda
       memcpy(left[0], "                        \0"
                       "                        \0"
                       "  TAREA 2 - SO (TETRIS) \0"
                       "  2604215-1             \0"
                       "                        \0"
                       "  NIVEL:                \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "  SIGUIENTE:            \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0"
                       "                        \0",
              (HEIGHT) * (WIDTH));

       // Inicializa la pantalla central del juego
       memcpy(center[0], "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<| . . . . . . . . . .|>\0"
                         "<|====================|>\0",
              (HEIGHT) * (WIDTH));

       // Inicializa la pantalla derecha del juego
       memcpy(right[0], "                        \0"
                        "                        \0"
                        "                        \0"
                        "    : IZQ      : DER    \0"
                        "         : ROTAR        \0"
                        "    : BAJAR    : REINIC \0"
                        "                        \0"
                        "                        \0"
                        "    : SALIR             \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0"
                        "                        \0",
              (HEIGHT) * (WIDTH));
}

void updateLevel()
{
       // Actualiza nivel en el panel izquierdo de la pantalla
       char *tmp = malloc(sizeof *tmp * 15);
       sprintf(tmp, "%-14d", level);
       memcpy(left[5] + 9, tmp, 14);
       free(tmp);
}

void updateScreen()
{
       // Actualiza pantalla en todos los paneles
       clear();
       printw("\n");

       for (int i = 2; i < HEIGHT; ++i)
       {
              if (show_next_piece)
                     showNextPiece();
              printw("%s", left[i]);
              printw("%s", center[i]);
              if (showText)
                     printw("%s", right[i]);
              printw("\n");
       }

       refresh();

       // Resetea y borra la siguiente pieza para mostrar la que esta en cola
       if (show_next_piece)
       {
              memcpy(left[10] + WIDTH - 10, "        ", 8);
              memcpy(left[11] + WIDTH - 10, "        ", 8);
       }
}

// Finalizacion del juego, cuando llega al borde superior todas las piezas
int gameOver()
{
       // Imprime el mensaje de juego terminado
       nodelay(stdscr, FALSE);

       end = 1;
       memcpy(center[13], "JUEGO TERMINADO !\0"
                          "                 \0",
              WIDTH * 5);
       memcpy(center[16], "    : SALIR    : REINICIAR   \0"
                          "                             \0",
              WIDTH * 2);
       center[16][3] = toupper(KEY_EXIT);
       center[16][13] = toupper(KEY_RESET);
       clear();
       printw("\n");
       for (int i = 2; i < HEIGHT; ++i)
       {
              printw("%s", left[i]);
              printw("%s", center[i]);
              printw("%s\n", right[i]);
       }
       refresh();
       return 1;
}

// Revisa si una fila esta completa, esta debe borrarse y bajar los siguientes
void checkClearPieces()
{
       // Verifica si la linea puede ser borrada y agrega puntaje
       int cleared = 0;
       if (fixedPoint[0] > 2)
       {
              for (int i = -2; i < 2; ++i)
              {
                     if (!strncmp(center[fixedPoint[0] + i] + 3, "][][][][][][][][][", 18))
                     {
                            ++cleared;
                            for (int j = fixedPoint[0] + i; j > 0; --j)
                                   memcpy(center[j] + 2, center[j - 1] + 2, 20);
                     }
              }
              if (cleared)
              {
                     dropped = 0;
                     updateScreen();
              }
       }
       clrLines += cleared;
}
