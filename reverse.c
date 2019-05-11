#include <stdio.h>

int reverse (int n){
	if (n!=0){
		printf("%i", n%10);
		reverse(n/10);
	}
	return 0;
}

int main(){
	int num;
	scanf("%i", &num);
	reverse(num);
	return 0;
}
