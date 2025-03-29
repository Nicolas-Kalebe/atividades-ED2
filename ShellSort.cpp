#include <iostream>
#include <vector>

void printArray(std::vector<int>& vetor) {
    for (int num : vetor) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void shellSort(std::vector<int>& vetor) {
    int tamanho = vetor.size();
    int h = 1;
    
    while (h < tamanho / 3) {
        h = 3 * h + 1;
    }
    while (h > 0) {
        std::cout << "Iniciando ordenação com h = " << h << std::endl;

        for (int i = h; i < tamanho; i++) {
            int aux = vetor[i];
            int j = i;

            while (j >= h && aux < vetor[j - h]) {
                vetor[j] = vetor[j - h];
                j -= h;
            }
            vetor[j] = aux;
        }

        std::cout << "Depois de h = " << h << ": ";
        printArray(vetor);

        h = (h - 1) / 3;
    }
}

int main() {
    std::vector<int> numeros = {12, 5, 19, 3, 8, 14, 7, 1, 20, 9, 6, 15, 2, 17, 4, 10, 11, 16, 18, 13};

    std::cout << "Vetor original: ";
    printArray(numeros);

    shellSort(numeros);

    std::cout << "Vetor depois de ordenado: ";
    printArray(numeros);

    return 0;
}
