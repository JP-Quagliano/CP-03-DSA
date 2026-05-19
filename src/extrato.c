#include <stdio.h>
#include <time.h>
#include "extrato.h"
#include "utils.h"

static void montarCaminhoExtrato(int numeroConta, char caminho[], int tamanho) {
    snprintf(caminho, tamanho, "data/extrato_%d.txt", numeroConta);
}

void registrarExtrato(const Conta *conta, const char tipo[], double valor, const char descricao[]) {
    char caminho[120];
    montarCaminhoExtrato(conta->numero, caminho, sizeof(caminho));

    FILE *arquivo = fopen(caminho, "a");

    if (arquivo == NULL) {
        printf("Aviso: nao foi possivel registrar a operacao no extrato.\n");
        return;
    }

    time_t agora = time(NULL);
    struct tm *dataHora = localtime(&agora);

    if (dataHora != NULL) {
        fprintf(arquivo,
                "%02d/%02d/%04d %02d:%02d:%02d | %-15s | R$ %10.2f | Saldo: R$ %10.2f | %s\n",
                dataHora->tm_mday,
                dataHora->tm_mon + 1,
                dataHora->tm_year + 1900,
                dataHora->tm_hour,
                dataHora->tm_min,
                dataHora->tm_sec,
                tipo,
                valor,
                conta->saldo,
                descricao);
    } else {
        fprintf(arquivo,
                "Data indisponivel | %-15s | R$ %10.2f | Saldo: R$ %10.2f | %s\n",
                tipo,
                valor,
                conta->saldo,
                descricao);
    }

    fclose(arquivo);
}

void exibirExtrato(const Conta *conta) {
    char caminho[120];
    char linha[300];
    int encontrouRegistro = 0;

    montarCaminhoExtrato(conta->numero, caminho, sizeof(caminho));

    FILE *arquivo = fopen(caminho, "r");

    exibirCabecalho("EXTRATO DA CONTA");
    printf("Conta: %d\n", conta->numero);
    printf("Titular: %s\n\n", conta->nome);

    if (arquivo == NULL) {
        printf("Nenhuma movimentacao encontrada para esta conta.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
        encontrouRegistro = 1;
    }

    if (!encontrouRegistro) {
        printf("Nenhuma movimentacao encontrada para esta conta.\n");
    }

    fclose(arquivo);
}
