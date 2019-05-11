#include <stdio.h>
#include <string.h>

void strUppercase(char *str){
	unsigned char i;
	for(i=0;*(str+i)!='\0';i++){
		if(*(str+i)>=97 && *(str+i)<=122){
			*(str+i)-=32;
		}
	}
}
int contVogals(char *str){
	int cont=0;
	char i;
	strUppercase(str);
	for(i=0;*(str+i)!='\0';i++){
		if(*(str+i)=='A' || *(str+i)=='E' || *(str+i)=='I' || *(str+i)=='O' || *(str+i)=='U'){
			cont++;
		}
	}
	return cont;
}
int main(){
	char str[50];
	printf("Digite a frase:\n");
	gets(str);
	printf("Contem %i vogais.\n", contVogals(str));
	return 0;
}
