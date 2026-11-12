/******************************************************************************

Nome: Thalles Eduardo Rodrigues De Paula
Matricula: 28386
Curso: Analise e Desenvolvimento de Sistemas
Obj: segunda etapa do sistema bancario

******************************************************************************/

#include <iostream> // permite usar cin e cout
#include <string> // permite trabalhar com textos
#include <limits> // ajuda a limpar entradas invalidas
#include <iomanip> // mostra valores com duas casas decimais

using namespace std;

int main()
{
// aqui vou guardar os dados de ate 100 contas
const int MAX_CONTAS = 100;

int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];

// controla quantas contas foram cadastradas
int quantidadeContas = 0;

// aqui guardo o historico das movimentacoes
const int MAX_MOVIMENTACOES = 500;

int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];

// conta quantas movimentacoes foram feitas
int quantidadeMovimentacoes = 0;

int opcao;

// deixa os valores com duas casas decimais
cout << fixed << setprecision(2);

// faz o menu ficar repetindo ate escolher sair
while(true)
{
cout << "\n********************************" << endl;
cout << "**         BANCO INF101        **" << endl;
cout << "********************************" << endl;

cout << "1 - Cadastrar conta" << endl;
cout << "2 - Listar contas" << endl;
cout << "3 - Consultar conta" << endl;
cout << "4 - Depositar" << endl;
cout << "5 - Sacar" << endl;
cout << "6 - Transferir" << endl;
cout << "7 - Exibir extrato" << endl;
cout << "8 - Sair" << endl;

cout << "Digite o que deseja: ";
cin >> opcao;

// verifica se a pessoa digitou um numero
if(cin.fail())
{
if(cin.eof())
return 0;

cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Opcao invalida! Digite um numero." << endl;
continue;
}

// escolhe qual parte do programa vai executar
switch(opcao)
{
// CADASTRAR CONTA
case 1:
{
// verifica se ja chegou ao limite de contas
if(quantidadeContas >= MAX_CONTAS)
{
cout << "Limite de contas atingido!" << endl;
break;
}

// variaveis para receber os dados do cliente
int novoNumero, novoTipo;
string novoNome, novoCpf;
double saldoInicial;
bool numeroJaExiste = false;

cout << "\n** Cadastro de conta **" << endl;

cout << "Digite o numero da conta: ";
cin >> novoNumero;

// o numero da conta tem que ser positivo
if(cin.fail() || novoNumero <= 0)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Numero da conta invalido!" << endl;
break;
}

// verifica se esse numero ja foi cadastrado
for(int i = 0; i < quantidadeContas; i++)
{
if(numeroConta[i] == novoNumero)
{
numeroJaExiste = true;
break;
}
}

// nao permite duas contas com o mesmo numero
if(numeroJaExiste)
{
cout << "Ja existe uma conta com esse numero!" << endl;
break;
}

cout << "Digite o nome do titular: ";

// limpa o enter que ficou do cin
cin.ignore(numeric_limits<streamsize>::max(), '\n');

// permite digitar o nome completo
getline(cin, novoNome);

if(novoNome.empty())
{
cout << "Nome invalido!" << endl;
break;
}

cout << "Digite seu CPF: ";
getline(cin, novoCpf);

if(novoCpf.empty())
{
cout << "CPF invalido!" << endl;
break;
}

cout << "Tipo de conta:" << endl;
cout << "1 - Corrente" << endl;
cout << "2 - Poupanca" << endl;

cout << "Digite: ";
cin >> novoTipo;

// verifica se o tipo de conta existe
if(cin.fail() || (novoTipo != 1 && novoTipo != 2))
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Tipo de conta invalido!" << endl;
break;
}

cout << "Saldo inicial: ";
cin >> saldoInicial;

// nao permite saldo inicial negativo
if(cin.fail() || saldoInicial < 0)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Saldo inicial invalido!" << endl;
break;
}

// salvo os dados na proxima posicao livre
numeroConta[quantidadeContas] = novoNumero;
nomeCliente[quantidadeContas] = novoNome;
cpf[quantidadeContas] = novoCpf;
tipoConta[quantidadeContas] = novoTipo;
saldo[quantidadeContas] = saldoInicial;

// toda conta cadastrada comeca ativa
contaAtiva[quantidadeContas] = true;

// aumenta a quantidade de contas cadastradas
quantidadeContas++;

cout << "Conta cadastrada com sucesso!" << endl;

break;
}

