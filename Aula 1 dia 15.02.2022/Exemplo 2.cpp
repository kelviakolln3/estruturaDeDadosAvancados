#include <iostream>
using namespace std;
void soma(int *z, int i){
	*z = *z + i;
}
void soma1(void *z, int i){ //Criação do ponteiro nulo
	*(int*)z = /*Casting*/ *(int*)z + i;
}
int main(){
	int x = 10;
	int i = 11;
	char s = 's';
	i = (int) s;//Cast de char para inteiro
	int *ptr; //->Ponteiro
	
	ptr = &x;//Vai atribuir ao ponteiro o endereço de memoria da variavel x
	*ptr = 20; //Tudo o que acontecer com o ponteiro vai acontecer com a variavel e vice versa
	soma(ptr, i);
	soma1(ptr, i);
	cout << *ptr << endl;
	cout << x << endl;
	cout << &x << endl;
	return 0;
}
