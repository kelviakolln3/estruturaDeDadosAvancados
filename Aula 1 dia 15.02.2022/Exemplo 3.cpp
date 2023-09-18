#include <iostream>
using namespace std;
//Desenvolva um algoritmo que crie um vetor de 5 posições no main e passe como parâmetro para uma função
//que o receba e insira valores no vetor, depois no main inmpima os valores
//Obs: não usar return
void leitura(int *z){//Recebe vetor como ponteiro
	int i = 0;
	while(i<5){
		scanf("%d",z);//Lê valores e insere no vetor O z serve para subistituir o vet[0], vet[1]...
		z++;//Incrementa índice de memória
		i++;//Incrementa índice de controle
	}
}
int main(){
	int vet[5];
	leitura(vet);//Passa primeira posição do vetor para a função como ponteiro
	
	for(int i = 0; i < 5; i++){
		printf("%d", vet[i]);
	}
	return 0;
}
