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
int * copyarray(int *array, int size){
	int *copy;
	int i;
	copy=malloc(sizeof(int)*size);
	if(copy==NULL)
		return NULL;
	for(i=0;i<size;i++){
		*(copy+i)=*(array+i);
	}
	return copy;
}
int main(){
	int *array1;
	int *array2;

	array1=generateArray(5);

	printArray(array1, 5);

	array2=copyarray(array1, 5);

	printArray(array2, 5);

	free(array1);
	free(array2);
	return 0;
}