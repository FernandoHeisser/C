#include <stdio.h>
#include <stdlib.h>

int j=0;
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
int * generateArray(int size){
    int i;
    int *array = malloc( sizeof(int) * size );
    if(array==NULL)
        return NULL;
    for(i=0;i<size;i++)
        *(array+i)=i+1;
    return array;
}
int * biggerThanArray(int * array, int num, int size){	
	int *sub;
	int i;
	sub=malloc(sizeof(int) * i+1);
	if(sub==NULL)
		return NULL;

	for (i=0;i<size;i++){
		if(*(array+i)>num){
			*(sub+j)=*(array+i);
			j++;
			sub=realloc(sub, sizeof(int)*j);
		}
	}
	

	return sub;
}
int main(){
	int *array1;
	int *array2;

	array1=generateArray(10);

	printArray(array1, 10);

	array2=biggerThanArray(array1, 5, 10);

	printArray(array2, j);

	free(array1);
	free(array2);	
	return 0;
}
