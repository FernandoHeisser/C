#include <stdio.h>
#include <string.h>

char findUpper(char *str){
	static int i=0;

	if( (*(str+i)>=65) && (*(str+i)<=90) )
		return *(str+i);
	else{
		i++;
		return findUpper(str);
	}
}
int main(){
	char str[50];
	printf("Digite a frase:\n");
	gets(str);
	printf("Primeira maiuscula de '%s' eh '%c'.", str, findUpper(str));
	return 0;
}
