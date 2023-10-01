#include <stdio.h>
#include <stdlib.h>
#include "jogadores.h"

//inicializando jogadores
jogador inicializa_jogador(char *name, cores color){
	jogador gamer;

	gamer.nome = name;
	gamer.cor = color;

	return gamer;
}


