#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int atualizaN(char ac);
int atualizaZ(char ac);
void openFile();
int strcompare(char *str1, char *str2);
void removeLastChar(char * str);
int validaNumero(char*str);
void printArray();

unsigned char mem[256];

int main(){
    unsigned char ac=0, pc=0, ender, letra;
    int i, op, aux, n, z;

    printf("\n RODAR DIGITE 1: PASSO A PASSO DIGITE 2:");
    scanf("%i", &op);

    system("cls");

    openFile();

    n=atualizaN(ac);
    z=atualizaZ(ac);

    /*printArray();return 0;*/

    for(pc=0;pc<256;pc++){
        if(op==2)
            printf("\n Digite qualquer tecla para continuar e 'Q' para Cancelar:\n\n");
            if(pc==0)
                printf("\n PC=%i\n AC=%i\n MEM[%i]=%i\n\n Z=%i\n N=%i\n", pc, (char)ac, pc, mem[pc], z, n);

        switch(mem[pc]&(128+64+32+16)){
            case 0://NOP

            break;
            case 16://STA
                pc++;
                ender=mem[pc];
                mem[ender]=ac;
            break;
            case 32://LDA
                pc++;
                ender=mem[pc];
                ac=mem[ender];
            break;
            case 48://ADD
                pc++;
                ender=mem[pc];
                ac+=mem[ender];
            break;
            case 64://OR
                pc++;
                ender=mem[pc];
                ac=mem[ender]|ac;
            break;
            case 80://AND
                pc++;
                ender=mem[pc];
                ac=mem[ender]&ac;
            break;
            case 96://NOT
                ac=~ac;
            break;
            case 128://JMP
                pc++;
                pc=(mem[pc]-1);
            break;
            case 144://JN
				if(n){
                    pc++;
                	pc=(mem[pc]-1);
                }
                else
                    pc++;
            break;
            case 160://JZ
                if(z){
                    pc++;
                	pc=(mem[pc]-1);
                }
                else
                    pc++;
            break;
            case 192://IN
                pc++;
                ender=mem[pc];
                printf("\n\n Insira o numero na posicao %i:", ender);
                scanf("%i", &aux);
                mem[ender]=(unsigned char)aux;
                //printArray();
            break;
            case 208://OUT
                pc++;
                ender=mem[pc];
                printf(" MEM[%i]=%i\n", ender,(char)*(mem+ender));
                letra=getch();
            break;
            case 224://LDI
                ac=mem[pc+1]&15;
                pc++;
            break;
            case 240://HLT
                system("cls");
                printArray();
                return 0;
            break;
        }
        n=atualizaN(ac);
        z=atualizaZ(ac);

        if(op==2){
            letra=getch();
            if(letra=='q'){
                printf("\n\nCANCELADO\n\n");
                return 0;
            }
        }

        system("cls");
        printf("\n PC=%i\n AC=%i\n MEM[%i]=%i\n\n Z=%i\n N=%i", pc, (char)ac, pc, mem[pc], z, n);

    }
    return 0;
}
void openFile(){
    FILE *fp;
    char str[80], useless;
    unsigned char cont=0;

    fp = fopen("file.txt", "r");
    while(fgets(str, 81, fp) != NULL){
        removeLastChar(str);

        if(strcompare(str, "lda")==1 || strcompare(str, "LDA")==1)
            mem[cont]=32;
        else if(strcompare(str, "sta")==1 || strcompare(str, "STA")==1)
            mem[cont]=16;
        else if(strcompare(str, "nop")==1 || strcompare(str, "NOP")==1)
            mem[cont]=0;
        else if(strcompare(str, "add")==1 || strcompare(str, "ADD")==1)
            mem[cont]=48;
        else if(strcompare(str, "or")==1 || strcompare(str, "OR")==1)
            mem[cont]=64;
        else if(strcompare(str, "and")==1 || strcompare(str, "AND")==1)
            mem[cont]=80;
        else if(strcompare(str, "not")==1 || strcompare(str, "NOT")==1)
            mem[cont]=96;
        else if(strcompare(str, "jmp")==1 || strcompare(str, "JMP")==1)
            mem[cont]=128;
        else if(strcompare(str, "jn")==1 || strcompare(str, "JN")==1)
            mem[cont]=144;
        else if(strcompare(str, "jz")==1 || strcompare(str, "JZ")==1)
            mem[cont]=160;
        else if(strcompare(str, "in")==1 || strcompare(str, "IN")==1)
            mem[cont]=192;
        else if(strcompare(str, "out")==1 || strcompare(str, "OUT")==1)
            mem[cont]=208;
        else if(strcompare(str, "ldi")==1 || strcompare(str, "LDI")==1)
            mem[cont]=224;
        else if(strcompare(str, "hlt")==1 || strcompare(str, "HLT")==1)
            mem[cont]=240;
        else if(validaNumero(str)==1)
            mem[cont]=atoi(str);
        else{
            fclose(fp);
            return;
        }
        cont++;
    }
    return;
}
void printArray(){
    int i;
    for(i=0;i<256;i++){
        printf("mem[%i] = %i %i\n", i, (char) mem[i],  mem[i]);
    }

}
int validaNumero(char*str){
    char i;
    int cont=0;
    for(i=0;*(str+i)!='\0';i++){
        if(*(str+i)>='0'&&*(str+i)<='9')
            cont++;
    }
    if(cont==strlen(str))
        return 1;
    return 0;
}
void removeLastChar(char * str){
    int index = strlen(str);
	if(*(str+index-1)=='\n'){
    	//printf("%i %s\n", strlen(str), str);
    	*(str+index-1) = '\0';
    	//printf("%i %s\n\n", strlen(str), str);
	}
}
int strcompare(char *str1, char *str2){
    int i, cont=0;
    if(strlen(str1)!=strlen(str2))
        return 0;
    for(i=0;*(str1+i)!='\0';i++){
        if(*(str1+i)==*(str2+i))
            cont++;
    }
    if(cont==strlen(str1))
        return 1;
    return 0;
}
int atualizaN(char ac){
    if((int)ac<0)
        return 1;
    return 0;
}
int atualizaZ(char ac){
    if((int)ac==0)
        return 1;
    return 0;
}
