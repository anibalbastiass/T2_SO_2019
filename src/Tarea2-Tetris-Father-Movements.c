/*
 *  Tarea 2 - Sistemas Operativos
 *  1 Semestre, 2019
 * 
 *  Autor:      Anibal Bastias Soto
 *  ROL:        2604215-1
 *  Carrera:    Ingenieria de Ejecucion en Informatica
 * 
 *  Archivo:    Tarea2-Tetris-Father-Movements.c 
 *  
 *  Archivo donde indica los movimientos de las piezas y como se dibuja
 *  para cada caso y chequeando si sobrepasa los limites del juego
 * 
 */

#include "include/Tarea2-Tetris-Settings.h"

// Muestra por pantalla las teclas permitidas para la interaccion
// del juego
void setKeybind()
{
       // Lee teclas desde la configuracion
       right[3][3] = toupper(KEY_BIND_MOVE_LEFT);
       right[3][14] = toupper(KEY_BIND_MOVE_RIGHT);
       right[4][8] = toupper(KEY_BIND_ROTATE);
       right[5][3] = toupper(KEY_BIND_DROP);
       right[5][14] = toupper(KEY_BIND_RESET);
       right[8][3] = toupper(KEY_BIND_EXIT);
}

// Mueve la actual pieza a la izquierda
void moveLeft()
{
       switch (piece)
       {
       case 'I':
              if (center[fixedPoint[0]][fixedPoint[1] + -6] == '[' || center[fixedPoint[0]][fixedPoint[1] - 6] == '<')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 6,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              fixedPoint[1] -= 2;
              return;
       case 'i':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '<')
                     return;
              for (int i = -2; i < 2; ++i)
              {
                     if (center[fixedPoint[0] + i][fixedPoint[1] - 2] == '[')
                            return;
              }
              for (int i = -2; i < 2; ++i)
              {
                     memcpy(center[fixedPoint[0] + i] + fixedPoint[1] - 2,
                            pieceT[0] + 10, 4);
              }
              fixedPoint[1] -= 2;
              return;
       case 'J':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 4] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              fixedPoint[1] -= 2;
              return;
       case 'K':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       case 'j':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] + 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       case 'k':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 4] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              fixedPoint[1] -= 2;
              return;
       case 'L':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] - 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              fixedPoint[1] -= 2;
              return;
       case 'M':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 2);
              fixedPoint[1] -= 2;
              return;
       case 'l':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] + 1][fixedPoint[1] - 4] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 4,
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       case 'm':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] - 4] == '[')
                     return;
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              fixedPoint[1] -= 2;
              return;
       case 'O':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0] - 1] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              fixedPoint[1] -= 2;
              return;
       case 'S':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 4] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 4] == '<')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 4,
                     center[fixedPoint[0] + 1] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              fixedPoint[1] -= 2;
              return;
       case 's':
              if (center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '<' || center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       case 'T':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              fixedPoint[1] -= 2;
              return;
       case 'U':
              if (center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       case 't':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     pieceT[0] + 10, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       case 'u':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] - 1][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     pieceO[0] + 10, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       case 'Z':
              if (center[fixedPoint[0]][fixedPoint[1] - 4] == '[' || center[fixedPoint[0]][fixedPoint[1] - 4] == '<' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0] + 1] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              fixedPoint[1] -= 2;
              return;
       case 'z':
              if (center[fixedPoint[0] - 1][fixedPoint[1]] == '[' || center[fixedPoint[0]][fixedPoint[1] - 2] == '<' || center[fixedPoint[0]][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 4);
              fixedPoint[1] -= 2;
              return;
       }
}

