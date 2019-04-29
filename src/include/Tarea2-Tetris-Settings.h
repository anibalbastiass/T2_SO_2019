/*
 *  Tarea 2 - Sistemas Operativos
 *  1 Semestre, 2019
 * 
 *  Autor:      Anibal Bastias Soto
 *  ROL:        2604215-1
 *  Carrera:    Ingenieria de Ejecucion en Informatica
 * 
 *  Archivo:    Tarea2-Tetris-Settings.h 
 * 
 *  Interfaz principal del programara para definir constantes, variables globales y metodos
 *  utilizados en todos los archivos *.c     
 * 
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

// Intervalo de tiempo para bajada de pieza
#define DROPINTERVAL (DELAY / 1000) * ((300 - level * 13) / 5)

// Retardo entre 2 comandos, segun el procesador
#define DELAY 7777
#define MAXLEVEL 9

// Numero de lineas para que ascienda de nivel
#define LINESFORLVLUP 10

// Valores fijos
#define WIDTH 25
#define HEIGHT 24
#define TOPLSITMAXLINELENGTH 34

#define SIZE_PIECE 2

// Teclas para acciones
#define KEY_BIND_MOVE_LEFT 'a'
#define KEY_BIND_MOVE_RIGHT 'd'
#define KEY_BIND_ROTATE 'w'
#define KEY_BIND_DROP 's'
#define KEY_BIND_RESET 'l'
#define KEY_BIND_EXIT 'k'

#define BUFF_SIZE 25
#define SHARED_MEMORY_SIZE 128
#define PIPE_READ 0
#define PIPE_WRITE 1

// Procesos hijos
int status;
pid_t pChild1, pChild2, pChild3;

// Variable para Pipes y Memoria compartida
// fd[0]; -> Para leer pipe
// fd[1]; -> Para escribir pipe
int fd1[2];
int fd2[2];
int fd3[2];
int fd4[2];

// Variables estaticas todos para los archivos .c

// Todas las piezas de Tetris: pieces (4 bloques)
char pieceI[SIZE_PIECE][WIDTH];
char pieceS[SIZE_PIECE][WIDTH];
char pieceL[SIZE_PIECE][WIDTH];
char pieceO[SIZE_PIECE][WIDTH];
char pieceZ[SIZE_PIECE][WIDTH];
char pieceT[SIZE_PIECE][WIDTH];
char pieceJ[SIZE_PIECE][WIDTH];

// Inicializacion de variables
char piece;

//set flags to default values
int level;
int showText;
int next;
int show_next_piece;
int end;
int clrLines;
int startLevel;
int dropped;
int fixedPoint[2];

//screen is divided into three sections - left, right and center
char left[HEIGHT][WIDTH];
char center[HEIGHT][WIDTH];
char right[HEIGHT][WIDTH];

struct timeval t1, t2;

// Funciones de juego Tetris
void initPiece();
void showNextPiece();
void rotatePiece();
void setKeybind();
void updateScreen();

int game();
void moveLeft();
void moveRight();
int moveDown();

void init();
int gameOver();

void checkClearPieces();
void updateLevel();

// Shared Memory
void *createSharedMemory(size_t size);
int createPipe();