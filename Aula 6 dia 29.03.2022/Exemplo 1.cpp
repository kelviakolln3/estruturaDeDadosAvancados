#include <stdio.h>
#include <cstdlib>
#define TAM 4
int qtde=0, qtde2=0, valor, valor2;
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
	int aux;
	if(raiz == NULL || raiz->prox == NULL)
		return NULL;
		
	while(_atual != NULL){
		_prox = _atual->prox;
		while(_prox != NULL){
			if(_atual->n > _prox->n){
				aux = _atual->n;
				_atual->n = _prox->n;
				_prox->n = aux;
			}
			_prox = _prox->prox;
		}
		_atual = _atual->prox;
	}
	return raiz;	
}
/*void moda(Lista * atual, Lista * prox){
    if(atual->n == prox->n){
        if(valor == atual->n){
            qtde++;
        } else if(valor2 == atual->n) {
            qtde2++;
            if(qtde<qtde2){
                valor = atual->n;
                qtde = qtde2;
            }
        }
    }
}*/
int main(){
    int total=0;
    Lista *raiz, *atual, *temp;
    raiz = (Lista *)malloc(sizeof(Lista));
    printf("Digite um valor para raiz \n");
    scanf("%d", &raiz->n);
    total += raiz->n;
    raiz->prox = 0;
    atual = raiz;
    for(int i=0; i<TAM;i++){
        temp = (Lista *)malloc(sizeof(Lista));
        atual->prox = temp;
        printf("Digite um valor \n");
        scanf("%d", &temp->n);
        total = total + temp->n;
        temp->prox = 0;
        atual = temp;
    }
    float media = (float)total/TAM+1;
    imprimir(raiz);
    printf("Ordenacao \n");
	raiz = ordena(raiz);
	imprimir(raiz);
    //valor = raiz->n;
    //moda(raiz, raiz->prox);
}
