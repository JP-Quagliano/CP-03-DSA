#ifndef MENU_H
#define MENU_H

#include "modelos.h"

void executarSistema(void);
int menuInicial(void);
int menuOperacoes(const Conta *conta);
int realizarLogin(Conta contas[], int quantidade);

#endif
