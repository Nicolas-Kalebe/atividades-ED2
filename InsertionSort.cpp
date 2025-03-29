#include <iostream>
//Nome: Nícolas Kalebe Gualberto Fidelis
//Matricula: 202302573
int main() {
    int vetor[5]={1,3,4,5,2};
    int aux,j;

    int tamanho = std::size(vetor);

    for(int i=1;i<tamanho;i++) {
        aux = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>aux) {
            vetor[j+1]=vetor[j];
            j = j-1;
        }
        vetor[j+1]=aux;

    }
    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}
