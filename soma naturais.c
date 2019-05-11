#include <stdio.h>

int sumNaturals (int n){
	static int aux=0;
	if(n>0){
		aux+=n%10;
		sumNaturals(--n);
	}else{
		printf("%i", aux);
	}
	return 0;
}
int main(){
	int num;
	scanf("%i", &num);
	sumNaturals(num);
	return 0;
}
