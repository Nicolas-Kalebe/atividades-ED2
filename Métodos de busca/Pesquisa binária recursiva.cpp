#include <iostream>

int PesquisaBinariaRecursiva (int *vet, int inicio, int fim, int chave) {
    int meio;
    if(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(vet[meio]==chave) {
            return meio;
        }if (vet[meio]<chave) {
            return PesquisaBinariaRecursiva(vet, meio+1, fim, chave);
        }else{
            return PesquisaBinariaRecursiva(vet, inicio, meio-1, chave);
        };
    } return -1;
}


int main() {
    int vet[6]={4,7,8,9,11,12};
    int inicio=0, fim=5;
    int chave;
    std::cout << "Selecione o número a ser procurado." << std::endl;
    std::cin >> chave;
    int pos = PesquisaBinariaRecursiva(vet, inicio, fim, chave);
    if (pos == -1) {
        std::cout << "Não encontrado." << std::endl;
    } else {
        std::cout << "Está na posição " << pos <<" do Vetor." << std::endl;
    }
    return 0;
}
