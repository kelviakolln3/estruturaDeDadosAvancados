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
Lista *ordenacao(Lista *raiz){
    int aux;
    Lista *i;
    Lista *j;
    if(raiz == NULL || raiz->prox == NULL){
        return NULL;
    }
    for(i = raiz;i != NULL; i= i->prox){
        for(j = i->prox;j != NULL;j =j->prox){
            if(i->n > j->n){
                aux = i->n;
				i->n = j->n;
                j->n = aux;
            }
        }
    }
    return raiz;
}
int main(){
    Lista *raiz, *atual, *temp;
    raiz = (Lista *)malloc(sizeof(Lista));
    printf("Um numero para a raiz \n");
    scanf("%d",&raiz->n);
    raiz->prox = 0;
    atual = raiz;
    for(int i=0; i<TAM;i++){
        temp = (Lista *)malloc(sizeof(Lista));
        atual->prox = temp;
        printf("Digite um valor\n");
            scanf("%d",&temp->n);
        temp->prox = 0;
        atual = temp;
    }
    
    imprimir(raiz);
    printf("Ordenacao\n");
    raiz = ordenacao(raiz);
    imprimir(raiz);
}
