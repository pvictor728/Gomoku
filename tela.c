#include<stdio.h>
#include<stdlib.h>

//Limpa o buffer
void limparbuffer(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

//menu inicial
int menu_inicial(){
	int opc; 

	do{
		printf("\t\tEscolha entre as duas opções:\n");
		printf("\t\t>> 1 - Jogo Novo\n");
		printf("\t\t>> 2 - Carregar jogo\n");
		scanf("%d", &opc);
		limparbuffer();
	}while(opc != 1 && opc != 2);

	return opc;
}

//reservar o espaçonamemoria para a matriz
char ** aloca_matriz(int n){
	char **matriz;
	int i;
	matriz = (char **) malloc(n * sizeof(char *));

	for (i = 0; i < n; i++){
 
 		matriz[i] = (char *) malloc(n * sizeof(char));	
	}
	return matriz;
}



//preenchendo a matriz(partes substituiveis do tabuleiro) com '-'
void traco_matriz(char ** matriz, int n){
	int i, j;

	for(i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			matriz[i][j] = '-';
		}
	}

}



//alocando o vetor responsavel pelas divisorias do tabuleiro
char * aloca_vetor(int n){
	char *p;
	p = (char *) malloc(n * sizeof(char *));
	return p;
}



//definindo o tamanho do goban
int tamanho_tela(){
	int n;

	printf("Tamanho do Goban (4 < n < 20): ");
	scanf("%d",&n);
	while(n <= 4 || n >= 20){

		printf("Erro quanto ao tamanho do Goban.\n");

		printf("Tamanho do Goban (4 < n < 20): ");
		scanf("%d",&n);
	}

	return n;
}



//printando o goban
void chama_tela(int n, char **matriz, char *p){
	int i, col, l;
	
	printf("\t");
	for(i = 0; i < n; i++){
		printf("%-2d  ", i);
	}
	
	printf("\n");

	for(i = 0; i < n; i++){
		
		printf("\t");
		
		for(col = 0; col < n; col++){
			
			if(col <= n-2){
				printf("%c---",matriz[i][col]);
			}
			else if(col == n-1){
				printf("%c  %d",matriz[i][col],i);
			}
		}

		printf("\n\t");

		for(l = 0; l < n; l++){
			
			p[l]='|';
			
			if(i <= n-2){
				printf("%c   ",p[l]);
			}
			else if(i == n-1){
				break;
			}
		}

		printf("\n");
	}

	
}
