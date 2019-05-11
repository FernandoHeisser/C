#include <stdio.h>
#include <string.h>

void swapChar(char *a, char *b){
	char aux;
	aux=*(a);
	*(a)=*(b);
	*(b)=aux;
}
void replaceChar(char *str, char letra, char letra2){
	int tam=strlen(str), i, j;
	for (j=0;j<tam;j++){	
		for (i=0;i<tam;i++){
			if(*(str+i)==letra){
				swapChar((str+i), &letra2);
			}		
		}
	}
}
int main(){
	char str[50], letra, letra2;
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a letra para ser trocada:\n");
	letra=getch();
	printf("%c\n", letra);
	printf("Digite a nova letra:\n");
	letra2=getch();
	printf("%c\n", letra2);
	printf("Substituindo '%c' por '%c' em '%s'.\n", letra, letra2, str);
	replaceChar(str, letra, letra2);
	printf("Resultado: '%s'.", str);
	
	return 0;
}
