# Planejamento do Projeto ATM

## Objetivo

Desenvolver um simulador de caixa eletrônico em linguagem C, executado via terminal, com interface textual e operações bancárias básicas.

## Requisitos funcionais

- Permitir acesso por número de conta e senha;
- Permitir consulta de saldo;
- Permitir depósito;
- Permitir saque;
- Permitir transferência entre contas;
- Permitir consulta de extrato;
- Permitir alteração de senha;
- Permitir encerramento seguro da sessão;
- Manter dados das contas em arquivo de texto.

## Requisitos não funcionais

- Código escrito em linguagem C;
- Sistema executado via terminal;
- Código modularizado em arquivos `.c` e `.h`;
- Interface textual organizada;
- Entradas do usuário validadas;
- README com instruções de compilação e execução;
- Versionamento com Git e GitHub.

## Divisão sugerida de tarefas

| Integrante | Responsabilidade sugerida |
|---|---|
| Integrante 1 | Estrutura inicial, `main.c`, menus e fluxo principal |
| Integrante 2 | Cadastro/carregamento/salvamento de contas em arquivo |
| Integrante 3 | Operações bancárias: saldo, depósito, saque e transferência |
| Integrante 4 | Extrato, README, testes e revisão final |

## Decisões de implementação

- As contas são armazenadas em `data/contas.txt`.
- Cada linha do arquivo segue o formato: `numero;nome;senha;saldo`.
- Os extratos são salvos em arquivos separados por conta.
- O sistema usa `fgets`, `strtol` e `strtod` para evitar problemas comuns de leitura com `scanf`.
- As operações financeiras rejeitam valores negativos, zero e entradas inválidas.

## Casos de erro tratados

- Conta inexistente;
- Senha incorreta;
- Limite de tentativas de login;
- Saldo insuficiente para saque;
- Saldo insuficiente para transferência;
- Transferência para a própria conta;
- Valor inválido em operações financeiras;
- Opção inválida no menu;
- Arquivo de contas inexistente.
