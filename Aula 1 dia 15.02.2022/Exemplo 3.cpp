#include <iostream>
using namespace std;
//Desenvolva um algoritmo que crie um vetor de 5 posi��es no main e passe como par�metro para uma fun��o
//que o receba e insira valores no vetor, depois no main inmpima os valores
//Obs: n�o usar return
void leitura(int *z){//Recebe vetor como ponteiro
	int i = 0;
	while(i<5){
		scanf("%d",z);//L� valores e insere no vetor O z serve para subistituir o vet[0], vet[1]...
		z++;//Incrementa �ndice de mem�ria
		i++;//Incrementa �ndice de controle
	}
}
int main(){
	int vet[5];
	leitura(vet);//Passa primeira posi��o do vetor para a fun��o como ponteiro
	
	for(int i = 0; i < 5; i++){
		printf("%d", vet[i]);
	}
	return 0;
}
