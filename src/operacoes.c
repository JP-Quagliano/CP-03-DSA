#include <stdio.h>
#include <string.h>
#include "operacoes.h"
#include "banco.h"
#include "extrato.h"
#include "utils.h"

#define VALOR_MINIMO_OPERACAO 0.01

void consultarSaldo(const Conta *conta) {
    exibirCabecalho("CONSULTA DE SALDO");
    exibirResumoConta(conta);
    printf("Saldo atual: R$ %.2f\n", conta->saldo);
}

void realizarDeposito(Conta contas[], int quantidade, int indiceConta) {
    double valor;

    exibirCabecalho("DEPOSITO");
    exibirResumoConta(&contas[indiceConta]);

    valor = lerDouble("Valor do deposito: R$ ", VALOR_MINIMO_OPERACAO);

    if (!confirmarOperacao("Confirmar deposito")) {
        printf("Operacao cancelada.\n");
        return;
    }

    contas[indiceConta].saldo += valor;

    if (salvarContas(contas, quantidade)) {
        registrarExtrato(&contas[indiceConta], "DEPOSITO", valor, "Deposito realizado no caixa eletronico");
        printf("Deposito realizado com sucesso.\n");
        printf("Novo saldo: R$ %.2f\n", contas[indiceConta].saldo);
    }
}

void realizarSaque(Conta contas[], int quantidade, int indiceConta) {
    double valor;

    exibirCabecalho("SAQUE");
    exibirResumoConta(&contas[indiceConta]);
    printf("Saldo disponivel: R$ %.2f\n", contas[indiceConta].saldo);

    valor = lerDouble("Valor do saque: R$ ", VALOR_MINIMO_OPERACAO);

    if (valor > contas[indiceConta].saldo) {
        printf("Saque recusado. Saldo insuficiente.\n");
        return;
    }

    if (!confirmarOperacao("Confirmar saque")) {
        printf("Operacao cancelada.\n");
        return;
    }

    contas[indiceConta].saldo -= valor;

    if (salvarContas(contas, quantidade)) {
        registrarExtrato(&contas[indiceConta], "SAQUE", valor, "Saque realizado no caixa eletronico");
        printf("Saque realizado com sucesso.\n");
        printf("Novo saldo: R$ %.2f\n", contas[indiceConta].saldo);
    }
}

void realizarTransferencia(Conta contas[], int quantidade, int indiceOrigem) {
    int numeroDestino;
    int indiceDestino;
    double valor;
    char descricaoOrigem[120];
    char descricaoDestino[120];

    exibirCabecalho("TRANSFERENCIA");
    exibirResumoConta(&contas[indiceOrigem]);
    printf("Saldo disponivel: R$ %.2f\n", contas[indiceOrigem].saldo);

    numeroDestino = lerInteiro("Numero da conta de destino: ", 1, 999999);
    indiceDestino = buscarContaPorNumero(contas, quantidade, numeroDestino);

    if (indiceDestino == -1) {
        printf("Transferencia recusada. Conta de destino nao encontrada.\n");
        return;
    }

    if (indiceDestino == indiceOrigem) {
        printf("Transferencia recusada. A conta de destino nao pode ser a mesma conta de origem.\n");
        return;
    }

    printf("Destinatario: %s\n", contas[indiceDestino].nome);
    valor = lerDouble("Valor da transferencia: R$ ", VALOR_MINIMO_OPERACAO);

    if (valor > contas[indiceOrigem].saldo) {
        printf("Transferencia recusada. Saldo insuficiente.\n");
        return;
    }

    if (!confirmarOperacao("Confirmar transferencia")) {
        printf("Operacao cancelada.\n");
        return;
    }

    contas[indiceOrigem].saldo -= valor;
    contas[indiceDestino].saldo += valor;

    if (salvarContas(contas, quantidade)) {
        snprintf(descricaoOrigem, sizeof(descricaoOrigem), "Transferencia enviada para conta %d - %s", contas[indiceDestino].numero, contas[indiceDestino].nome);
        snprintf(descricaoDestino, sizeof(descricaoDestino), "Transferencia recebida da conta %d - %s", contas[indiceOrigem].numero, contas[indiceOrigem].nome);

        registrarExtrato(&contas[indiceOrigem], "TRANSFERENCIA", valor, descricaoOrigem);
        registrarExtrato(&contas[indiceDestino], "RECEBIMENTO", valor, descricaoDestino);

        printf("Transferencia realizada com sucesso.\n");
        printf("Novo saldo: R$ %.2f\n", contas[indiceOrigem].saldo);
    }
}

void alterarSenha(Conta contas[], int quantidade, int indiceConta) {
    char senhaAtual[TAM_SENHA];
    char novaSenha[TAM_SENHA];
    char confirmacao[TAM_SENHA];

    exibirCabecalho("ALTERACAO DE SENHA");
    exibirResumoConta(&contas[indiceConta]);

    lerLinha("Senha atual: ", senhaAtual, TAM_SENHA);

    if (strcmp(senhaAtual, contas[indiceConta].senha) != 0) {
        printf("Senha atual incorreta. Operacao cancelada.\n");
        return;
    }

    lerLinha("Nova senha numerica ou alfanumerica: ", novaSenha, TAM_SENHA);

    if (strlen(novaSenha) < 4) {
        printf("A nova senha deve possuir pelo menos 4 caracteres.\n");
        return;
    }

    if (strcmp(novaSenha, senhaAtual) == 0) {
        printf("A nova senha nao pode ser igual a senha atual.\n");
        return;
    }

    lerLinha("Confirme a nova senha: ", confirmacao, TAM_SENHA);

    if (strcmp(novaSenha, confirmacao) != 0) {
        printf("As senhas nao conferem. Operacao cancelada.\n");
        return;
    }

    if (!confirmarOperacao("Confirmar alteracao de senha")) {
        printf("Operacao cancelada.\n");
        return;
    }

    strncpy(contas[indiceConta].senha, novaSenha, TAM_SENHA - 1);
    contas[indiceConta].senha[TAM_SENHA - 1] = '\0';

    if (salvarContas(contas, quantidade)) {
        registrarExtrato(&contas[indiceConta], "ALTERACAO", 0.00, "Senha alterada com sucesso");
        printf("Senha alterada com sucesso.\n");
    }
}
