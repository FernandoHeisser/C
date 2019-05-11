#include <stdio.h>

long convertbinary (int n){
	if (n!=0){
		convertbinary(n/2);
		printf("%i", n%2);
	}
	return 0;
}

int main(){
	int num;
	scanf("%i", &num);
	convertbinary(num);
	return 0;
}
