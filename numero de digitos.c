#include <stdio.h>

int nOfDigits (int n){
	static int cont=0;
	if (n>0){
		cont++;
		nOfDigits(n/10);
	}
	else{
		printf("%i\n", cont);
	}
	return 0;
}
int main(){
	int num;
	scanf("%i", &num);
	nOfDigits(num);
	return 0;
}
