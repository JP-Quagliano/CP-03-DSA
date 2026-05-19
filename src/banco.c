#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "utils.h"

static void salvarContasPadrao(void) {
    FILE *arquivo = fopen(CAMINHO_CONTAS, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de contas. Verifique a pasta data.\n");
        return;
    }

    fprintf(arquivo, "1001;Joao Silva;1234;1500.00\n");
    fprintf(arquivo, "1002;Maria Souza;4321;2200.50\n");
    fprintf(arquivo, "1003;Carlos Lima;1111;850.75\n");
    fprintf(arquivo, "1004;Ana Pereira;2222;3000.00\n");

    fclose(arquivo);
}

void criarContasPadraoSeNecessario(void) {
    FILE *arquivo = fopen(CAMINHO_CONTAS, "r");

    if (arquivo == NULL) {
        salvarContasPadrao();
        return;
    }

    fclose(arquivo);
}

int carregarContas(Conta contas[], int limite) {
    FILE *arquivo = fopen(CAMINHO_CONTAS, "r");
    char linha[250];
    int quantidade = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de contas.\n");
        return 0;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL && quantidade < limite) {
        removerQuebraLinha(linha);

        char *numero = strtok(linha, ";");
        char *nome = strtok(NULL, ";");
        char *senha = strtok(NULL, ";");
        char *saldo = strtok(NULL, ";");

        if (numero != NULL && nome != NULL && senha != NULL && saldo != NULL) {
            contas[quantidade].numero = atoi(numero);
            strncpy(contas[quantidade].nome, nome, TAM_NOME - 1);
            contas[quantidade].nome[TAM_NOME - 1] = '\0';
            strncpy(contas[quantidade].senha, senha, TAM_SENHA - 1);
            contas[quantidade].senha[TAM_SENHA - 1] = '\0';
            contas[quantidade].saldo = atof(saldo);
            quantidade++;
        }
    }

    fclose(arquivo);
    return quantidade;
}

int salvarContas(Conta contas[], int quantidade) {
    FILE *arquivo = fopen(CAMINHO_CONTAS, "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar contas. Verifique o arquivo %s.\n", CAMINHO_CONTAS);
        return 0;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d;%s;%s;%.2f\n",
                contas[i].numero,
                contas[i].nome,
                contas[i].senha,
                contas[i].saldo);
    }

    fclose(arquivo);
    return 1;
}

int buscarContaPorNumero(Conta contas[], int quantidade, int numero) {
    for (int i = 0; i < quantidade; i++) {
        if (contas[i].numero == numero) {
            return i;
        }
    }
    return -1;
}

int autenticarConta(Conta contas[], int quantidade, int numero, const char senha[]) {
    int indice = buscarContaPorNumero(contas, quantidade, numero);

    if (indice == -1) {
        return -1;
    }

    if (strcmp(contas[indice].senha, senha) == 0) {
        return indice;
    }

    return -1;
}

void exibirResumoConta(const Conta *conta) {
    printf("Conta: %d\n", conta->numero);
    printf("Titular: %s\n", conta->nome);
}
