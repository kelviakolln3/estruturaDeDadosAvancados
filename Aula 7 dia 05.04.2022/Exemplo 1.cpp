#include <stdio.h>
#include <cstdlib>
#define TAM 4
typedef struct strLista{
    int n;
    strLista *prox;
} Lista;
void imprimir(Lista *l){
    if(l){
        printf("numero %d\n",l->n);
        imprimir(l->prox);
    }
}
Lista *ordena(Lista *raiz){
	Lista *_atual = raiz;
	Lista *_prox;	
	Lista *_aux;
	Lista *_anterior;
	if(raiz == NULL /*|| raiz->prox == NULL*/) //Perde a raiz se não existir o proximo porque atribuo null a raiz
		return NULL; 
		
	while(_atual != NULL){
		_prox = _atual->prox;
		while(_prox != NULL){//Enquanto tiver proximo
			if(_atual->n > _prox->n){
				if(_atual == raiz){
					raiz = _atual->prox;
				}
				//_aux = _prox;
				_atual->prox = _prox->prox;
				_prox->prox = _atual;
				if(_anterior)
					_anterior->prox = _prox;
				_prox = _atual;
				_atual = _aux;
			}
			_anterior = _atual;
			_prox = _prox->prox;
		}
		_atual = _atual->prox;
	}
	return raiz;	
}
int main(){
    Lista *raiz, *atual, *temp;
    raiz = (Lista *)malloc(sizeof(Lista));
    printf("Digite um valor para raiz \n");
    scanf("%d", &raiz->n);
    raiz->prox = 0;
    atual = raiz;
    for(int i=0; i<TAM;i++){
        temp = (Lista *)malloc(sizeof(Lista));
        atual->prox = temp;
        printf("Digite um valor \n");
        scanf("%d", &temp->n);
        temp->prox = 0;
        atual = temp;
    }
    imprimir(raiz);
    printf("Ordenacao \n");
	raiz = ordena(raiz);
	imprimir(raiz);
}
