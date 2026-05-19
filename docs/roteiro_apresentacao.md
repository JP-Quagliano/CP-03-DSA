# Roteiro de Apresentação Prática

## 1. Introdução

Este projeto é um simulador de caixa eletrônico desenvolvido em linguagem C. Ele permite realizar operações bancárias básicas via terminal, como login, consulta de saldo, depósito, saque, transferência, extrato e alteração de senha.

## 2. Organização do código

Explique que o projeto foi dividido em módulos:

- `main.c`: inicia o sistema;
- `menu.c`: controla os menus e o fluxo principal;
- `banco.c`: manipula contas, autenticação e arquivo de contas;
- `operacoes.c`: contém as operações bancárias;
- `extrato.c`: registra e exibe movimentações;
- `utils.c`: concentra validações e funções auxiliares.

## 3. Demonstração sugerida

### Passo 1: Compilar

```bash
make
```

Ou:

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude src/main.c src/menu.c src/banco.c src/operacoes.c src/extrato.c src/utils.c -o atm
```

### Passo 2: Executar

```bash
./atm
```

### Passo 3: Exibir contas de demonstração

Mostre a opção `Ver contas de demonstração`.

### Passo 4: Realizar login

Use, por exemplo:

- Conta: `1001`
- Senha: `1234`

### Passo 5: Consultar saldo

Mostre o saldo inicial da conta.

### Passo 6: Fazer depósito

Deposite um valor pequeno, por exemplo `100`.

### Passo 7: Fazer saque

Saque um valor menor que o saldo disponível, por exemplo `50`.

### Passo 8: Testar erro de saque

Tente sacar um valor maior que o saldo para mostrar a validação.

### Passo 9: Fazer transferência

Transfira um valor para outra conta, por exemplo conta `1002`.

### Passo 10: Consultar extrato

Mostre que as operações foram registradas no extrato.

### Passo 11: Alterar senha

Altere a senha da conta e explique que os dados são salvos no arquivo.

## 4. Pontos fortes para mencionar

- O sistema não quebra com entradas inválidas;
- As operações são validadas;
- Os dados são persistidos em arquivos;
- O código foi modularizado;
- O README explica como compilar e executar;
- O projeto foi pensado para ser fácil de testar e apresentar.
