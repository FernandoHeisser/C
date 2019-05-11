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
int main(){
	char str[50];
	printf("Digite a frase:\n");
	gets(str);
	strUppercase(str);
	printf("%s\n", str);
	return 0;
}
