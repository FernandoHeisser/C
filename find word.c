#include <stdio.h>
#include <string.h>

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
int main(){
	char str[50], palavra[50];
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a palavra:\n");
	gets(palavra);
	int res=findWord(str, palavra);
	printf("'%s' encontrada na posicao %i da str '%s'.", palavra, res, str);
	

	return 0;
}
