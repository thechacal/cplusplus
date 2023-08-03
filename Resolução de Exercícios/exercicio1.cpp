/*
Exercício 1
Uma empresa comercial possui um programa para controle das receitas e despesas em seus 10 projetos. 
Os projetos são numerados de 0 até 9. 
Faça um programa C que controle a entrada e saída de recursos dos projetos. 
O programa deverá ler um conjunto de informações contendo: 
Número do projeto, valor, tipo despesa ("R" - Receita e "D" - Despesa). 
O programa termina quando o valor do código do projeto for igual a -1. 
Sabe-se que Receita deve ser somada ao saldo do projeto e despesa subtraída do saldo do projeto. 
Ao final do programa, imprirmir o saldo final de cada projeto.

Dica: Usar uma estrutura do tipo vetor para controlar os saldos dos projetos. 
Usar o conceito de struct para agrupar as informações lidas.
*/
#include <iostream>
#include <vector>

using namespace std;

// Definindo a classe Projeto para agrupar as informações do projeto
class Projeto {
public:
    int numero;
    float saldo;

    Projeto(int num) : numero(num), saldo(0) {}
    void atualizarSaldo(float valor, char tipoDespesa) {
        if (tipoDespesa == 'R' || tipoDespesa == 'r') {
            saldo += valor;
        } else if (tipoDespesa == 'D' || tipoDespesa == 'd') {
            saldo -= valor;
        } else {
            cout << "Tipo de despesa invalido! Use 'R' para Receita ou 'D' para Despesa." << endl;
        }
    }
};

int main() {
    const int NUM_PROJETOS = 10;

    // Criando um vetor para armazenar os objetos Projeto
    vector<Projeto> projetos;

    // Inicializando o vetor de projetos com objetos Projeto
    for (int i = 0; i < NUM_PROJETOS; i++) {
        projetos.push_back(Projeto(i));
    }

    int numeroProjeto;
    float valor;
    char tipoDespesa;

    // Loop para ler as informações até que o número do projeto seja -1
    while (true) {
        cout << "Digite o numero do projeto (-1 para encerrar): ";
        cin >> numeroProjeto;

        if (numeroProjeto == -1) {
            break; // Encerra o loop caso seja digitado -1
        }

        cout << "Digite o valor: ";
        cin >> valor;

        cout << "Digite o tipo de despesa (R - Receita, D - Despesa): ";
        cin >> tipoDespesa;

        if (numeroProjeto >= 0 && numeroProjeto < NUM_PROJETOS) {
            projetos[numeroProjeto].atualizarSaldo(valor, tipoDespesa);
        } else {
            cout << "Projeto nao encontrado!" << endl;
        }
    }

    // Imprimindo o saldo final de cada projeto
    cout << "\nSaldo final de cada projeto:" << endl;
    for (const Projeto& projeto : projetos) {
        cout << "Projeto " << projeto.numero << ": R$ " << projeto.saldo << endl;
    }

    return 0;
}
