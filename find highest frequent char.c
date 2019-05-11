#include <stdio.h>
#include <string.h>

int contchar(char *str, char letra){
	int i=0, cont=0;
	for (i=0;i<strlen(str);i++){
		if (*(str+i)==letra){
			cont++;
		}
	}
	return cont;
}

char findHighestFrequentChar(char *str){
	int tam=strlen(str);
	int contvet[tam];
	int i, maior;
	char mais, aux;

	for (i=0;i<tam;i++){
		contvet[i]=contchar(str, *(str+i));		
	}
	maior=contvet[0];
	for (i=0;i<tam;i++){
		if(contvet[i]>maior || i==0){
			maior=contvet[i];
			mais=*(str+i);
		}
	}
	return mais;
}
int main(){
	char str[50];
	printf("Digite a frase:\n");
	gets(str);
	char res=findHighestFrequentChar(str);
	printf("Caracter '%c' eh o caracter mais comum em '%s'.",res, str);
	

	return 0;
}
