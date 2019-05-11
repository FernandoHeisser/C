#include <stdio.h>
#include <stdlib.h>

int * readArrayFromUser(){
	int *array, i=0, aux=1;
	array=malloc(sizeof(int));
	if(array==NULL){return NULL;}
	do{
		printf("Digite um numero:");
		scanf("%i", &aux);
		*(array+i)=aux;
		i++;
		array=realloc(array, sizeof(int)*(i+1));
	}while(aux!=0);
	*(array+i)=i;
	return array;
}
int main(){
	int *array;
	array=readArrayFromUser();
	return 0;
}