// LISTAR CONTAS
case 2:
{
cout << "\n** Contas cadastradas **" << endl;

// verifica se existe alguma conta cadastrada
if(quantidadeContas == 0)
{
cout << "Nenhuma conta cadastrada." << endl;
break;
}

// percorre todas as contas cadastradas
for(int i = 0; i < quantidadeContas; i++)
{
cout << "\nConta: " << numeroConta[i] << endl;
cout << "Titular: " << nomeCliente[i] << endl;

// mostra se a conta e corrente ou poupanca
cout << "Tipo: " << (tipoConta[i] == 1 ? "Corrente" : "Poupanca") << endl;

cout << "Saldo: R$ " << saldo[i] << endl;

// mostra se a conta esta ativa ou inativa
cout << "Situacao: " << (contaAtiva[i] ? "Ativa" : "Inativa") << endl;
}

break;
}

// CONSULTAR CONTA
case 3:
{
int numeroBusca;
int posicao = -1;

cout << "\n** Consultar conta **" << endl;
cout << "Digite o numero da conta: ";
cin >> numeroBusca;

if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Numero invalido!" << endl;
break;
}

// procura o numero digitado nos vetores
for(int i = 0; i < quantidadeContas; i++)
{
if(numeroConta[i] == numeroBusca)
{
posicao = i;
break;
}
}

// -1 significa que a conta nao foi encontrada
if(posicao == -1)
{
cout << "Conta nao encontrada!" << endl;
break;
}

// mostra os dados da conta encontrada
cout << "\n** Dados da conta **" << endl;
cout << "Numero: " << numeroConta[posicao] << endl;
cout << "Titular: " << nomeCliente[posicao] << endl;
cout << "CPF: " << cpf[posicao] << endl;

cout << "Tipo: " << (tipoConta[posicao] == 1 ? "Corrente" : "Poupanca") << endl;

cout << "Saldo: R$ " << saldo[posicao] << endl;

cout << "Situacao: " << (contaAtiva[posicao] ? "Ativa" : "Inativa") << endl;

break;
}

// DEPOSITAR
case 4:
{
int numeroBusca;
int posicao = -1;
double valor;

cout << "\n** Deposito **" << endl;
cout << "Numero da conta: ";
cin >> numeroBusca;

if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Numero invalido!" << endl;
break;
}

// procura a conta que vai receber o deposito
for(int i = 0; i < quantidadeContas; i++)
{
if(numeroConta[i] == numeroBusca)
{
posicao = i;
break;
}
}

if(posicao == -1)
{
cout << "Conta nao encontrada!" << endl;
break;
}

// conta desativada nao pode receber deposito
if(!contaAtiva[posicao])
{
cout << "Essa conta esta desativada!" << endl;
break;
}

// verifica se ainda tem espaco no historico
if(quantidadeMovimentacoes >= MAX_MOVIMENTACOES)
{
cout << "Historico cheio. Deposito nao realizado!" << endl;
break;
}

cout << "Valor do deposito: R$ ";
cin >> valor;

// o deposito precisa ser maior que zero
if(cin.fail() || valor <= 0)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Valor invalido!" << endl;
break;
}

// adiciona o dinheiro ao saldo da conta
saldo[posicao] += valor;

// registra o deposito no historico
contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicao];
tipoMovimentacao[quantidadeMovimentacoes] = 'D';
valorMovimentacao[quantidadeMovimentacoes] = valor;

// aumenta o numero de movimentacoes
quantidadeMovimentacoes++;

cout << "Deposito realizado!" << endl;
cout << "Novo saldo: R$ " << saldo[posicao] << endl;

break;
}

// SACAR
case 5:
{
int numeroBusca;
int posicao = -1;
double valor;

cout << "\n** Saque **" << endl;
cout << "Numero da conta: ";
cin >> numeroBusca;

if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Numero invalido!" << endl;
break;
}

// procura a conta que vai fazer o saque
for(int i = 0; i < quantidadeContas; i++)
{
if(numeroConta[i] == numeroBusca)
{
posicao = i;
break;
}
}

if(posicao == -1)
{
cout << "Conta nao encontrada!" << endl;
break;
}

// verifica se a conta esta ativa
if(!contaAtiva[posicao])
{
cout << "Essa conta esta desativada!" << endl;
break;
}

// precisa ter espaco para registrar o saque
if(quantidadeMovimentacoes >= MAX_MOVIMENTACOES)
{
cout << "Historico cheio. Saque nao realizado!" << endl;
break;
}

cout << "Valor do saque: R$ ";
cin >> valor;

// nao permite sacar valor negativo ou zero
if(cin.fail() || valor <= 0)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Valor invalido!" << endl;
break;
}

// verifica se o cliente possui saldo suficiente
if(valor > saldo[posicao])
{
cout << "Saldo insuficiente!" << endl;
break;
}

