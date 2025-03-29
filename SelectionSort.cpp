#include <stdio.h>

//Nome do Aluno: Nícolas Kalebe Gualberto Fidelis
//Matricula: 202302573

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int vetor[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int index_min = i;
        for (int j = i + 1; j < size; j++) {
            if (vetor[j] < vetor[index_min]) {
                index_min = j;
            }
        }
        troca(&vetor[index_min], &vetor[i]);
    }
}

void printvetor(int vetor[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", vetor[i]);
    }
    printf("\n");
    printf("E o menor valor é %d",vetor[0]);
}

int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);

    selection_sort(data, size);

    printf("Vetor ordenado:\n");
    printvetor(data, size);

    return 0;
}
