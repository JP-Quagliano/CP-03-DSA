# Checklist de Testes do Sistema ATM

Use esta lista antes de enviar o projeto.

## Compilação

- [ ] O projeto compila com `make`.
- [ ] O projeto compila com o comando GCC informado no README.
- [ ] O programa executa a partir da pasta raiz do projeto.
- [ ] Não aparecem erros de compilação.

## Login

- [ ] Login funciona com conta e senha corretas.
- [ ] Login recusa senha incorreta.
- [ ] Login recusa conta inexistente.
- [ ] Sistema retorna ao menu inicial após 3 tentativas incorretas.

## Menu

- [ ] Menu inicial aparece corretamente.
- [ ] Menu de operações aparece após login.
- [ ] Opção inválida não quebra o programa.
- [ ] Entrada com letra não quebra o programa.

## Consulta de saldo

- [ ] Saldo aparece com duas casas decimais.
- [ ] Número da conta e nome do titular aparecem corretamente.

## Depósito

- [ ] Depósito positivo funciona.
- [ ] Depósito com valor zero é recusado.
- [ ] Depósito com valor negativo é recusado.
- [ ] Depósito com letras é recusado.
- [ ] Saldo é atualizado após depósito.
- [ ] Operação aparece no extrato.

## Saque

- [ ] Saque positivo funciona quando há saldo suficiente.
- [ ] Saque maior que o saldo é recusado.
- [ ] Saque com valor zero é recusado.
- [ ] Saque com valor negativo é recusado.
- [ ] Saldo é atualizado após saque.
- [ ] Operação aparece no extrato.

## Transferência

- [ ] Transferência para conta existente funciona.
- [ ] Transferência para conta inexistente é recusada.
- [ ] Transferência para a própria conta é recusada.
- [ ] Transferência maior que o saldo é recusada.
- [ ] Saldo da origem diminui corretamente.
- [ ] Saldo do destino aumenta corretamente.
- [ ] Operação aparece no extrato da conta origem.
- [ ] Recebimento aparece no extrato da conta destino.

## Alteração de senha

- [ ] Alteração funciona com senha atual correta.
- [ ] Alteração é recusada com senha atual incorreta.
- [ ] Nova senha com menos de 4 caracteres é recusada.
- [ ] Nova senha igual à atual é recusada.
- [ ] Confirmação diferente é recusada.
- [ ] Login passa a aceitar a nova senha após alteração.

## Persistência

- [ ] Alterações de saldo são salvas em `data/contas.txt`.
- [ ] Após fechar e abrir o programa, os saldos atualizados continuam salvos.
- [ ] Extratos são criados na pasta `data/`.

## README e GitHub

- [ ] README contém nome do projeto.
- [ ] README contém nome completo dos integrantes.
- [ ] README contém descrição do sistema.
- [ ] README contém funcionalidades implementadas.
- [ ] README contém instruções de compilação.
- [ ] README contém instruções de execução.
- [ ] Repositório contém commits descritivos.
