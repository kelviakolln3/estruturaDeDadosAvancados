//Complementar o algoritmo para que ele traga a média e moda dos valores que o usuário digitar.
//Manter a impressão, mas imprimir do primeiro para o último e do último para o primeiro digitado
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
#define TAM 4
using namespace std;
int soma = 0, cont=0, cont1 = 0, cont2 = -1, calModa = 0;
float calMedia = 0;
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
/*void media(Lista *m){
	soma = soma+m->n;
	cont++;	
	media(m->prox);	
}*/
void media(Lista *med){
	while(med){
		soma = soma+ med->n;
		cont++;
		med = med->prox;
	}
	calMedia = soma/cont;
	printf("Media e: %.2f \n", calMedia);
}
void moda(Lista *atual, Lista *prox){
	if(atual->n == prox->n){
		if()
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
		temp = (Lista *)malloc(sizeof(Lista));
		printf("Informe o valor \n");
		scanf("%d", &temp->n);
		temp->prox = 0;
		atual->prox = temp;
		atual = temp;
	}
	imprimir(raiz);
	media(raiz);
	moda(raiz);
	return 0;
}
