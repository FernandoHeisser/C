#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
char * copyString(char * str1){
	char *copy;
	copy=malloc(sizeof(char)*strlen(str1));
    if(copy==NULL)
        return NULL;
	strcpy(copy, str1);
	return copy;
}
int main(){
	char *str1;
	char *str;

	printf("Digite a primeira string:");
	str1=readString();

	str=copyString(str1);

	printf("\n%s\n", str);

	free(str1);
	free(str);
	return 0;
}
