# fichero Makefile
#
# Domingo Martin Perandres 2017

# nombre del fichero ejecutable
#
TARGETS= practica5

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=   -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS= -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
#LDFLAGS= -lstdc++ -lGLU -lGL -lglut -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 

OS := $(shell uname)
ifeq ($(OS),Darwin) #flags para MAC OS X
LDFLAGS= -framework GLUT -framework OpenGL -framework Cocoa 
else  #flags para linux
LDFLAGS=  -lGLU -lGL -lglut
endif
# definicion del compilador
#
CC = g++

# sufijos
.SUFFIXES: .cc .c .o

# Reglas
# $< -> todas las dependencias que han cambiado
# $@ -> el objetivo
# $^ -> todas las dependencias

# como pasar de .cc a .o

.cc.o:
	$(CC) $(CXXFLAGS) -c $<

# como pasar de .o a ejecutable (sin sufijo)

.o:
	$(CC) $(LDFLAGS) $^ -o $@

# orden que sera ejecutada por defecto
#

default : $(TARGETS)

# regla de dependencias
#
$(TARGETS) : practica5.o objetos.o file_ply_stl.o
	$(CC) -o $@ $(CXXFLAGS) practica5.o objetos.o file_ply_stl.o $(LDFLAGS)

read_ply.o: read_ply.cc file_ply_stl.cc

file_ply_stl.o: file_ply_stl.cc file_ply_stl.h vertex.h

# regla para limpiar
clean:
	rm -f *.o
	rm -f $(TARGETS)
