#!/bin/bash

rm -f *.o
gcc -Wall -c jogadores.c 
gcc -Wall -c tela.c
gcc -Wall -c rodadas.c
gcc -Wall -c armazenamento.c
gcc -Wall gomoku.c jogadores.o tela.o rodadas.o armazenamento.o -o test.o

./test.o