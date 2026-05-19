#ifndef OPERACOES_H
#define OPERACOES_H

#include "modelos.h"

void consultarSaldo(const Conta *conta);
void realizarDeposito(Conta contas[], int quantidade, int indiceConta);
void realizarSaque(Conta contas[], int quantidade, int indiceConta);
void realizarTransferencia(Conta contas[], int quantidade, int indiceOrigem);
void alterarSenha(Conta contas[], int quantidade, int indiceConta);

#endif
