## Ordenação em C++

Este projeto implementa diversos algoritmos de ordenação em C++ e compara seu desempenho em termos de tempo de execução, número de comparações e número de trocas. O código inclui uma classe chamada `Ordenacao`, que encapsula os diferentes algoritmos e oferece métodos para ordenação e exibição de estatísticas.

### [Video apresentando o código](https://drive.google.com/file/d/1Nw16yfuxHAY7nwMNM6CYpKA69X-t36kj/view?usp=sharing)

### Algoritmos de Ordenação Implementados

- Bubblesort
- Selectionsort
- Insertionsort
- Mergesort
- Quicksort
- Heapsort
- Radixsort
- Bucketsort
- Countingsort

### Funcionalidades

- **Gerar Vetor**: Cria um vetor de números aleatórios ou em ordem decrescente para ser ordenado.
- **Ordenar Vetor**: Aplica o algoritmo de ordenação escolhido ao vetor.
- **Exibir Estatísticas**: Mostra o número de comparações e trocas realizadas pelo algoritmo de ordenação, além do tempo de execução.
- **Apresentar Vetor**: Exibe o vetor antes e depois da ordenação.

### Exemplo de Execução

```bash
Escolha o número de valores (10, 100, 1000, 10000): 1000
Deseja valores aleatórios (1 para sim, 0 para decrescente)? 1
Escolha o algoritmo de ordenação (Bubblesort, Selectionsort, Insertionsort, Mergesort, Quicksort, Heapsort, Radixsort, Bucketsort, Countingsort): Mergesort

Vetor antes da ordenação:
1000 999 998 ... 1

Vetor após a ordenação:
1 2 3 ... 1000

Número de comparações: 499500
Número de trocas: 499500
Tempo de execução: 2.4 ms
