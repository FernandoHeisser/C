#include <stdio.h>
#include <stdlib.h>

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
int findWordPart1(char *str, char *palavra){
	int i=0, inicio;
	int ts=strlen(str);
	int tp=strlen(palavra);

	while(i<ts){

		if( *(str+i)==*(palavra) && *(str+i+tp-1)==*(palavra+tp-1) ){

			inicio=i;
			break;

		}
		else{
			inicio=-1;
		}
		i++;
	}
	return inicio;
}
int countWord(char * arquivo, char * palavra){
	FILE *f;
    char str[50];
    int cont=0;

    f=fopen(arquivo, "r");
    if(f==NULL){return 0;}

    while(fgets(str, 50, f)!=NULL){
        if(findWordPart1(str, palavra)!=-1){
        	cont+=contWord(str, palavra);
        }
    }
    fclose(f);

    return cont;
}
int main(){
	int cont=countWord("exemplo.txt", "World");
	printf("%i\n", cont);
}