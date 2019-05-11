#include <stdio.h>
#include <string.h>

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
void removeWord(char *str, char *palavra){
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
int main(){
	char str[50], palavra[50];
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a palavra que deseja remover:\n");
	gets(palavra);
	printf("Removendo '%s' de '%s'\n", palavra, str);
	removeWord(str, palavra);
	printf("Resultado: '%s'.", str);
	

	return 0;
}
