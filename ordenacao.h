#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <vector>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class Ordenacao {
private:
    vector<int> vetor;
    int numComparacoes;
    int numTrocas;
    high_resolution_clock::time_point inicio, fim;

    // Funções privadas para os algoritmos de ordenação
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void mergeSort(int esq, int dir);
    void merge(int esq, int meio, int dir);
    void quickSort(int esq, int dir);
    int partition(int esq, int dir);
    void heapSort();
    void heapify(int n, int i);
    void radixSort();
    void bucketSort();  
    void countingSort(int exp);

public:
    // Construtor
    Ordenacao(const vector<int>& valores);

    // Funções públicas
    void ordenar(string algoritmo);
    void gerarEstatisticas();
    void apresentarVetor();
    void configurarTemporizador();
    void finalizarTemporizador();
    void exibirTempo(long long duracao);
};

#endif
