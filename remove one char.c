#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *ptr1, char *ptr2){
    char temp;
    // Copy the value of num1 to some temp variable
    temp = *ptr1;
    // Copy the value of num2 to num1
    *ptr1= *ptr2;
    // Copy the value of num1 stored in temp to num2
    *ptr2= temp;
}
char * readString(){
    char *pStr = malloc(sizeof(char));
    char c = ' ';
    int i =0;

    if(pStr == NULL)
        return NULL;

    while (( c = getchar() ) != '\n' && pStr != NULL)
    {
        *(pStr+i)=c;
        i++;
        pStr = realloc(pStr, i+1);
    }
    *(pStr+i) = '\0';
    // printf("\nSize: %d Long String value:%s \n\n", i,pStr);
    return pStr;
}
char * removeOneChar(char * str, char letra){
	int i, j, size=strlen(str);
    
    for (i=0;i<size;i++){
        if(*(str+i)==letra){
            swap((str+i), (str+i+1));
        }
    }
	str=realloc(str, sizeof(char)*size-1);
    if(str==NULL)
        return NULL;
	return str;
}
int main(){
	char *str, letra;

	printf("Digite a string:\n");
	str=readString();

    printf("Digite o caracter que deseja remover:\n");
    letra=getchar();

	printf("\n%s\n", str);

    str=removeOneChar(str, letra);

	printf("\n%s\n", str);

    free(str);
    return 0;
}
