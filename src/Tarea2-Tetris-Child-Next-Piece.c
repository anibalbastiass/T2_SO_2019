/*
 *  Tarea 2 - Sistemas Operativos
 *  1 Semestre, 2019
 * 
 *  Autor:      Anibal Bastias Soto
 *  ROL:        2604215-1
 *  Carrera:    Ingenieria de Ejecucion en Informatica
 * 
 *  Archivo:    Tarea2-Tetris-Child-Next-Piece.c 
 *  
 *  Archivo que define funcion para retonar la siguiente pieza   
 *  del Tetris y definirlo en un proceso hijo pChild1
 */

#include "include/Tarea2-Tetris-Settings.h"

// Funcion donde muestra por pantalla la siguiente pieza segun
// el caso en switch case enumarado anteriormente
void showNextPiece()
{
       //pChild1 = fork();

       if (pipe(fd1) == -1)
       {
              fprintf(stderr, "Pipe Failed");
              exit(0);
       }

       close(fd1[PIPE_READ]); // no se usara para leer
       //write(fd1[PIPE_WRITE], next, strlen(next) + 1);
       close(fd1[PIPE_WRITE]); //ya no se usar ́a para escribir

       // En cada caso, copia en memoria la posicion izquierda de
       // la pantalla en vista segun la posicion y ancho de este
       switch (next)
       {
       case 0:
              memcpy(left[11] + WIDTH - 10, pieceI[1] + 8, 8);
              return;
       case 1:
              memcpy(left[10] + WIDTH - 8, pieceJ[0] + 8, 2);
              memcpy(left[11] + WIDTH - 8, pieceJ[1] + 8, 6);
              return;
       case 2:
              memcpy(left[10] + WIDTH - 4, pieceL[0] + 12, 2);
              memcpy(left[11] + WIDTH - 8, pieceL[1] + 8, 6);
              return;
       case 3:
              memcpy(left[10] + WIDTH - 6, pieceO[0] + 10, 4);
              memcpy(left[11] + WIDTH - 6, pieceO[1] + 10, 4);
              return;
       case 4:
              memcpy(left[10] + WIDTH - 6, pieceS[0] + 10, 4);
              memcpy(left[11] + WIDTH - 8, pieceS[1] + 8, 4);
              return;
       case 5:
              memcpy(left[10] + WIDTH - 6, pieceT[0] + 10, 2);
              memcpy(left[11] + WIDTH - 8, pieceT[1] + 8, 6);
              return;
       case 6:
              memcpy(left[10] + WIDTH - 8, pieceZ[0] + 8, 4);
              memcpy(left[11] + WIDTH - 6, pieceZ[1] + 10, 4);
              return;
       }
}
