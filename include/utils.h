#ifndef UTILS_H
#define UTILS_H

void removerQuebraLinha(char texto[]);
void lerLinha(const char mensagem[], char destino[], int tamanho);
int lerInteiro(const char mensagem[], int minimo, int maximo);
double lerDouble(const char mensagem[], double minimo);
void pausar(void);
void exibirCabecalho(const char titulo[]);
int confirmarOperacao(const char mensagem[]);
void limparTela(void);
void removerEspacosLaterais(char texto[]);

#endif
