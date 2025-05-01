//Atividade feita por Abner Gabriel e Nicolas Kalebe 
#include <stdio.h>
#include <stdlib.h>

int BuscaIterativa(int* Vetor, int chave, int fim) {
	int inicio = 0;

	while(inicio <= fim) {

		int meio = (inicio + fim)/2;

		if(chave == Vetor[meio])
			return meio;

		else if(chave < Vetor[meio])
			fim = meio - 1;
		else
			inicio = meio + 1;
	}
	return -1;
}

int main() {
	int Vetor[] = {0, 1, 4, 6, 7, 8, 10, 12};
	int x;
	int tamanho = sizeof(Vetor)/sizeof(Vetor[0]);

	printf("Digite o número a ser procurado: ");
	scanf("%d", &x);

	int Posicao = BuscaIterativa(Vetor, x, tamanho - 1);
	int Elemento = Vetor[Posicao];

	if (Posicao != -1) {
		printf("O elemento procurado é: %d \n", Elemento);
		printf("O elemento procurado está na posição: %d\n", Posicao + 1);
	}
	else
		printf("Elemento não encontrado.\n");

	return 0;
}