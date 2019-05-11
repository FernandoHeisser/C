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
char * toggleString(char * str){
	int i;
	int size=strlen(str);
	if(*str>='a'&&*str<='z'){
		*str-=32;
	}
	for(i=1;i<size;i++){
		if(*(str+i)==' '){
			if(*(str+i+1)>='a'&&*(str+i+1)<='z'){
				*(str+i+1)-=32;
			}
		}
		if(*(str+i)>='A'&&*(str+i)<='Z'){
			if(*(str+i-1)!=' '){
				*(str+i)+=32;
			}
		}
	}
	return str;
}
int main(){
	char *str1;
	char *str;

	printf("Digite a string:");
	str1=readString();

	str=toggleString(str1);
	printf("\n%s\n", str);

	free(str1);
	free(str);
	return 0;
}

