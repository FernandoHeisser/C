#include <stdio.h>

void EvenAndOdd(int valorpadrao, int n){
	if(valorpadrao==1){
	    if((n>0) && (n%2==0)){
	        printf("%i ", n--);
	        EvenAndOdd(valorpadrao, n);
	    }
	    else{
	    	n--;
	    	EvenAndOdd(valorpadrao, n);
		}
	}
	if(valorpadrao==2){
	    if((n>0) && (n%2!=0)){
	        printf("%i ", n--);
	        EvenAndOdd(valorpadrao, n);
	    }
	    else{
	    	n--;
	    	EvenAndOdd(valorpadrao, n);
		}
	}
	return;
}

int main(){
	int a, b;
	printf("1 - Pares\n2 - Impares\n");
	scanf("%i", &a);
	printf("Digite o numero:");
	scanf("%i", &b);
	EvenAndOdd(a, b);
	return 0;
}