// Mueve la actual pieza a la derecha
void moveRight()
{
       switch (piece)
       {
       case 'I':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 4,
                     pieceI[0] + fixedPoint[1] - 4, 2);
              fixedPoint[1] += 2;
              return;
       case 'i':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '|')
                     return;
              for (int i = -2; i < 2; ++i)
              {
                     if (center[fixedPoint[0] + i][fixedPoint[1] + 2] == '[')
                            return;
              }
              for (int i = -2; i < 2; ++i)
              {
                     memcpy(center[fixedPoint[0] + i] + fixedPoint[1],
                            pieceT[0] + 8, 4);
              }
              fixedPoint[1] += 2;
              return;
       case 'J':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] - 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              fixedPoint[1] += 2;
              return;
       case 'K':
              if (center[fixedPoint[0] - 1][fixedPoint[1] + 4] == '[' || center[fixedPoint[0] - 1][fixedPoint[1] + 4] == '|' || center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 'j':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] + 1][fixedPoint[1] + 4] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 'k':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '|' || center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1] + 2, 2);
              fixedPoint[1] += 2;
              return;
       case 'L':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] - 1][fixedPoint[1] + 4] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1] + 4, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              fixedPoint[1] += 2;
              return;
       case 'M':
              if (center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 4] == '|' || center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 4] == '[')
                     return;
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 'l':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] + 1][fixedPoint[1]] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 'm':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '|' || center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1] + 2, 2);
              fixedPoint[1] += 2;
              return;
       case 'O':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] - 1][fixedPoint[1] + 4] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 4,
                     center[fixedPoint[0] - 1] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              fixedPoint[1] += 2;
              return;
       case 'S':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0] + 1] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              fixedPoint[1] += 2;
              return;
       case 's':
              if (center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 4] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceO[0] + 8, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 'T':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              fixedPoint[1] += 2;
              return;
       case 'U':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceO[0] + 8, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 't':
              if (center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 4,
                     pieceT[0] + 10, 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 'u':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0]][fixedPoint[1] + 2] == '|' || center[fixedPoint[0] - 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceO[0] + 8, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       case 'Z':
              if (center[fixedPoint[0]][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 4] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 4] == '|')
                     return;
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 4,
                     center[fixedPoint[0] + 1] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              fixedPoint[1] += 2;
              return;
       case 'z':
              if (center[fixedPoint[0] - 1][fixedPoint[1] + 4] == '[' || center[fixedPoint[0]][fixedPoint[1] + 4] == '|' || center[fixedPoint[0]][fixedPoint[1] + 4] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     return;
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceO[0] + 8, 6);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              fixedPoint[1] += 2;
              return;
       }
}

