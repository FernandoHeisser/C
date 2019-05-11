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
    for(i=0;i<size;i++)
        *(array+i)=i+1;
    return array;
}
int * removeDuplicates(int * array, int size){
    int i, j, k, x=0;
    while(x<size){
        for(i=0;i<size;i++){
            for(j=i+1;j<size;j++){
                if(*(array+i)==*(array+j)){
                    for(k=j;k<size;k++){
                        swap((array+k), (array+k+1));
                    }
                }
            }
        }
        i=0;
        x++;
    }
    array=realloc(array, sizeof(int)*10);
    if(array==NULL)
        return NULL;
    return array;
}
int main(){
	int *array1;
	int *array2;

	array1=generateArray(10);
    *(array1+0)=1;
    *(array1+1)=1;
    *(array1+2)=1;
    *(array1+3)=2;
    *(array1+4)=3;
    *(array1+5)=1;
    *(array1+6)=1;
    *(array1+7)=1;
    *(array1+8)=2;
    *(array1+9)=3;

    printArray(array1, 10);

    array2=removeDuplicates(array1, 10);

	printArray(array2, 3);

    free(array1);
    free(array2);
	return 0;
}
