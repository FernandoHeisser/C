#include <stdio.h>
#include <string.h>

void swapChar(char *a, char *b){
	char aux;
	aux=*(a);
	*(a)=*(b);
	*(b)=aux;
}
void removeBlank(char *str){
	int tam=strlen(str), i, j;
	for (j=0;j<tam;j++){	
		for (i=0;i<tam;i++){
			if(*(str+i)=='\n' || *(str+i)==' ' || *(str+i)=='\t'){
				swapChar((str+i), (str+i+1));
			}		
		}
	}
}
int main(){
	char str[50];
	printf("Digite a frase:\n");
	gets(str);
	removeBlank(str);
	printf("Resultado: '%s'.", str);
	
	return 0;
}

