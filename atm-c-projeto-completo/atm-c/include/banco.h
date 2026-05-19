#ifndef BANCO_H
#define BANCO_H

#include "modelos.h"

int carregarContas(Conta contas[], int limite);
int salvarContas(Conta contas[], int quantidade);
int buscarContaPorNumero(Conta contas[], int quantidade, int numero);
int autenticarConta(Conta contas[], int quantidade, int numero, const char senha[]);
void criarContasPadraoSeNecessario(void);
void exibirResumoConta(const Conta *conta);

#endif
