#include <stdio.h>


void copyArray(int *vetA, int *vetB, int tam);


int main(){

	int vetA[]={1, 2, 3, 4, 5};
	int vetB[]={0, 0, 0, 0, 0};
	int i;

	printf("Vetor A=");
	for(i=0;i<5;i++){
		if(i==0){
			printf("[%i,", vetA[i]);
		}
		if(i>0 && i<4){
			printf("%i,", vetA[i]);
		}
		if(i==4){
			printf("%i]", vetA[i]);
		}
	}

	printf("\n\nVetor B=");
	for(i=0;i<5;i++){
		if(i==0){
			printf("[%i,", vetB[i]);
		}
		if(i>0 && i<4){
			printf("%i,", vetB[i]);
		}
		if(i==4){
			printf("%i]", vetB[i]);
		}
	}

	copyArray(vetA, vetB, 5);

	printf("\n\nVetor A=");
	for(i=0;i<5;i++){
		if(i==0){
			printf("[%i,", vetA[i]);
		}
		if(i>0 && i<4){
			printf("%i,", vetA[i]);
		}
		if(i==4){
			printf("%i]", vetA[i]);
		}
	}

	printf("\n\nVetor B=");
	for(i=0;i<5;i++){
		if(i==0){
			printf("[%i,", vetB[i]);
		}
		if(i>0 && i<4){
			printf("%i,", vetB[i]);
		}
		if(i==4){
			printf("%i]", vetB[i]);
		}
	}

	return 0;

}

void copyArray(int *vetA, int *vetB, int tam){

	int i;

	for (i=0;i<tam;i++){
		*(vetB+i)=*(vetA+i);
	}


}
