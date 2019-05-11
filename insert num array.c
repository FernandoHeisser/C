#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr1, int *ptr2){
    int temp;
    // Copy the value of num1 to some temp variable
    temp = *ptr1;
    // Copy the value of num2 to num1
    *ptr1= *ptr2;
    // Copy the value of num1 stored in temp to num2
    *ptr2= temp;
}
void printArray(int *array, int size){
    int i;
    static cont=1;
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
    for(i=0;i<size;i++)
        *(array+i)=i+1;
    return array;
}
int * insertNumArray(int * array, int num, int pos, int size){
    int i;
    array=realloc(array, sizeof(int)*size+1);
    if(array==NULL)
        return NULL;
    swap(&num, (array+pos));
    for(i=pos+1;i<=size;i++){
        swap(&num, (array+i));
    }
    return array;
}
int main(){
	int *array1;
	int *array2;

	array1=generateArray(10);

    printArray(array1, 10);

    array2=insertNumArray(array1, 999, 7, 10);

	printArray(array2, 11);

    free(array1);
    free(array2);
	return 0;
}
