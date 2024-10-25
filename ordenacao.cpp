#include "ordenacao.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Construtor para inicializar o vetor
Ordenacao::Ordenacao(const vector<int>& valores) {
    vetor = valores;
    numComparacoes = 0;
    numTrocas = 0;
}

// Inicia o temporizador
void Ordenacao::configurarTemporizador() {
    inicio = high_resolution_clock::now();
}

// Finaliza o temporizador e calcula o tempo total em microsegundos
void Ordenacao::finalizarTemporizador() {
    fim = high_resolution_clock::now();
    auto duracao = duration_cast<microseconds>(fim - inicio).count();  // Ajustado para microsegundos
    exibirTempo(duracao);
}

// Exibe o vetor
void Ordenacao::apresentarVetor() {
    for (int i : vetor) {
        cout << i << " ";
    }
    cout << endl;
}

// Ordena com base no algoritmo selecionado
void Ordenacao::ordenar(string algoritmo) {
    configurarTemporizador();
    if (algoritmo == "Bubblesort") bubbleSort();
    else if (algoritmo == "Selectionsort") selectionSort();
    else if (algoritmo == "Insertionsort") insertionSort();
    else if (algoritmo == "Mergesort") mergeSort(0, vetor.size() - 1);
    else if (algoritmo == "Quicksort") quickSort(0, vetor.size() - 1);
    else if (algoritmo == "Heapsort") heapSort();
    else if (algoritmo == "Radixsort") radixSort();
    else if (algoritmo == "Bucketsort") bucketSort();
    finalizarTemporizador();
}

// Exibe o tempo de execução formatado
void Ordenacao::exibirTempo(long long duracao) {
    if (duracao < 1000) {
        cout << "Tempo de execução: " << duracao << " µs" << endl;
    } else if (duracao < 1000000) {
        cout << "Tempo de execução: " << duracao / 1000.0 << " ms" << endl;
    } else if (duracao < 60000000) {
        cout << "Tempo de execução: " << duracao / 1000000.0 << " s" << endl;
    } else {
        cout << "Tempo de execução: " << duracao / 60000000.0 << " min" << endl;
    }
}

// Estatísticas de comparações e trocas
void Ordenacao::gerarEstatisticas() {
    cout << "Número de comparações: " << numComparacoes << endl;
    cout << "Número de trocas: " << numTrocas << endl;
}

// Implementação dos algoritmos de ordenação

void Ordenacao::bubbleSort() {
    int n = vetor.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            numComparacoes++;
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
                numTrocas++;
            }
        }
    }
}

void Ordenacao::selectionSort() {
    int n = vetor.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            numComparacoes++;
            if (vetor[j] < vetor[minIdx])
                minIdx = j;
        }
        swap(vetor[minIdx], vetor[i]);
        numTrocas++;
    }
}

void Ordenacao::insertionSort() {
    int n = vetor.size();
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;
        numComparacoes++;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
            numTrocas++;
        }
        vetor[j + 1] = chave;
    }
}

void Ordenacao::mergeSort(int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(esq, meio);
        mergeSort(meio + 1, dir);
        merge(esq, meio, dir);
    }
}

void Ordenacao::merge(int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vetor[esq + i];
    for (int i = 0; i < n2; i++)
        R[i] = vetor[meio + 1 + i];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        numComparacoes++;
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
        numTrocas++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void Ordenacao::quickSort(int esq, int dir) {
    if (esq < dir) {
        int p = partition(esq, dir);
        quickSort(esq, p - 1);
        quickSort(p + 1, dir);
    }
}

int Ordenacao::partition(int esq, int dir) {
    int pivo = vetor[dir];
    int i = esq - 1;
    for (int j = esq; j < dir; j++) {
        numComparacoes++;
        if (vetor[j] < pivo) {
            i++;
            swap(vetor[i], vetor[j]);
            numTrocas++;
        }
    }
    swap(vetor[i + 1], vetor[dir]);
    numTrocas++;
    return i + 1;
}

void Ordenacao::heapSort() {
    int n = vetor.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(vetor[0], vetor[i]);
        numTrocas++;
        heapify(i, 0);
    }
}

void Ordenacao::heapify(int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    numComparacoes++;
    if (esq < n && vetor[esq] > vetor[maior])
        maior = esq;

    numComparacoes++;
    if (dir < n && vetor[dir] > vetor[maior])
        maior = dir;

    if (maior != i) {
        swap(vetor[i], vetor[maior]);
        numTrocas++;
        heapify(n, maior);
    }
}

void Ordenacao::radixSort() {
    int max = *max_element(vetor.begin(), vetor.end());
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(exp);
}

void Ordenacao::countingSort(int expo) {
    int n = vetor.size();

    if (n == 0)
        return;

    int max_valor = *max_element(vetor.begin(), vetor.end()); // Maior valor do vetor
    int min_valor = *min_element(vetor.begin(), vetor.end()); // Menor valor (caso tenha números negativos)

    // Ajuste do intervalo para lidar com valores negativos
    int range = max_valor - min_valor + 1;

    vector<int> count(range, 0);  // Vetor de contagem inicializado com zeros
    vector<int> output(n);        // Vetor de saída

    // Contar as ocorrências de cada número no vetor original
    for (int i = 0; i < n; i++) {
        count[vetor[i] - min_valor]++;
    }

    // Atualizar o vetor de contagem
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Construir o vetor de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[vetor[i] - min_valor] - 1] = vetor[i];
        count[vetor[i] - min_valor]--;
    }

    // Copiar o vetor de saída para o vetor original
    for (int i = 0; i < n; i++) {
        vetor[i] = output[i];
    }
}


void Ordenacao::bucketSort() {
    int n = vetor.size();
    if (n <= 0)
        return;

    int max_val = *max_element(vetor.begin(), vetor.end());
    int min_val = *min_element(vetor.begin(), vetor.end());

    int bucket_count = 10;
    vector<vector<int>> buckets(bucket_count);

    for (int i = 0; i < n; i++) {
        int bucket_index = (bucket_count * (vetor[i] - min_val)) / (max_val - min_val + 1);
        buckets[bucket_index].push_back(vetor[i]);
    }

    for (int i = 0; i < bucket_count; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            vetor[index++] = buckets[i][j];
            numTrocas++;
        }
    }
}
