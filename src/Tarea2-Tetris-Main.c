/*
 *  Tarea 2 - Sistemas Operativos
 *  1 Semestre, 2019
 * 
 *  Autor:      Anibal Bastias Soto
 *  ROL:        2604215-1
 *  Carrera:    Ingenieria de Ejecucion en Informatica
 * 
 *  Archivo:    Tarea2-Tetris-Main.c 
 *  
 *  Archivo donde se define los valores de las variables globales,
 *  inicializacion del programa y la asignacion del nivel para jugar
 *
 */

#include "include/Tarea2-Tetris-Settings.h"

// Todas piezas las de Tetris: pieces (4 bloques)
char pieceI[SIZE_PIECE][WIDTH] = {"<! . . . . . . . . . .!>",
                                  "<! . . .[][][][] . . .!>"};

char pieceJ[SIZE_PIECE][WIDTH] = {"<! . . .[] . . . . . .!>",
                                  "<! . . .[][][] . . . .!>"};

char pieceL[SIZE_PIECE][WIDTH] = {"<! . . . . .[] . . . .!>",
                                  "<! . . .[][][] . . . .!>"};

char pieceO[SIZE_PIECE][WIDTH] = {"<! . . . .[][] . . . .!>",
                                  "<! . . . .[][] . . . .!>"};

char pieceS[SIZE_PIECE][WIDTH] = {"<! . . . .[][] . . . .!>",
                                  "<! . . .[][] . . . . .!>"};

char pieceT[SIZE_PIECE][WIDTH] = {"<! . . . .[] . . . . .!>",
                                  "<! . . .[][][] . . . .!>"};

char pieceZ[SIZE_PIECE][WIDTH] = {"<! . . .[][] . . . . .!>",
                                  "<! . . . .[][] . . . .!>"};

// Inicializacion de variables
int showText = 1;
int show_next_piece = 1;
int clrLines = 0;
int dropped = 0;
int fixedPoint[2] = {0};

// La pantalla es dividida en 3 secciones: izquierda, centro y derecha
char left[HEIGHT][WIDTH] = {{0}};
char center[HEIGHT][WIDTH] = {{0}};
char right[HEIGHT][WIDTH] = {{0}};

int main(int argc, char *argv[])
{
  // Setea el timer en el proceso padre
  srand(time(NULL));

  // Inicializa la pantalla mediante ncurses
  initscr();
  cbreak();

  // Pregunta que nivel se va a jugar
  do
  {
    clear();
    printw("\n\n\n       Ingresa el nivel de Tetris (1-%d): ", MAXLEVEL);
    refresh();
    scanw("%d ", &startLevel);
  } while (startLevel < 1 || startLevel > MAXLEVEL);

  clear();

  refresh();

  noecho();
  curs_set(0);

  // Setea la siguiente pieza e inicializa el juego
  next = rand() % 7;
  while (!game())
    ;

  endwin();

  return 0;
}
