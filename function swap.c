#include <stdio.h>

void swap3v2(int *a, int *b, int *c);

int main(){

	int a=1, b=3, c=5;

	printf("A=%i  B=%i  C=%i\n\n",a, b, c);

	swap3v2(&a, &b, &c);

	printf("A=%i  B=%i  C=%i\n\n",a, b, c);

	return 0;

}

void swap3v2(int *a, int *b, int *c){
	
	int aux1, aux2;

	aux1=(*a);
	aux2=(*b);

	(*a)=(*c);
	(*b)=aux1;
	(*c)=aux2;

}
