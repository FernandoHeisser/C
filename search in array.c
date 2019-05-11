#include <stdio.h>

int searchinArray(int *vet, int tam, int num);

int main(){

	int vet[]={1, 2, 3, 4, 5};
	int i, num;

	printf("Vetor=");
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

	printf("\n\nProcurar valor:");
	scanf("%i", &num);

	if(searchinArray(vet, 5, num)==1){
		printf("Valor encontrado.\n");
	}
	if(searchinArray(vet, 5, num)==0){
		printf("Valor nao encontrado.\n");
	}
	

	return 0;

}

int searchinArray(int *vet, int tam, int num){

	int i, cont=0;
	
	for (i=0;i<tam;i++){
		if(*(vet+i)==num)
			cont++;
	}

	if(cont>0)
		return 1;
	return 0;

}
