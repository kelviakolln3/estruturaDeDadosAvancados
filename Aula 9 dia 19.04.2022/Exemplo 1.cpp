#include <bits/stdc++.h>
struct arvore{
	int num; //valor a ser inserido
	arvore *dir, *esq;
};
arvore * criaArvore(int); //prototipação de função
arvore * cria_No();
void pEsq(arvore *, int);//cria nó esquerda
void pDir(arvore *, int);//cria nó direita
void recursiva(arvore *);//Percorrer a arvore e imprimir os nos
void buscaArvore(arvore *, int);
void fazerBuscaArvore(arvore *, int);
void media(arvore *, int);
int soma = 0, cont = 1;
int lerValor(){
	int x;
	printf("Digite um valor \n");
	scanf("%d", &x);
	return x;
}
int main(){
	arvore *raiz, *p, *q;
	int x = lerValor();
	int j;
	raiz = criaArvore(x);
	while(x != 0){
		p = q = raiz;
		x = lerValor();
		while(x != 0 && x != p->num && q){
			p = q;
			if(x < p->num){
				q = p->esq;
				if(!q){
					pEsq(p,x);
				}
			}else{
				q = p->dir;
				if(!q){
					pDir(p,x);
				}
			}
		}
		if(x==p->num){
			printf("Numero ja existe.\n");
		}
	}
	//recursiva(raiz);
	/*printf("Buscar um elemento na arvore\n");
	printf("Informe um numero para buscar \n");
	scanf("%d", &j);
	buscaArvore(raiz, j);*/
	media(raiz, 0);
	printf("Media %f \n", (soma/cont));
	return 0;
}
arvore * criaArvore(int x){
	arvore *p;
	if((p = (arvore *) malloc(sizeof(arvore))) == NULL){
		return NULL;
	}
	p->num = x;
	p->dir = p->esq = NULL;
	return p;
}
void pEsq(arvore *p, int x){
	arvore * q = criaArvore(x);
	p->esq = q;
}
void pDir(arvore *p, int x){
	arvore * q = criaArvore(x);
	p->dir = q;
}
void recursiva(arvore *p){
	printf("%d\n", p->num);
	if(p->esq){
		recursiva(p->esq);
	}
	if(p->dir){
		recursiva(p->dir);
	}
}
/*void fazerBuscaArvore(arvore *p){
	int j, ret;
	printf("Buscar um elemento na arvore\n");
	printf("Informe um numero para buscar \n");
	scanf("%d", &j);
	ret = buscaArvore(p, j);
	if(ret == 0){
		printf("Deseja buscar outro numero? \n 1-Sim 2-Nao \n");
		scanf("%d", opcao);
		if(opcao == 1)
			fazerBuscaArvore(p)
	}
}*/
/*int*/void buscaArvore(arvore *p, int x){
	if(x== p->num){
		printf("Numero %d esta na arvore \n", x);
		//return 0;
	}else
	if(x < p->num){
		if(p->esq != NULL)
			buscaArvore(p->esq, x);
		else{
			printf("O numero %d nao esta na arvore\n");
			//return 0;
		}
	}else
	if (x > p->num){
		if(p->dir != NULL)
			buscaArvore(p->dir, x);
		else{
			printf("O numero %d nao esta na arvore\n");
			//return 0;
		}
	}
}
void media(arvore *p, int x){
	x += p->num;
	if(p->esq){
		media(p->esq, x);
	}
	if(p->dir){
		media(p->dir, x);
	}
}
