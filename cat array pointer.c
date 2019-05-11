#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size){
    int i;
    static int cont=1;
    printf("Array%i: ", cont);
    for (i=0;i<size;i++){
    	if(i<size-1)
        	printf("%d, ", *(array + i));
        if(i==size-1)
        	printf("%d. ", *(array + i));
    }
    printf("\n\n");
    cont++;
}
int * catArray(int * array1, int size1, int * array2, int size2){
	int i, size=size1+size2;
	int *cat;
	cat=malloc(sizeof(int)*size);
	if(cat==NULL)
		return NULL;

	for (i=0;i<size1;i++){
		*(cat+i)=*(array1+i);
	}
	for (i=0;i<size2;i++){
		*(cat+i+size1)=*(array2+i);
	}
	return cat;
}
int main(){
	int *array1;
	int *array2;
	int *array;
	array1=malloc(sizeof(int)*3);
	if(array1==NULL)
        return NULL;
	array2=malloc(sizeof(int)*3);
	if(array2==NULL)
        return NULL;

	*(array1+0)=1;
	*(array1+1)=2;
	*(array1+2)=3;

	*(array2+0)=777;
	*(array2+1)=888;
	*(array2+2)=999;

	printArray(array1, 3);
	printArray(array2, 3);

	array=catArray(array2, 3, array1, 3);

	printArray(array, 6);

	free(array1);
	free(array2);
	free(array);

	return 0;
}
