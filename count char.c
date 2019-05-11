#include <stdio.h>
#include <string.h>

int contChar(char *str, char letra){
	int i=0, cont=0;
	for (i=0;i<strlen(str);i++){
		if (*(str+i)==letra){
			cont++;
		}
	}
	return cont;
}
int main(){
	char str[50], letra;
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a letra:\n");
	letra=getch();
	int res=contChar(str, letra);
	printf("Caracter '%c' encontrado %i vezes na string '%s'.", letra, res, str);
	

	return 0;
}
