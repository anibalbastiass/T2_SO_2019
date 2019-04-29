/*
 *  Tarea 2 - Sistemas Operativos
 *  1 Semestre, 2019
 * 
 *  Autor:      Anibal Bastias Soto
 *  ROL:        2604215-1
 *  Carrera:    Ingenieria de Ejecucion en Informatica
 * 
 *  Archivo:    Tarea2-Tetris-Child-Rotate-Piece.c 
 *  
 *  Archivo que define la rotacion de la pieza en juego redibujando 
 *  sus caracteristicas en sentido horario, definiendo los bordes
 *  y que estos no sobrepasen, seguido con los caracteres <!, !> 
 *  y cuando llega al final con =
 * 
 */

#include "include/Tarea2-Tetris-Settings.h"

void rotatePiece()
{
       //pChild2 = fork();

       if (pipe(fd2) == -1)
       {
              fprintf(stderr, "Pipe Failed");
              exit(0);
       }

       close(fd2[PIPE_READ]); // no se usara para leer
       //write(fd1[PIPE_WRITE], piece, strlen(piece) + 1);
       close(fd2[PIPE_WRITE]); //ya no se usar ́a para escribir

       // Rota la pieza que se juega en sentido horario
       // verificando por pieza
       switch (piece)
       {
       case 'I':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1]] == '=' || center[fixedPoint[0] - 1][fixedPoint[1]] == '[' || center[fixedPoint[0] - 2][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 2] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     pieceI[0] + fixedPoint[1] - 4, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              piece = 'i';
              return;
       case 'i':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '|' || center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<')
                     return;
              memcpy(center[fixedPoint[0] - 2] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     pieceI[1] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[1] + 12, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              piece = 'I';
              return;
       case 'J':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1]] == '=' || center[fixedPoint[0] - 1][fixedPoint[1]] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceO[0] + 8, 6);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              piece = 'K';
              return;
       case 'K':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              piece = 'j';
              return;
       case 'j':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] - 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 6);
              piece = 'k';
              return;
       case 'k':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '|' || center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 4);
              piece = 'J';
              return;
       case 'L':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1]] == '=' || center[fixedPoint[0] - 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceO[0] + 10, 4);
              piece = 'M';
              return;
       case 'M':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 6);
              piece = 'l';
              return;
       case 'l':
              if (center[fixedPoint[0] - 1][fixedPoint[1]] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 4);
              piece = 'm';
              return;
       case 'm':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '|' || center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceT[0] + 6, 6);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              piece = 'L';
              return;
       case 'S':
              if (center[fixedPoint[0] - 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 6, 6);
              piece = 's';
              return;
       case 's':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '<' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 6);
              piece = 'S';
              return;
       case 'T':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1]] == '=')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              piece = 'U';
              return;
       case 'U':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              piece = 't';
              return;
       case 't':
              if (center[fixedPoint[0] - 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              piece = 'u';
              return;
       case 'u':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '|')
                     return;
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              piece = 'T';
              return;
       case 'Z':
              if (center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceO[0] + 8, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              piece = 'z';
              return;
       case 'z':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              piece = 'Z';
              return;
       }
}