#include <stdio.h>
#include <string.h>

void swapChar(char *a, char *b){
	char aux;
	aux=*(a);
	*(a)=*(b);
	*(b)=aux;
}
void removeChar(char *str, char letra){
	int tam=strlen(str), i, j;
	for (j=0;j<tam;j++){	
		for (i=0;i<tam;i++){
			if(*(str+i)==letra){
				swapChar((str+i), (str+i+1));
			}		
		}
	}
}
int main(){
	char str[50], letra;
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a letra:\n");
	letra=getch();
	printf("Removendo '%c' de '%s'.", letra, str);
	removeChar(str, letra);
	printf("Resultado: '%s'.", str);
	
	return 0;
}
