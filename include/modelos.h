#ifndef MODELOS_H
#define MODELOS_H

#define MAX_CONTAS 50
#define TAM_NOME 80
#define TAM_SENHA 30
#define CAMINHO_CONTAS "data/contas.txt"
#define PASTA_DADOS "data"

typedef struct {
    int numero;
    char nome[TAM_NOME];
    char senha[TAM_SENHA];
    double saldo;
} Conta;

#endif
