#include <iostream>
using namespace std;

//Nome: Nícolas Kalebe Gualberto Fidelis
//Matricula: 202302573

void bubbleSort(int arr[], int n) {
    bool trocou;

    for (int i = 0; i < n - 1; i++) {
        trocou = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = true;
            }
        }

        if (!trocou)
            break;
    }
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Antes:\n";
    imprimirArray(vetor, tamanho);

    bubbleSort(vetor, tamanho);

    cout << "Depois:\n";
    imprimirArray(vetor, tamanho);

    return 0;
}
