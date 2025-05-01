//Atividade feita por Abner Gabriel e Nicolas Kalebe
#include<stdio.h>
#include<stdlib.h>

int Busca(int* Vetor, int elem, int tam)
{
    for (int i = 0; i < tam; i++) {
        if (Vetor[i] == elem) {
            return i;
        }
    }
    
    return -1;
}

int main(){
    int Vetor[] = {0, 2, 3, 26, 12, 13, 15, 30, 19, 26};
    int x;
    int tamanho = sizeof(Vetor)/sizeof(Vetor[0]);
    
    printf("Digite o número a ser procurado: ");
    scanf("%d", &x);
    
    int Posicao = Busca(Vetor, x, tamanho);
    int Elemento = Vetor[Posicao];
    
    if (Posicao != -1){
        printf("O elemento procurado é: %d \n", Elemento);
        printf("O elemento procurado está na posição: %d\n", Posicao + 1);
    }
    else
        printf("Elemento não encontrado.\n");
        
    return 0;
}