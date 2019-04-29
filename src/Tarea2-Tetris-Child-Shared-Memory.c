/*
 *  Tarea 2 - Sistemas Operativos
 *  1 Semestre, 2019
 * 
 *  Autor:      Anibal Bastias Soto
 *  ROL:        2604215-1
 *  Carrera:    Ingenieria de Ejecucion en Informatica
 * 
 *  Archivo:    Tarea2-Tetris-Child-Shared-Memory.c 
 *  
 *  Archivo donde se define la memoria compartida del programa uniendo el proceso
 *  pChild3 con el proceso padre y entregando la pieza por pipe en memoria compartida
 */

#include "include/Tarea2-Tetris-Settings.h"

void *createSharedMemory(size_t size)
{
       // Memoria buffer sera leible y escrible
       int protection = PROT_READ | PROT_WRITE;

       // El buffer sera compartido, pero anonimamente, entonces solo este proceso y sus
       // hijos seran capaces de usarlo
       int visibility = MAP_ANONYMOUS | MAP_SHARED;

       // Lo parametros restantes a mmap() no son importantes en este caso
       return mmap(NULL, size, protection, visibility, 0, 0);
}

// Funcion que inicia la nueva pieza
void initPiece()
{
       //pChild3 = fork();

       if (pipe(fd3) == -1)
       {
              fprintf(stderr, "Pipe Failed");
              exit(0);
       }

       close(fd3[PIPE_READ]); // no se usara para leer
       //write(fd3[PIPE_WRITE], piece, strlen(piece) + 1);
       close(fd3[PIPE_WRITE]); //ya no se usar ́a para escribir

       // Crea memoria compartida
       createSharedMemory(128);

       // Revisa si cumple la condicion de borrar la linea completa de la fila
       // y borrarla, para marcar puntaje y seguir con la siguiente pieza
       checkClearPieces();

       int current;
       current = next;

       // Escoje aleatoriamente una de las 7 piezas siguientes (modulo 7)
       next = rand() % 7;

       switch (current)
       {
       case 0:
              memcpy(center[0], pieceI[0], WIDTH * 2);
              fixedPoint[0] = 1;
              fixedPoint[1] = 12;
              piece = 'I';
              return;
       case 1:
              memcpy(center[0], pieceJ[0], WIDTH * 2);
              fixedPoint[0] = 1;
              fixedPoint[1] = 10;
              piece = 'J';
              return;
       case 2:
              memcpy(center[0], pieceL[0], WIDTH * 2);
              fixedPoint[0] = 1;
              fixedPoint[1] = 10;
              piece = 'L';
              return;
       case 3:
              memcpy(center[0], pieceO[0], WIDTH * 2);
              fixedPoint[0] = 1;
              fixedPoint[1] = 10;
              piece = 'O';
              return;
       case 4:
              memcpy(center[0], pieceS[0], WIDTH * 2);
              fixedPoint[0] = 0;
              fixedPoint[1] = 10;
              piece = 'S';
              return;
       case 5:
              memcpy(center[0], pieceT[0], WIDTH * 2);
              fixedPoint[0] = 1;
              fixedPoint[1] = 10;
              piece = 'T';
              return;
       case 6:
              memcpy(center[0], pieceZ[0], WIDTH * 2);
              fixedPoint[0] = 0;
              fixedPoint[1] = 10;
              piece = 'Z';
              return;
       }
}