// retira o dinheiro do saldo
saldo[posicao] -= valor;

// guarda o saque no historico
contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicao];
tipoMovimentacao[quantidadeMovimentacoes] = 'S';
valorMovimentacao[quantidadeMovimentacoes] = valor;

quantidadeMovimentacoes++;

cout << "Saque realizado!" << endl;
cout << "Novo saldo: R$ " << saldo[posicao] << endl;

break;
}

// TRANSFERIR
case 6:
{
int numeroOrigem, numeroDestino;
int indiceOrigem = -1;
int indiceDestino = -1;
double valor;

cout << "\n** Transferencia **" << endl;

cout << "Conta de origem: ";
cin >> numeroOrigem;

if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Numero invalido!" << endl;
break;
}

cout << "Conta de destino: ";
cin >> numeroDestino;

if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Numero invalido!" << endl;
break;
}

// nao pode transferir para a mesma conta
if(numeroOrigem == numeroDestino)
{
cout << "Escolha duas contas diferentes!" << endl;
break;
}

// procura a conta de origem e a de destino
for(int i = 0; i < quantidadeContas; i++)
{
if(numeroConta[i] == numeroOrigem)
{
indiceOrigem = i;
}

if(numeroConta[i] == numeroDestino)
{
indiceDestino = i;
}
}

// verifica se as duas contas existem
if(indiceOrigem == -1 || indiceDestino == -1)
{
cout << "Uma das contas nao foi encontrada!" << endl;
break;
}

// verifica se as duas contas estao ativas
if(!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino])
{
cout << "As duas contas precisam estar ativas!" << endl;
break;
}

// a transferencia precisa de dois registros
if(quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES)
{
cout << "Historico sem espaco para a transferencia!" << endl;
break;
}

cout << "Valor da transferencia: R$ ";
cin >> valor;

// verifica se o valor e positivo
if(cin.fail() || valor <= 0)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Valor invalido!" << endl;
break;
}

// verifica se tem dinheiro na conta de origem
if(valor > saldo[indiceOrigem])
{
cout << "Saldo insuficiente na conta de origem!" << endl;
break;
}

// retira o dinheiro da conta que esta enviando
saldo[indiceOrigem] -= valor;

// adiciona o dinheiro na conta que esta recebendo
saldo[indiceDestino] += valor;

// registra a saida na primeira conta
contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
tipoMovimentacao[quantidadeMovimentacoes] = 'S';
valorMovimentacao[quantidadeMovimentacoes] = valor;

quantidadeMovimentacoes++;

// registra a entrada na segunda conta
contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
tipoMovimentacao[quantidadeMovimentacoes] = 'D';
valorMovimentacao[quantidadeMovimentacoes] = valor;

quantidadeMovimentacoes++;

cout << "Transferencia realizada com sucesso!" << endl;

break;
}

// EXIBIR EXTRATO
case 7:
{
int numeroBusca;
int posicao = -1;
bool encontrouMovimentacao = false;

cout << "\n** Extrato da conta **" << endl;
cout << "Numero da conta: ";
cin >> numeroBusca;

if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Numero invalido!" << endl;
break;
}

// procura a conta informada pelo usuario
for(int i = 0; i < quantidadeContas; i++)
{
if(numeroConta[i] == numeroBusca)
{
posicao = i;
break;
}
}

if(posicao == -1)
{
cout << "Conta nao encontrada!" << endl;
break;
}

cout << "Titular: " << nomeCliente[posicao] << endl;

// percorre todas as movimentacoes registradas
for(int i = 0; i < quantidadeMovimentacoes; i++)
{
// mostra apenas as movimentacoes dessa conta
if(contaMovimentacao[i] == numeroConta[posicao])
{
encontrouMovimentacao = true;

// D representa entrada de dinheiro
if(tipoMovimentacao[i] == 'D')
{
cout << "Entrada (deposito): R$ " << valorMovimentacao[i] << endl;
}

// S representa saida de dinheiro
else if(tipoMovimentacao[i] == 'S')
{
cout << "Saida (saque ou transferencia): R$ " << valorMovimentacao[i] << endl;
}
}
}

// avisa quando nao existe movimentacao
if(!encontrouMovimentacao)
{
cout << "Nenhuma movimentacao registrada." << endl;
}

// mostra o saldo depois das movimentacoes
cout << "Saldo atual: R$ " << saldo[posicao] << endl;

break;
}

// SAIR
case 8:
{
cout << "Programa terminado com sucesso!" << endl;

// encerra o programa
return 0;
}

default:
{
cout << "Opcao invalida!" << endl;
break;
}
}
}

return 0;
}
