#ifndef EXTRATO_H
#define EXTRATO_H

#include "modelos.h"

void registrarExtrato(const Conta *conta, const char tipo[], double valor, const char descricao[]);
void exibirExtrato(const Conta *conta);

#endif
