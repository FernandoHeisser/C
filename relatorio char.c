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
void relatorioChar(char * arq_fonte, char * arq_destino){
    FILE *f1;
    FILE *f2;
    char *alfabeto, c;
    int i=0, j=65, k=97;
    alfabeto=malloc(sizeof(char)*52);
    if(alfabeto==NULL){return NULL;}
    for(i=0;i<26;i++){
        *(alfabeto+i)=j;
        j++;
    }
    for(i=26;i<52;i++){
        *(alfabeto+i)=k;
        k++;
    }
    *(alfabeto+i)='\0';
    i=0;
    char array[52];
    f1=fopen(arq_fonte, "r");
    f2=fopen(arq_destino, "w");
    for(i=0;i<52;i++){
        array[i]=contCaracter(arq_fonte, *(alfabeto+i));
    }
    for(i=0;i<26;i++){
        fprintf(f2,"%c=%i; ", *(alfabeto+i), array[i]);
    }
    fprintf(f2, "\n\n");
    for(i=26;i<52;i++){
        fprintf(f2,"%c=%i; ", *(alfabeto+i), array[i]);
    }


    fclose(f1);
    fclose(f2);
}
int main(){
    relatorioChar("exemplo.txt", "relatorio.txt");
    return 0;
}