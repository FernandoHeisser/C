#include <stdio.h>

void swap(int *a, int *b);
void swap3v2(int *a, int *b, int *c);

int main(){

	int a=1, b=3, c=5;

	printf("A=%i  B=%i  C=%i\n\n",a, b, c);

	swap3v2(&a, &b, &c);

	printf("A=%i  B=%i  C=%i\n\n",a, b, c);

	return 0;

}

void swap(int *a, int *b){

	int aux;

	aux=(*a);
	(*a)=(*b);
	(*b)=aux;
}

void swap3v2(int *a, int *b, int *c){
	
	swap(a, b);
	swap(a, c);

}