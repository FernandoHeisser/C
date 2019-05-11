#include <stdio.h>

void printNaturals (int n){
	if(n>=1){
		printf("%i ", n--);
		printNaturals(n);
	}
	return;
}
int main(){
	int num;
	scanf("%i", &num);
	printNaturals(num);
	return 0;
}
