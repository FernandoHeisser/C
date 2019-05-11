#include <stdio.h>

int _V1, _V2;

int sum(int a, int b){
	return a+b;
}
int multi(int a, int b){
	return a*b;
}

int main(){
	printf("Enter two numbers:\n");
	scanf("%i %i", &_V1, &_V2);
	printf("%i\n", sum(_V1, _V2));
	printf("%i\n", multi(_V1, _V2));
}
