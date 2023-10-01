#ifndef RODADAS_H
#define RODADAS_H

// verificando a validade das rodadas de acordo com a segunda regra do ninuki
int verifique_validade_jogada(int n, char **matriz, int i, int j);

//analisa validade da jogada e substitui na matriz
void atualiza_jogo(char **matriz, int n, jogador gamer);

//analisa depois de uma rodada se houve algum vencedor ou se houve caso de empate
int verifique_vitoria(int n, char **matriz, jogador gamer);

//Implementa a a captura de peças a partir da primeira regra do jogo
int captura_peca(int n, char **matriz, jogador gamer);

//alterna jogadas e printa o goban
void alternar_jogadas(int n, char **matriz, char *p, jogador j1, jogador j2);

//Exibe ao usuario a opção de continuar o jogo após uma partida realizada
int deseja_continuar(char opc_continue[]);


#endif