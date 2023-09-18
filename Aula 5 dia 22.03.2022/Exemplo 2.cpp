#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
#define TAM 4
using namespace std;
typedef struct strLista{
	int n;
	strLista *prox;//Faz referência do tipo
} Lista;
void imprimir(Lista *l){
	if(l != NULL){
		printf("Numero: %d \n", l->n);
		imprimir(l->prox);
	}
}
int main(){
	Lista *raiz;//Saber qual é o primeiro elemento. Se perder ele, perde tudo.
	Lista *atual;//Para criar elementos novos
	Lista *temp;
	
	raiz = (Lista *)malloc(sizeof(Lista));//Locando memoria. Criei um espaço de memoria com o tamanho da lista
	raiz->n = 10;
	raiz->prox = 0;
	atual = raiz;
	
	for(int i = 0; i < TAM;i++){
		temp = new Lista;
		temp = (Lista *)malloc(sizeof(Lista));
		temp->n = atual->n+1;
		temp->prox = 0;
		atual->prox = temp;
		atual = temp;
	}
	imprimir(raiz);
	return 0;
}
