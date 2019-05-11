#include <stdio.h>
#include <stdlib.h>

int findWordPart1(char *str, char *palavra){
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
int findWord(char * arquivo, char * palavra){
	FILE *f;
    char str[50];
    int nLines=0;

    f=fopen(arquivo, "r");
    if(f==NULL){return 0;}

    while(fgets(str, 50, f)!=NULL){
        if(findWordPart1(str, palavra)!=-1){
        	return nLines;
        }
        nLines++;
    }
    fclose(f);

    return -1;
}
int main(){
	int pos=findWord("exemplo.txt", "World");
	printf("%i\n", pos);
}