// Mueve la actual pieza hacia abajo
int moveDown()
{
       switch (piece)
       {
       case 'I':
              if (center[fixedPoint[0] + 1][fixedPoint[1] - 4] == '=')
              {
                     initPiece();
                     return 0;
              }
              for (int i = 0; i < 4; ++i)
              {
                     if (center[fixedPoint[0] + 1][fixedPoint[1] - 4 + i * 2] == '[')
                     {
                            if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                                   return gameOver();
                            initPiece();
                            return 0;
                     }
              }
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 4,
                     center[fixedPoint[0]] + fixedPoint[1] - 4, 8);
              memcpy(center[fixedPoint[0]++] + fixedPoint[1] - 4,
                     pieceI[0] + fixedPoint[1] - 4, 8);
              return 0;
       case 'i':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]++ - 2] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              return 0;
       case 'J':
              if (center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '=')
              {
                     initPiece();
                     return 0;
              }
              for (int i = 0; i < 3; ++i)
              {
                     if (center[fixedPoint[0] + 1][fixedPoint[1] - 2 + i * 2] == '[')
                     {
                            if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                                   return gameOver();
                            initPiece();
                            return 0;
                     }
              }
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1] - 2, 6);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 4);
              memcpy(center[fixedPoint[0]++ - 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              return 0;
       case 'K':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0]][fixedPoint[1] + 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 4);
              memcpy(center[fixedPoint[0]++] + fixedPoint[1] + 2,
                     pieceT[0] + 10, 2);
              return 0;
       case 'j':
              if (center[fixedPoint[0] + 2][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 2][fixedPoint[1] + 2] == '=' || center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 6);
              memcpy(center[fixedPoint[0]++ + 1] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 4);
              return 0;
       case 'k':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0] + 2][fixedPoint[1] - 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1] - 2,
                     pieceO[0] + 10, 4);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]++ + 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              return 0;
       case 'L':
              if (center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '=')
              {
                     initPiece();
                     return 0;
              }
              for (int i = 0; i < 3; ++i)
              {
                     if (center[fixedPoint[0] + 1][fixedPoint[1] - 2 + i * 2] == '[')
                     {
                            if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                                   return gameOver();
                            initPiece();
                            return 0;
                     }
              }
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1] - 2, 6);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 4);
              memcpy(center[fixedPoint[0]++ - 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              return 0;
       case 'M':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0] + 2][fixedPoint[1] + 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     pieceO[0] + 10, 4);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]++ + 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              return 0;
       case 'l':
              if (center[fixedPoint[0] + 2][fixedPoint[1] - 2] == '[' || center[fixedPoint[0] + 2][fixedPoint[1] - 2] == '=' || center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 6);
              memcpy(center[fixedPoint[0]++ + 1] + fixedPoint[1],
                     pieceO[0] + 10, 4);
              return 0;
       case 'm':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0]][fixedPoint[1] - 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     pieceT[0] + 10, 2);
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 4);
              memcpy(center[fixedPoint[0]++] + fixedPoint[1] - 2,
                     pieceT[0] + 10, 2);
              return 0;
       case 'O':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '=')
              {
                     initPiece();
                     return 0;
              }
              for (int i = 0; i < 2; ++i)
              {
                     if (center[fixedPoint[0] + 1][fixedPoint[1] + i * 2] == '[')
                     {
                            if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                                   return gameOver();
                            initPiece();
                            return 0;
                     }
              }
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 4);
              memcpy(center[fixedPoint[0]++ - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 4);
              return 0;
       case 'S':
              if (center[fixedPoint[0] + 2][fixedPoint[1] - 2] == '=')
              {
                     initPiece();
                     return 0;
              }
              for (int i = 0; i < 2; ++i)
              {
                     if (center[fixedPoint[0] + 2][fixedPoint[1] - 2 + i * 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
                     {
                            if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                                   return gameOver();
                            initPiece();
                            return 0;
                     }
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1] - 2,
                     center[fixedPoint[0] + 1] + fixedPoint[1] - 2, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceS[0] + 8, 6);
              memcpy(center[fixedPoint[0]++] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 4);
              return 0;
       case 's':
              if (center[fixedPoint[0] + 1][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0] + 2][fixedPoint[1] + 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceT[0] + 10, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceO[0] + 10, 4);
              memcpy(center[fixedPoint[0]++ + 2] + fixedPoint[1] + 2,
                     pieceT[0] + 10, 2);
              return 0;
       case 'T':
              if (center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '=')
              {
                     initPiece();
                     return 0;
              }
              for (int i = 0; i < 3; ++i)
              {
                     if (center[fixedPoint[0] + 1][fixedPoint[1] - 2 + i * 2] == '[')
                     {
                            if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                                   return gameOver();
                            initPiece();
                            return 0;
                     }
              }
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1] - 2, 6);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceT[0] + 8, 6);
              memcpy(center[fixedPoint[0]++ - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              return 0;
       case 'U':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1] + 2, 2);
              memcpy(center[fixedPoint[0]++ - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              return 0;
       case 't':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] + 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]++] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 6);
              return 0;
       case 'u':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     center[fixedPoint[0]] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 2);
              memcpy(center[fixedPoint[0]++ - 1] + fixedPoint[1],
                     pieceI[0] + fixedPoint[1], 2);
              return 0;
       case 'Z':
              if (center[fixedPoint[0] + 2][fixedPoint[1]] == '=')
              {
                     initPiece();
                     return 0;
              }
              for (int i = 0; i < 2; ++i)
              {
                     if (center[fixedPoint[0] + 2][fixedPoint[1] + i * 2] == '[' || center[fixedPoint[0] + 1][fixedPoint[1] - 2] == '[')
                     {
                            if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                                   return gameOver();
                            initPiece();
                            return 0;
                     }
              }
              memcpy(center[fixedPoint[0] + 2] + fixedPoint[1],
                     center[fixedPoint[0] + 1] + fixedPoint[1], 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1] - 2,
                     pieceZ[0] + 8, 6);
              memcpy(center[fixedPoint[0]++] + fixedPoint[1] - 2,
                     pieceI[0] + fixedPoint[1] - 2, 4);
              return 0;
       case 'z':
              if (center[fixedPoint[0] + 1][fixedPoint[1] + 2] == '[' || center[fixedPoint[0] + 2][fixedPoint[1]] == '=' || center[fixedPoint[0] + 2][fixedPoint[1]] == '[')
              {
                     if (fixedPoint[0] == 1 || fixedPoint[0] == 2)
                            return gameOver();
                     initPiece();
                     return 0;
              }
              memcpy(center[fixedPoint[0] - 1] + fixedPoint[1] + 2,
                     pieceI[0] + fixedPoint[1], 2);
              memcpy(center[fixedPoint[0]] + fixedPoint[1],
                     pieceT[0] + 8, 4);
              memcpy(center[fixedPoint[0] + 1] + fixedPoint[1],
                     pieceO[0] + 10, 4);
              memcpy(center[fixedPoint[0]++ + 2] + fixedPoint[1],
                     pieceT[0] + 10, 2);
              return 0;
       }
       return 0;
}
