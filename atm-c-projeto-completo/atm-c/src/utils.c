#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "utils.h"

void removerQuebraLinha(char texto[]) {
    size_t tamanho = strlen(texto);
    if (tamanho > 0 && texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }
}

void removerEspacosLaterais(char texto[]) {
    int inicio = 0;
    int fim = (int)strlen(texto) - 1;

    while (texto[inicio] != '\0' && isspace((unsigned char)texto[inicio])) {
        inicio++;
    }

    while (fim >= inicio && isspace((unsigned char)texto[fim])) {
        fim--;
    }

    int i = 0;
    while (inicio <= fim) {
        texto[i++] = texto[inicio++];
    }
    texto[i] = '\0';
}

void lerLinha(const char mensagem[], char destino[], int tamanho) {
    while (1) {
        printf("%s", mensagem);

        if (fgets(destino, tamanho, stdin) == NULL) {
            clearerr(stdin);
            destino[0] = '\0';
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }

        removerQuebraLinha(destino);
        removerEspacosLaterais(destino);

        if (strlen(destino) == 0) {
            printf("Entrada vazia. Tente novamente.\n");
            continue;
        }

        return;
    }
}

int lerInteiro(const char mensagem[], int minimo, int maximo) {
    char entrada[100];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            clearerr(stdin);
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }

        removerQuebraLinha(entrada);
        removerEspacosLaterais(entrada);

        errno = 0;
        valor = strtol(entrada, &fim, 10);

        while (*fim != '\0' && isspace((unsigned char)*fim)) {
            fim++;
        }

        if (entrada[0] == '\0' || *fim != '\0' || errno == ERANGE) {
            printf("Digite apenas numeros inteiros.\n");
            continue;
        }

        if (valor < minimo || valor > maximo) {
            printf("Digite um valor entre %d e %d.\n", minimo, maximo);
            continue;
        }

        return (int)valor;
    }
}

double lerDouble(const char mensagem[], double minimo) {
    char entrada[100];
    char *fim;
    double valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            clearerr(stdin);
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }

        removerQuebraLinha(entrada);
        removerEspacosLaterais(entrada);

        for (int i = 0; entrada[i] != '\0'; i++) {
            if (entrada[i] == ',') {
                entrada[i] = '.';
            }
        }

        errno = 0;
        valor = strtod(entrada, &fim);

        while (*fim != '\0' && isspace((unsigned char)*fim)) {
            fim++;
        }

        if (entrada[0] == '\0' || *fim != '\0' || errno == ERANGE) {
            printf("Digite um valor numerico valido.\n");
            continue;
        }

        if (valor < minimo) {
            printf("Digite um valor maior ou igual a %.2f.\n", minimo);
            continue;
        }

        return valor;
    }
}

void pausar(void) {
    char entrada[10];
    printf("\nPressione ENTER para continuar...");
    fgets(entrada, sizeof(entrada), stdin);
}

void exibirCabecalho(const char titulo[]) {
    printf("\n========================================\n");
    printf("  %s\n", titulo);
    printf("========================================\n");
}

int confirmarOperacao(const char mensagem[]) {
    char resposta[10];

    while (1) {
        printf("%s (s/n): ", mensagem);

        if (fgets(resposta, sizeof(resposta), stdin) == NULL) {
            clearerr(stdin);
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }

        removerQuebraLinha(resposta);
        removerEspacosLaterais(resposta);

        if (strlen(resposta) == 1) {
            resposta[0] = (char)tolower((unsigned char)resposta[0]);
            if (resposta[0] == 's') {
                return 1;
            }
            if (resposta[0] == 'n') {
                return 0;
            }
        }

        printf("Resposta invalida. Digite s para sim ou n para nao.\n");
    }
}

void limparTela(void) {
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
}
