#include <stdio.h>	

int prime(int a){
	int aux=0, i;
	for (i=1;i<=a;i++){
		if (a%i==0){ 
		 aux++;
		}
	}
	    
	if (aux==2)
		return 1;
	return 0;
}
int lower(int a, int b){
	if(a>b)
		return b;
	if(a<b)
		return a;
}
int higher(int a, int b){
	if(a>b)
		return a;
	if(a<b)
		return b;
}
void primes(int x, int y){
	int i;
	int low=lower(x, y);
	int high=higher(x, y);
	
	for (i=low;i<=high;i++){
			
		if (prime(i)==1){
			printf("%i, ", i);
		}
	}
}
int main(){
	int a, b;
	printf("Enter two numbers:\n");
	scanf("%i %i", &a, &b);
	primes(a, b);
	return 0;
}
