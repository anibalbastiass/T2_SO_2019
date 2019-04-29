#
#  Tarea 2 - Sistemas Operativos
#  1 Semestre, 2019
# 
#  Autor: 	Anibal Bastias Soto
#  ROL: 	2604215-1
#  Carrera: Ingenieria de Ejecucion en Informatica
# 
#  Archivo: Makefile
#  
#  Este archivo construye la aplicacion leyendo las carpetas src, src/include
#  encontrando archivos .c y .h para luego generar objetos en la carpeta obj/
#  y el ejecutable en la ruta principal con el compilador GCC
#
#  Nota: Se necesita la libreria lncurses para compilar de manera adecuada
#  esta aplicacion (Comando instalacion Linux): sudo apt-get install libncurses5-dev
# 

TARGET = Tarea2-2604215-1
CC = gcc
CFLAGS = -g -Wall
ODIR = obj
HDIR = include
SDIR = src
LIBS = -lncurses

.CLEARALL: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(wildcard $(SDIR)/*.c))
HEADERS = $(wildcard $(SDIR)/$(HDIR)/*.h)

$(ODIR)/%.o: $(SDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(ODIR)/*.o
	-rm -f $(TARGET)