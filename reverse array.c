#include <stdio.h>

void reverseArray(int *vet, int tam);

int main(){

	int vet[]={1, 2, 3, 4, 5};
	int i;

	printf("Vetor Antes=");
	for(i=0;i<5;i++){
		if(i==0){
			printf("[%i,", vet[i]);
		}
		if(i>0 && i<4){
			printf("%i,", vet[i]);
		}
		if(i==4){
			printf("%i]", vet[i]);
		}
	}

	reverseArray(vet, 5);

	printf("\n\nVetor Depois=");
	for(i=0;i<5;i++){
		if(i==0){
			printf("[%i,", vet[i]);
		}
		if(i>0 && i<4){
			printf("%i,", vet[i]);
		}
		if(i==4){
			printf("%i]", vet[i]);
		}
	}

	return 0;

}

void reverseArray(int *vet, int tam){

	int i, aux[tam], x=tam-1;

	for (i=0;i<tam;i++){
		aux[i]=*(vet+x);
		x--;
	}
	for (i=0;i<tam;i++){
		*(vet+i)=aux[i];
	}

}