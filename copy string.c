#include <stdio.h>
#include <string.h>

void copyString(char *str1, char *str2){
	static int i=0;
	*(str2+i)=*(str1+i);
	if (*(str1+i)=='\0' && *(str2+i)=='\0'){
		return;
	}
	else{
		i++;
		copyString(str1, str2);
	}
}
int main(){
	char str1[50], str2[50];
	printf("Digite a frase:\n");
	gets(str1);
	copyString(str1, str2);
	printf("Str1: %s\nStr2: %s\n", str1, str2);

	return 0;
}
