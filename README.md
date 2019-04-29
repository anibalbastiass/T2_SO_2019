# Tarea 2 - Sistemas Operativos

``` 
1 Semestre 2019
Autor:      Anibal Bastias Soto
ROL:        2604215-1
Carrera:    Ingenieria de Ejecucion en Informatica
```

### Introduccion

En esta tarea se solicita construir el juego Tetris con las reglas generales del juego. El objetivo
es implementar procesos mediante pipes y memoria compartida de forma circular para aplicar los 
conocimientos de la asignatura. En este caso, se aplico el siguiente diagrama:

                    pipe1                      pipe2 (nextPiece)
   Proceso Padre ---------->  Proceso Hijo 1 -------------------> Proceso Hijo 2
        |                                                                |
        |   ShMem(Piece)                       pipe3 (nextRotPiece)      |
        --------------------- Proceso Hijo 3 <----------------------------

Por lo tanto:

- P0:   Proceso Padre: Encargado del juego donde recibe la pieza mediante memoria compartida
        del proceso hijo P3 en el pipe fd1

- P1:   Proceso Hijo 1: Encargado de elegir la siguiente pieza y enviarla al proceso P2
        por el pipe fd1

- P2:   Proceso Hijo 2: Recibe la pieza por el pipe fd1, rota la pieza y la envia al proceso
        P3 mediante Pipe fd1

- P3:   Proceso Hijo 3: Recibe la pieza rotada y la envia al pipe fd1 en memoria compartida
        al proceso padre P0 y sigue el flujo circular en el While

## Librerias requeridas

Esta tarea se requiere la libreria nCurses para compilarla correctamente, se puede instalar
en Ubuntu mediante los comandos:

sudo apt-get install libncurses5-dev
sudo apt-get install libncurses5-dev libncursesw5-dev


### Estructura del Proyecto

El proyecto consta de 2 carpetas:

- src: Directorio que contiene los archivos .c (Variables y funciones en ingles, comentarios en espanol)
- src/include: Directorio donde contiene los archivos .h (Cabeceras para definir variables y funciones)
- obj: Directorio donde se generan los objetos despues de compilar
- Makefile: Archivo base para compilar mediante GCC la aplicacion programada en lenguaje C
- README.md: Archivo que explica con detalle el desarrollo de la tarea

Despues de compilar, se generará la carpeta "Cartas" donde contendra las cartas ordenadas.

### Modo de compilacion
El compilador GCC de Unix genera archivos object en la carpeta obj (.o) y el ejecutable para usar
la aplicacion. En el Makefile se definieron las siguientes reglas:

- make clean (Limpia el ejecutable, .o y directorio de Cartas generadas)
- make (Compila la aplicacion y genera objetos y ejecutable)

Se recomienda ejecutar estos 2 scripts para modo de pruebas

### Modo de ejecucion

- Para iniciar la aplicacion, simplemente escribir:

* ./Tarea2-2604215-1

*by @anibalbastiass*

PD: Si desea ver este README con estilos, puede acceder a un lector Markdown Online :)