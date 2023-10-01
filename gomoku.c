#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "jogadores.h"
#include "tela.h"
#include "rodadas.h"
#include "armazenamento.h"


int main(){

	//variaveis
	int n, continua = 0, i, opcao2;
	char **matriz, *p, opc_continue[] = "sim", salv[3];
	cores color;
	jogador j1, j2;
	int opc;


	//zerando vitorias / começando um novo jogo
	j1.vitoria = 0;
	j2.vitoria = 0;

	//alocaçao dos nomes dos jogadores
	j1.nome = (char *)malloc(50 * sizeof(char));
	j2.nome = (char *)malloc(50 * sizeof(char));
	
	opc = menu_inicial();

	if(opc == 2){
		opc = abrindo_jogo_salvo(j1, j2);
	}

	if(opc == 1){
		unsigned long len = 0;

		// pedindo nome dos usuarios
		printf("Nome do jogador 1: \n"); 
		getline(&j1.nome, &len, stdin);
		j1.nome[strlen(j1.nome) - 1] = 0;
		j1 = inicializa_jogador(j1.nome, 0);

		printf("Nome do jogador 2: \n"); 
		getline(&j2.nome, &len, stdin);
		j2.nome[strlen(j2.nome) - 1] = 0;
		j2 = inicializa_jogador(j2.nome, 0);
	}



	//alocaçao das coordenadas de movimentos dos jogadores
	j1.move = (coordenadas *) malloc(sizeof(coordenadas));
	j2.move = (coordenadas *) malloc(sizeof(coordenadas));

	//alocaçao de espaço para as vitorias
	j1.vitoria = (int *) malloc(sizeof(int));
	j2.vitoria = (int *) malloc(sizeof(int));
	
	
	
	do{
		
		//resetar as cores e capturas
		j2.cor = 0;
		j1.cor = 0;

		//zerando capturas
		j1.captura = 0;
		j2.captura = 0;
		
		

		//definindo as cores
		srand((unsigned) time(NULL));

		color = rand() % 2;

		if(color == 0){
			j2.cor = 1;
		}
		else if(color == 1){
			j1.cor = 1;
		}
		


	

		//define o tamanho do goban
		n = tamanho_tela();
	
		//alocaçoes do tabuleiro
		matriz = aloca_matriz(n);
		traco_matriz(matriz, n);
		p = aloca_vetor(n);


		//printa tela
		chama_tela(n, matriz, p);

		//rodadas alternadas
		alternar_jogadas(n, matriz, p, j1, j2);
		continua = deseja_continuar(opc_continue);
		
		


	}while(continua == 0);




	if(continua > 0){
		printf("Deseja salvar as informacoes do jogo? sim/nao\n");
		scanf("%s", salv);
		for(i = 0; i < 3; i++){
			salv[i] = tolower(salv[i]);
		}
		opcao2 = strcmp(salv, opc_continue);
		if(opcao2 == 0){
			salvando_jogo(matriz, n, j1, j2);
		}
	}

	
	return 0;
}


	
	
	