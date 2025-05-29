//Nome: Nicolas Kalebe - Matricula: 202302573
//Nome: Abner Gabriel - Matricula: 202302517
//codigo feito em C++20
#include <iostream>
#define COUNT 10

typedef struct no {
    int valor;
    struct no *esquerdo, *direito;
    int altura;
}No;

No* novoNo(int x) {
    No *novo = new No;

    if(novo) {
        novo->valor = x;
        novo -> esquerdo = nullptr;
        novo -> direito = nullptr;
        novo -> altura = 0;
    }
    else std::cout << "\nErro ao alocar memoria\n";
    return novo;
}

int maior(int a, int b) {
    return a > b ? a : b;
}

int alturaDoNo(No *no) {
    if(no==nullptr) return -1;
    else return no -> altura;
}
int fatorDeBalanceamento(No *no) {
    if(no)
        return alturaDoNo(no->direito) - alturaDoNo(no->esquerdo);
    else
        return 0;
}
No* rotacaoEsquerda(No* p) {
    No* q = p->direito;
    No* temp = q->esquerdo;

    q->esquerdo = p;
    p->direito = temp;

    p->altura = 1 + maior(alturaDoNo(p->esquerdo), alturaDoNo(p->direito));
    q->altura = 1 + maior(alturaDoNo(q->esquerdo), alturaDoNo(q->direito));

    return q;
}

No* rotacaoDireita(No* p) {
    No* q = p->esquerdo;
    No* temp = q->direito;

    q->direito = p;
    p->esquerdo = temp;

    p->altura = 1 + maior(alturaDoNo(p->esquerdo), alturaDoNo(p->direito));
    q->altura = 1 + maior(alturaDoNo(q->esquerdo), alturaDoNo(q->direito));

    return q;
}

No* rotacaoDuplaEsquerda(No* p) {
    p->direito = rotacaoDireita(p->direito);
    return rotacaoEsquerda(p);
}

No* rotacaoDuplaDireita(No* p) {
    p->esquerdo = rotacaoEsquerda(p->esquerdo);
    return rotacaoDireita(p);
}

No* balancear(No* p) {
    int fb = fatorDeBalanceamento(p);

    if (fb > 1 && fatorDeBalanceamento(p->direito) >= 0)
        return rotacaoEsquerda(p);

    if (fb > 1 && fatorDeBalanceamento(p->direito) < 0)
        return rotacaoDuplaEsquerda(p);

    if (fb < -1 && fatorDeBalanceamento(p->esquerdo) <= 0)
        return rotacaoDireita(p);

    if (fb < -1 && fatorDeBalanceamento(p->esquerdo) > 0)
        return rotacaoDuplaDireita(p);

    return p;
}

No* inserir(No* p, int x) {
    if (p == nullptr)
        return novoNo(x);

    if (x < p->valor)
        p->esquerdo = inserir(p->esquerdo, x);
    else if (x > p->valor)
        p->direito = inserir(p->direito, x);
    else {
        std::cout << "Erro ao inserir, o elemento " << x << " já existe\n";
        return p;
    }

    p->altura = 1 + maior(alturaDoNo(p->direito), alturaDoNo(p->esquerdo));
    return balancear(p);
}


void emOrdem(No* raiz) {
    if (raiz != nullptr) {
        emOrdem(raiz->esquerdo);
        std::cout << raiz->valor << " ";
        emOrdem(raiz->direito);
    }
}

void constroiAVL(No* raiz, int space) {
    if (raiz == NULL)
        return;

    space += COUNT;

    constroiAVL(raiz->direito, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", raiz->valor);

    constroiAVL(raiz->esquerdo, space);
}

int main() {
    No* raiz = nullptr;

    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 10);

    std::cout << "Em ordem: ";
    emOrdem(raiz);
    std::cout << std::endl;
    printf("\n");
    
    std::cout << "A visualização dos nós: ";
    constroiAVL(raiz, 0);

    return 0;
}
