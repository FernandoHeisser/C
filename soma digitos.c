#include <stdio.h>

int Digitsum (int n){
	static int soma=0;
	if (n>0){
		soma+=n%10;
		Digitsum(n/10);
	}
	else{
		printf("%i\n", soma);
	}
	return 0;
}
int main(){
	int num;
	scanf("%i", &num);
	Digitsum(num);
	return 0;
}
