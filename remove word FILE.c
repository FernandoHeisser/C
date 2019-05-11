#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nLinhas(char * file_name){
    FILE *f;
    char str[50];
    int cont=0;
    f=fopen(file_name, "r");

    while(fgets(str, 50, f)!=NULL){
        cont++;
    }
    fclose(f);
    return cont;
}
void swapChar(char *a, char *b){
    char aux;
    aux=*(a);
    *(a)=*(b);
    *(b)=aux;
}
void removeChar(char *str, char letra, int pos_inicial, int pos_final){
    int i, j;
    for (i=pos_inicial;i<pos_final;i++){
        if(*(str+i)==letra){
            swapChar((str+i), (str+i+1));
        }
    }
}
int findWord(char *str, char *palavra){
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
void removeWordPart1(char *str, char *palavra){
    int local=findWord(str, palavra);
    int i=0;
    int ts=strlen(str);
    int tp=strlen(palavra);

    while(i<tp){

        if( *(str+local) == *(palavra+i) ){
            removeChar( str, *(str+local), local, ts );
        }
        else if(*str == *(palavra+i)){
            removeChar( str, *(str+local), local, ts );
        }
        i++;
    }
}
void removeWord(char * str, char * word){
    int i=0, ts=strlen(str), tp=strlen(word);
    while(i<ts){
        removeWordPart1(str, word);
        i++;
    }
    str=realloc(str, sizeof(char)*(ts-tp));
}
int removeWordFILE(char * file, char * word){
    FILE *f1;
    FILE *f2;
    f1=fopen(file, "r");
    f2=fopen("temp.txt", "w");
    
    char str[100];
    int cont=0;
    
    while(fgets(str, 100, f1)!=NULL){
        if(findWord(str, word)==-1){
            cont++;
        }
        removeWord(str, word);
        fputs(str, f2);
    }
    fclose(f1);
    fclose(f2);

    remove(file);
    rename("temp.txt", file);

    if(cont==nLinhas(file)){
        return 0;
    }
    return 1;
}
int main(){
    int n=removeWordFILE("exemplo.txt", "World");
    printf("%i\n", n);
    return 0;
}
