#include <stdio.h>
#include <stdlib.h>

void catArqs(char * arq1, char * arq2, char * arqResult){
	FILE *f1;
    FILE *f2;
    FILE *f3;
    char str[50];

    f1=fopen(arq1, "r");
    if(f1==NULL){return 0;}

    f2=fopen(arq2, "r");
    if(f2==NULL){return 0;}

    f3=fopen(arqResult, "w");
    if(f3==NULL){return 0;}

    while(fgets(str, 50, f1)!=NULL){
        fputs(str, f3);
    }
    while(fgets(str, 50, f2)!=NULL){
        fputs(str, f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
int main(){
	catArqs("file1.txt", "file2.txt", "file3.txt");
	return 0;
}