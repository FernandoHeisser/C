#include <stdio.h>
#include <string.h>

int findchar(char *str, char letra){
	int i=0;
	for (i=0;i<strlen(str);i++){
		if (*(str+i)==letra){
			return i;
		}
	}
}
int main(){
	char str[50], letra;
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a letra:\n");
	letra=getch();
	int res=findchar(str, letra);
	printf("Caracter '%c' encontrado na posicao %i da str '%s'.", letra, res, str);
	

	return 0;
}
