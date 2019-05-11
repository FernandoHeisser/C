#include <stdio.h>
#include <stdlib.h>

int contVogals(char * file_name){
	FILE *f;
	char c;
	int cont=0;
	f=fopen(file_name, "r");

	c=fgetc(f);
    while(c!=EOF){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        	cont++;
        c=fgetc(f);
    }
    fclose(f);
    return cont;
}
int main(){
	int vogals=contVogals("exemplo.txt");
	printf("%i\n", vogals);
}
