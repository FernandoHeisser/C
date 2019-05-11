#include <stdio.h>
#include <string.h>

int contWord(char *str, char *palavra){
	int i, j, k, letra=0;
	int ts=strlen(str);
	int tp=strlen(palavra);
	
	for (i=0;i<ts;i++){
		if (*(str+i)==*(palavra)){
			for(j=0;j<tp;j++){
				if (*(str+i+j)==*(palavra+j)){
					for(k=0;k<tp;k++){
						if (*(str+i+j+k)==*(palavra+k)){
							letra++;
						}
					}
				}
			}
		}
	}
	return letra/tp;
}
int main(){
	char str[50], palavra[50];
	printf("Digite a frase:\n");
	gets(str);
	printf("Digite a palavra:\n");
	gets(palavra);
	int res=contWord(str, palavra);
	printf("'%s' encontrada %i vezes na str '%s'.", palavra, res, str);
	

	return 0;
}
