#ifndef ARMAZENAMENTO_H
#define ARMAZENAMENTO_H

void lista_de_jogos_salvos(char nome_arquivo[]);

//funçao para salvar dados do jogo
void salvando_jogo(char **matriz, int n, jogador gamer1, jogador gamer2);

int abrindo_jogo_salvo(jogador gamer1, jogador gamer2);

#endif