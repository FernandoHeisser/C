#include <stdio.h>
#include <stdlib.h>

int contVogalsOrConsonants(char * file_name, int op){
    FILE *f;
    char c;
    int cont=0;
    f=fopen(file_name, "r");
    if(op==0){
        c=fgetc(f);
        while(c!=EOF){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
                cont++;
            c=fgetc(f);
        }
    }
    if(op==1){
        c=fgetc(f);
        while(c!=EOF){
            if(c!='a'||c!='e'||c!='i'||c!='o'||c!='u'||c!='A'||c!='E'||c!='I'||c!='O'||c!='U'){
                if(c>'a'&&c<='z'||c>'A'&&c<='Z'){   
                    cont++;
                }
            }
            c=fgetc(f);
        }
    }
    fclose(f);
    return cont;
}
int main(){
    int vogals=contVogalsOrConsonants("exemplo.txt", 0);
    int consonants=contVogalsOrConsonants("exemplo.txt", 1);
    printf("Vogais-%i\nConsoantes-%i\n", vogals, consonants);

}