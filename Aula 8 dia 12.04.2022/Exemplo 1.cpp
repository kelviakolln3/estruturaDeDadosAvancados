#include <cstdlib>
#include <cstdio>
#define TAM 3
typedef struct snumero {
	int numerol;
	snumero* Proximo, *Anterior;
} numero;
numero* inserir(numero* anterior) {
    numero * novo = (numero*)malloc(sizeof(numero));
    novo->Proximo = NULL;
    novo->Anterior = NULL;
    printf("Digite um número\n");
    scanf("%d", &novo->numerol);
    if (anterior == NULL)
        return novo;
    else {
        novo->Anterior = anterior;
        anterior->Proximo = novo;
    }
    return novo;
}
void imprime(numero *atual){
    if(atual){
        printf("\t %d",atual->numerol);
        imprime(atual->Proximo);
    }
}
numero * fmaior(numero *atual, numero *maior){
    if(maior->numerol < atual->numerol){
        maior = atual;
    }
    if(atual->Proximo == NULL){
        return maior;
    }
    maior = fmaior(atual->Proximo, maior);
    return maior;
}
void imp(numero *elemento){
    if(elemento)
        printf("\n\t%d",elemento->numerol);
}
int main() {
    numero* raiz=NULL, *atual=NULL, *maior;
    int i=0;
    raiz = inserir(NULL);
    atual = raiz;
    for(;i<TAM;i++){
        atual = inserir(atual);
    }
    imprime(raiz);
    maior = fmaior(raiz, raiz);
    imp(maior->Anterior);
    imp(maior->Proximo);
	return 0;
}
