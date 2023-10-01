#ifndef TELA_H
#define TELA_H

//Limpa o buffer
void limparbuffer();

//menu inicial
int menu_inicial();

//reservar o espaçonamemoria para a matriz
char ** aloca_matriz(int n);

//preenchendo a matriz(partes substituiveis do tabuleiro) com '-'
void traco_matriz(char ** matriz, int n);

//alocando o vetor responsavel pelas divisorias do tabuleiro
char * aloca_vetor(int n);

//definindo o tamanho do goban
int tamanho_tela();

//printando o goban
void chama_tela(int n, char **matriz, char *p);

#endif