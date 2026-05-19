# Simulador de Caixa Eletrônico em C

## Nome do projeto

**ATM Console - Simulador de Caixa Eletrônico**

## Integrantes

- Joao Pedro do Vale Quagliano - RM: 570233

## Descrição do sistema

Este projeto implementa um simulador de caixa eletrônico, também conhecido como ATM (*Automated Teller Machine*), desenvolvido em linguagem C e executado via terminal/console.

O sistema permite que o usuário acesse uma conta bancária de demonstração por meio de número de conta e senha, realize operações bancárias básicas e tenha os dados atualizados em arquivos de texto.

O objetivo do projeto é aplicar conceitos de lógica de programação, estruturas de decisão, estruturas de repetição, funções, modularização, manipulação de arquivos e organização de código-fonte em linguagem C.

## Funcionalidades implementadas

- Login com número da conta e senha;
- Limite de 3 tentativas de login;
- Menu textual organizado;
- Consulta de saldo;
- Depósito com validação de valor;
- Saque com verificação de saldo disponível;
- Transferência entre contas cadastradas;
- Consulta de extrato por conta;
- Alteração de senha;
- Persistência dos dados em arquivo `.txt`;
- Registro das movimentações no extrato;
- Validação de entradas inválidas no menu e nas operações;
- Código organizado em múltiplos arquivos `.c` e `.h`.

## Contas de demonstração

O sistema já possui algumas contas cadastradas no arquivo `data/contas.txt`.

| Conta | Titular | Senha | Saldo inicial |
|---|---|---|---|
| 1001 | Joao Silva | 1234 | R$ 1500.00 |
| 1002 | Maria Souza | 4321 | R$ 2200.50 |
| 1003 | Carlos Lima | 1111 | R$ 850.75 |
| 1004 | Ana Pereira | 2222 | R$ 3000.00 |

Também é possível visualizar essas contas dentro do próprio sistema, pela opção **Ver contas de demonstração** no menu inicial.

## Estrutura do projeto

```txt
atm-c/
│
├── README.md
├── Makefile
├── .gitignore
│
├── include/
│   ├── banco.h
│   ├── extrato.h
│   ├── menu.h
│   ├── modelos.h
│   ├── operacoes.h
│   └── utils.h
│
├── src/
│   ├── main.c
│   ├── banco.c
│   ├── extrato.c
│   ├── menu.c
│   ├── operacoes.c
│   └── utils.c
│
├── data/
│   ├── contas.txt
│   └── .gitkeep
│
└── docs/
    ├── checklist_testes.md
    ├── planejamento.md
    └── roteiro_apresentacao.md
```

## Como compilar

### Opção 1: usando Makefile

No terminal, dentro da pasta do projeto, execute:

```bash
make
```

### Opção 2: usando GCC diretamente

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude src/main.c src/menu.c src/banco.c src/operacoes.c src/extrato.c src/utils.c -o atm
```

No Windows, caso utilize MinGW, o executável pode ser gerado como:

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude src/main.c src/menu.c src/banco.c src/operacoes.c src/extrato.c src/utils.c -o atm.exe
```

## Como executar

### Linux/macOS

```bash
./atm
```

### Windows

```bash
atm.exe
```

## Como limpar o executável gerado

```bash
make clean
```

## Organização do código

O projeto foi modularizado para separar responsabilidades:

- `main.c`: ponto de entrada do programa;
- `menu.c`: menus e fluxo principal do sistema;
- `banco.c`: carregamento, salvamento, busca e autenticação de contas;
- `operacoes.c`: regras de negócio das operações bancárias;
- `extrato.c`: registro e leitura do extrato;
- `utils.c`: funções auxiliares de entrada, validação e interface textual;
- `include/`: arquivos de cabeçalho com protótipos, constantes e estruturas.

## Histórico de commits sugerido para o grupo

Evite commits genéricos como `update`, `teste`, `aaa` ou `final`.

Sugestão de histórico:

```txt
feat: cria estrutura inicial do projeto ATM
feat: adiciona modelo de conta bancaria
feat: implementa leitura e salvamento de contas em arquivo
feat: cria menu inicial e menu de operacoes
feat: implementa login com limite de tentativas
feat: adiciona consulta de saldo
feat: implementa operacao de deposito
feat: implementa saque com validacao de saldo
feat: adiciona transferencia entre contas
feat: implementa registro de extrato
feat: adiciona alteracao de senha
refactor: separa funcoes auxiliares de validacao
fix: corrige tratamento de entradas invalidas no menu
docs: adiciona instrucoes de compilacao e execucao no README
```

## Observações importantes

- O programa deve ser executado a partir da pasta raiz do projeto, pois utiliza os arquivos dentro da pasta `data/`.
- Caso o arquivo `data/contas.txt` não exista, o sistema tenta criar contas padrão automaticamente.
- Os extratos são gerados automaticamente na pasta `data/` com o padrão `extrato_NUMERODACONTA.txt`.
- Antes da entrega, atualize o README com o nome completo dos integrantes.
