#ifndef JOGADORES_H
#define JOGADORES_H

//difinindo tipo coordenadas
typedef struct{
	int x, y;
}coordenadas;

//difinindo tipo jogador
typedef struct{
	char *nome;
	int cor;
	coordenadas *move;
	int *vitoria;
	int comp;
	int captura;
}jogador;

//difinindo tipo cores
typedef enum{
	white, black
}cores;

//inicializando jogadores
jogador inicializa_jogador(char *name, cores color);



#endif