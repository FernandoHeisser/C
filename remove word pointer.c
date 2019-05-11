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
void swapChar(char *a, char *b){
	char aux;
	aux=*(a);
	*(a)=*(b);
	*(b)=aux;
}
void removeChar(char *str, char letra, int pos_inicial, int pos_final){
	int i, j;
	for (i=pos_inicial;i<pos_final;i++){
		if(*(str+i)==letra){
			swapChar((str+i), (str+i+1));
		}
	}
}
int findWord(char *str, char *palavra){
	int i=0, inicio;
	int ts=strlen(str);
	int tp=strlen(palavra);

	while(i<ts){

		if( *(str+i)==*(palavra) && *(str+i+tp-1)==*(palavra+tp-1) ){

			inicio=i;
			break;

		}
		else{
			inicio=-1;
		}
		i++;
	}
	return inicio;
}
void removeWordPart1(char *str, char *palavra){
 	int local=findWord(str, palavra);
 	int i=0;
 	int ts=strlen(str);
	int tp=strlen(palavra);

 	while(i<tp){

 		if( *(str+local) == *(palavra+i) ){
 			removeChar( str, *(str+local), local, ts );
 		}
 		else if(*str == *(palavra+i)){
 			removeChar( str, *(str+local), local, ts );
 		}
 		i++;
 	}
}
char * removeWord(char * str, char * word){
	int i=0, ts=strlen(str), tp=strlen(word);
	while(i<ts){
		removeWordPart1(str, word);
		i++;
	}
	str=realloc(str, sizeof(char)*(ts-tp));
	return str;
}
int main(){
	char *str, *word;

	printf("Digite a string:\n");
	str=readString();

    printf("Digite a palavra:\n");
	word=readString();

    str=removeWord(str, word);

	printf("\n%s\n", str);

    free(str);
    free(word);
    return 0;
}
