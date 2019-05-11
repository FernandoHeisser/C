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
void insertWord(char * arr, char * word, int pos){
	if(pos>0){    
	    int i;
	    char substr1[20], substr2[20];
	    for(i=0; i<pos; i++){
	        *(substr1+i) = *(arr+i);
	    }
	    *(substr1+pos) = '\0';

	    for(i=pos; i<strlen(arr); i++){
	        *(substr2+i-pos) = *(arr+i);
	    }
	    *(substr2+strlen(arr)-pos) = '\0';
	    //concatena tudo
	    strcat(substr1, word);
	    strcat(substr1, substr2);
	    strcpy(arr, substr1);
	}
	else if(pos==0){
		char *aux = malloc(sizeof(char));
		if(aux==NULL){return NULL;}
		int i=0, tp=strlen(word);
		while(i<tp && aux!=NULL){
			*(aux+i)=*(word+i);
			i++;
        	aux=realloc(aux, i+1);
		}
		strcat(aux, arr);
		strcpy(arr, aux);
	}
}
char * replaceWord(char * str, char * word1, char * word2){
	int ts=strlen(str), pos;
	int tp1=strlen(word1), tp2=strlen(word2);;
	while(findWord(str, word1)!=-1){
		pos=findWord(str, word1);
		removeWordPart1(str, word1);
		//printf("%i\n", pos);
		insertWord(str, word2, pos);
	}
	return str;
}
int main(){
	char *str, *word1, *word2;

	printf("Digite a string:\n");
	str=readString();

    printf("Digite a palavra a ser tirada:\n");
	word1=readString();

	printf("Digite a nova palavra:\n");
	word2=readString();

    str=replaceWord(str, word1, word2);

	printf("\n%s\n", str);

    free(str);
    free(word1);
    free(word2);
    return 0;
}
