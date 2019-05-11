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
void copyChar(char *a, char *b){
	*(a)=*(b);



	//sla	
}
void insertWord(char *str, char *palavra, int pos){
	char aux1[50];
	char aux2[50];
	int i;
	for (i=0;i<pos;i++){
		*(aux1+i)=*(str+i);
	}
	for (i=pos;i<strlen(str);i++){
		*(aux2+i-pos)=*(str+i);	
	}
	strcat(aux1, palavra);
	strcat(aux1, aux2);
	strcpy(str, aux1);
}
void replaceWord(char *str, char *palavra, char *palavra2){
	int i, j, k, l;
	int ts=strlen(str);
	int tp=strlen(palavra);
	
	if (*(str)==*(palavra)){
		if (*(str+tp-1)==*(palavra+tp-1)){	
			removeWord(str, palavra);
			insertWord(str, palavra2, 0);
			return;
		}
	}
	for (i=1;i<ts;i++){
		if (*(str+i)==*(palavra)){
			for(j=0;j<tp;j++){
				if (*(str+i+j)==*(palavra+j)){
					for(k=0;k<tp;k++){
						if (*(str+i+j+k)==*(palavra+k)){
							copyChar((str+i+j+k), (palavra2+k));
						}
					}
				}
			}
		}
	}	
}
int main(){
	char str[50], palavra[50], palavra2[50];
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a palavra que deseja substituir:\n");
	gets(palavra);
	printf("Digite a nova palavra:\n");
	gets(palavra2);
	printf("Substituindo '%s' por '%s' em '%s'.\n", palavra, palavra2, str);
	replaceWord(str, palavra, palavra2);
	printf("Resultado: '%s'.", str);
	

	return 0;
}
