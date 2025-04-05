#include <iostream>

//Nome: Nícolas Kalebe Gualberto Fidelis
//Matricula: 202302573

int particiona(int *vet, int inicio, int fim) {
    int pivo = (vet[inicio] + vet[fim] + vet[(inicio + fim) / 2]) / 3;

    while (inicio <= fim) {
        while (vet[inicio] < pivo) inicio++;
        while (vet[fim] > pivo) fim--;

        if (inicio <= fim) {
            int aux = vet[inicio];
            vet[inicio] = vet[fim];
            vet[fim] = aux;
            inicio++;
            fim--;
        }
    }

    return inicio;
}

void quickSort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int pos = particiona(vet, inicio, fim);
        quickSort(vet, inicio, pos - 1);
        quickSort(vet, pos, fim);
    }
}

void printVetor(int *vet, int tam) {
    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < tam; i++) {
        std::cout << vet[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int vet[] = {5, 4, 1, 3, 2, 6, 0, 9, 8, 7};
    int tam = sizeof(vet) / sizeof(int);

    std::cout << "Vetor desordenado: ";
    for (int i = 0; i < tam; i++) {
        std::cout << vet[i] << " ";
    }
    std::cout << std::endl;

    quickSort(vet, 0, tam - 1);
    printVetor(vet, tam);

    return 0;
}
