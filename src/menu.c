#include <stdio.h>
#include "menu.h"
#include "banco.h"
#include "operacoes.h"
#include "extrato.h"
#include "utils.h"

int menuInicial(void) {
    exibirCabecalho("SIMULADOR DE CAIXA ELETRONICO - ATM");
    printf("1. Acessar conta\n");
    printf("2. Ver contas de demonstracao\n");
    printf("0. Encerrar sistema\n");

    return lerInteiro("Escolha uma opcao: ", 0, 2);
}

int menuOperacoes(const Conta *conta) {
    exibirCabecalho("MENU DE OPERACOES");
    printf("Usuario: %s | Conta: %d\n\n", conta->nome, conta->numero);
    printf("1. Consultar saldo\n");
    printf("2. Realizar deposito\n");
    printf("3. Realizar saque\n");
    printf("4. Realizar transferencia\n");
    printf("5. Consultar extrato\n");
    printf("6. Alterar senha\n");
    printf("0. Sair da conta\n");

    return lerInteiro("Escolha uma opcao: ", 0, 6);
}

int realizarLogin(Conta contas[], int quantidade) {
    int numero;
    char senha[TAM_SENHA];
    int indice;
    int tentativas = 3;

    while (tentativas > 0) {
        exibirCabecalho("LOGIN");
        printf("Tentativas restantes: %d\n\n", tentativas);

        numero = lerInteiro("Numero da conta: ", 1, 999999);
        lerLinha("Senha: ", senha, TAM_SENHA);

        indice = autenticarConta(contas, quantidade, numero, senha);

        if (indice != -1) {
            printf("Login realizado com sucesso. Bem-vindo(a), %s!\n", contas[indice].nome);
            return indice;
        }

        printf("Conta ou senha incorreta.\n");
        tentativas--;
        pausar();
    }

    printf("Numero maximo de tentativas atingido. Retornando ao menu inicial.\n");
    return -1;
}

static void exibirContasDemonstracao(Conta contas[], int quantidade) {
    exibirCabecalho("CONTAS DE DEMONSTRACAO");
    printf("Use uma das contas abaixo para testar o sistema.\n\n");

    for (int i = 0; i < quantidade; i++) {
        printf("Conta: %d | Titular: %-20s | Senha: %s | Saldo: R$ %.2f\n",
               contas[i].numero,
               contas[i].nome,
               contas[i].senha,
               contas[i].saldo);
    }
}

static void executarOperacoesConta(Conta contas[], int quantidade, int indiceConta) {
    int opcao;
    int continuar = 1;

    while (continuar) {
        limparTela();
        opcao = menuOperacoes(&contas[indiceConta]);

        switch (opcao) {
            case 1:
                consultarSaldo(&contas[indiceConta]);
                pausar();
                break;
            case 2:
                realizarDeposito(contas, quantidade, indiceConta);
                pausar();
                break;
            case 3:
                realizarSaque(contas, quantidade, indiceConta);
                pausar();
                break;
            case 4:
                realizarTransferencia(contas, quantidade, indiceConta);
                pausar();
                break;
            case 5:
                exibirExtrato(&contas[indiceConta]);
                pausar();
                break;
            case 6:
                alterarSenha(contas, quantidade, indiceConta);
                pausar();
                break;
            case 0:
                printf("Sessao encerrada com seguranca.\n");
                continuar = 0;
                pausar();
                break;
            default:
                printf("Opcao invalida.\n");
                pausar();
                break;
        }
    }
}

void executarSistema(void) {
    Conta contas[MAX_CONTAS];
    int quantidade;
    int opcao;
    int indiceLogado;
    int executando = 1;

    criarContasPadraoSeNecessario();
    quantidade = carregarContas(contas, MAX_CONTAS);

    if (quantidade == 0) {
        printf("Nao foi possivel carregar contas. O sistema sera encerrado.\n");
        return;
    }

    while (executando) {
        limparTela();
        opcao = menuInicial();

        switch (opcao) {
            case 1:
                indiceLogado = realizarLogin(contas, quantidade);
                if (indiceLogado != -1) {
                    pausar();
                    executarOperacoesConta(contas, quantidade, indiceLogado);
                    quantidade = carregarContas(contas, MAX_CONTAS);
                }
                break;
            case 2:
                exibirContasDemonstracao(contas, quantidade);
                pausar();
                break;
            case 0:
                printf("Sistema encerrado. Obrigado por utilizar o ATM.\n");
                executando = 0;
                break;
            default:
                printf("Opcao invalida.\n");
                pausar();
                break;
        }
    }
}
