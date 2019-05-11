#include <stdio.h>
#include <stdlib.h>

int contCaracter(char * file_name, char letter){
    FILE *f;
    char c;
    int cont=0;
    f=fopen(file_name, "r");

    c=fgetc(f);
    while(c!=EOF){
        if(c==letter)
            cont++;
        c=fgetc(f);
    }
    fclose(f);
    return cont;
}
int main(){
	int num=contCaracter("exemplo.txt", 'l');
	printf("%i\n", num);
}