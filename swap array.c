#include <stdio.h>

void swapArray(int *vetA, int *vetB, int tam);
void swap(int *a, int *b);

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

	swapArray(vetA, vetB, 5);

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
void swap(int *a, int *b){
	int aux;
	aux=(*a);
	(*a)=(*b);
	(*b)=aux;
}
void swapArray(int *vetA, int *vetB, int tam){

	int i;

	for (i=0;i<tam;i++){
		swap( (vetA+i) , (vetB+i) );
	}


}
