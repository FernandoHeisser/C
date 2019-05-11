#include <stdio.h>
#include <stdlib.h>

int nLinhas(char * file_name){
	FILE *f;
	char *str;
	int cont=0;
	f=fopen(file_name, "r");

	while(fgets(str, 50, f)!=NULL){
        cont++;
    }
    fclose(f);
    return cont;
}
int main(){
	int linhas=nLinhas("exemplo.txt");
	printf("%i\n", linhas);
}