#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogadores.h"
#include "tela.h"




void lista_de_jogos_salvos(char nome_arquivo[]){
	FILE *lista_salvos;

	lista_salvos = fopen("lista_salvos.txt", "a");

	fprintf(lista_salvos, "%s\n", nome_arquivo);

	fclose(lista_salvos);
}





//funçao para salvar dados do jogo
void salvando_jogo(char **matriz, int n, jogador gamer1, jogador gamer2){
	
	char nome_arquivo[50];


	printf("Informe o nome com que deseja salvar o jogo: \n");
	scanf("%s", nome_arquivo);
	lista_de_jogos_salvos(nome_arquivo);
	strcat(nome_arquivo, ".txt");

	FILE *arquivo = fopen(nome_arquivo, "w");

	//Jogador 1
	fprintf(arquivo, "%s\n%d\n", gamer1.nome, *(gamer1).vitoria);

	//Jogador 2
	fprintf(arquivo, "%s\n%d\n", gamer2.nome, *(gamer2).vitoria);

	fclose(arquivo);


	printf("Jogo salvo com sucesso.\n");
}







int abrindo_jogo_salvo(jogador gamer1, jogador gamer2){
	char nome_arquivo[50], pegue_nome[50];
	int opc;
	FILE *lista_salvos;

	if(fopen("lista_salvos.txt", "r") != NULL){

		lista_salvos = fopen("lista_salvos.txt", "r");

		printf("\n\n");

		while(fgets(nome_arquivo, 50, lista_salvos) != NULL){
			printf("%s\n", nome_arquivo);
		}
		fclose(lista_salvos);
	


		printf("Informe o nome do arquivo a ser aberto: \n");
		scanf("%s", nome_arquivo);
		strcat(nome_arquivo, ".txt");



		FILE *arquivo2 = fopen(nome_arquivo, "r");

		do{
			if(arquivo2 == NULL){
				printf("Arquivo nao encontrado.\n");
				printf("Informe o nome do arquivo a ser aberto: \n");
				scanf("%s", nome_arquivo);
				strcat(nome_arquivo, ".txt");

				arquivo2 = fopen(nome_arquivo, "r");
			}
		}while(arquivo2 == NULL);
		
		fscanf(arquivo2, "%s", pegue_nome);
		
		
		strcpy(gamer1.nome, pegue_nome);
		
		fscanf(arquivo2, "%s", pegue_nome);
		strcpy(gamer2.nome, pegue_nome);
		
		fclose(arquivo2);

		return 2;
	}
	else{
		printf("Nao ha jogo salvo.\n\n");
		opc = menu_inicial();
		if(opc == 1){
			return 1;
		}
		else if(opc == 2){
			abrindo_jogo_salvo( gamer1, gamer2);
		}
	}
	return 1;
}