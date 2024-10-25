//Guilherme Sandim
//David Tavares

#include "ordenacao.h"
#include <random>
#include <iostream>

using namespace std;

vector<int> gerarVetor(int tamanho, bool aleatorio) {
    vector<int> vetor(tamanho);
    if (aleatorio) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 10000);
        for (int i = 0; i < tamanho; ++i) {
            vetor[i] = dis(gen);
        }
    } else {
        for (int i = 0; i < tamanho; ++i) {
            vetor[i] = tamanho - i;
        }
    }
    return vetor;
}

int main() {
    int tamanho;
    bool aleatorio;
    string algoritmo;

    cout << "Escolha o número de valores (10, 100, 1000, 10000): ";
    cin >> tamanho;

    cout << "Deseja valores aleatórios (1 para sim, 0 para decrescente)? ";
    cin >> aleatorio;

    cout << "Escolha o algoritmo de ordenação (Bubblesort, Selectionsort, Insertionsort, Mergesort, Quicksort, Heapsort, Radixsort, Bucketsort, Countingsort): ";
    cin >> algoritmo;

    vector<int> valores = gerarVetor(tamanho, aleatorio);

    Ordenacao ordenacao(valores);

    cout << "Vetor antes da ordenação: " << endl;
    ordenacao.apresentarVetor();

    ordenacao.ordenar(algoritmo);

    cout << "Vetor após a ordenação: " << endl;
    ordenacao.apresentarVetor();

    ordenacao.gerarEstatisticas();

    return 0;  
}
