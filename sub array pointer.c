#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size){
    int i;
    printf("Array: ");
    for (i=0;i<size;i++){
    	if(i<size-1)
        	printf("%d, ", *(array + i));
        if(i==size-1)
        	printf("%d. ", *(array + i));
    }
    printf("\n\n");
}
int * generateArray(int size){
    int i;
    int *array = malloc( sizeof(int) * size );
    if(array==NULL)
			return NULL;
    for(i=0;i<size;i++)
        *(array+i)=i+1;
    return array;
}
int * subArray(int * array, int size, int begin, int end){
	if(end<=begin || size!=(end-begin+1)){
		return NULL;
	}
	else{	
		int *sub;
		int i;
		sub=malloc(sizeof(int) * size);
		if(sub==NULL)
			return NULL;
		for (i=begin;i<=end;i++){
			*(sub+i-begin)=*(array+i);
		}
		return sub;
	}
}
int main(){
	int *array1;
	int *array2;

	array1=generateArray(10);

	printArray(array1, 10);

	array2=subArray(array1, 4, 4, 7);

	printArray(array2, 4);

	free(array1);
	free(array2);
	return 0;
}