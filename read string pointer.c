#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * catString(char * str1, char * str2){
	int i, size=strlen(str1)+strlen(str2);
	char *str;
	str=malloc(sizeof(char)*size);
	str=strcat(str1, str2);
	return str;
}
char * readString(){
    char *pStr = malloc(sizeof(char));
    char c=' ';
    int i=0;

    if(pStr == NULL)
        return NULL;

    while (( c = getchar() ) != '\n' && pStr != NULL)
    {
        *(pStr+i)=c;
        i++;
        pStr = realloc(pStr, i+1);
    }
    *(pStr+i) = '\0';
    //printf("\nSize: %d Long String value:%s \n\n", i,pStr);
    return pStr;
}
int main(){
	char *strA=malloc(sizeof(char));
	if(strA==NULL)
        return NULL;
	char *strB=malloc(sizeof(char));
	if(strB==NULL)
        return NULL;
	char *str;

	printf("Digite a primeira string:");
	strA=readString();
	
	printf("\nDigite a segunda string:");
	strB=readString();

	str=catString(strA, strB);

	printf("\n%s\n", str);

	free(strA);
	free(strB);
	free(str);
	return 0;
}
