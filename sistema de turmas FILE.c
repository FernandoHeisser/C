#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
char * readString(){
    char *pStr = malloc(sizeof(char));
    char c = ' ';
    int i =0;

    if(pStr == NULL)
        return NULL;

    while (( c = getchar() ) != '\n' && pStr != NULL)
    {
        *(pStr+i)=c;
        i++;
        pStr = realloc(pStr, i+1);
    }
    *(pStr+i) = '\0';
    // printf("\nSize: %d Long String value:%s \n\n", i,pStr);
    return pStr;
}
char * defineTurma(char * curso, char *sem_ano, char *turno){
	strcat(curso, "_");
	strcat(curso, sem_ano);
	strcat(curso, "A");
	strcat(curso, turno);
	char *aux;
	strcpy(aux, curso);
	strcat(curso, ".txt");
	FILE *f;
	f=fopen(curso, "w");
	fprintf(f, "# matricula\tnome\tnota1\tnota2\trecuperacao\n");
	fclose(f);
	return aux;
}
int inserirAluno(char * turma, char * aluno, float n1, float n2, float rec){
	FILE *f;
	strcat(turma, ".txt");
	f=fopen(turma, "r");
	if(f==NULL){
		return 0;
	}else{
		fclose(f);
		f=fopen(turma, "a");
		fprintf(f, "%i\t%s\t%.1f\t%.1f\t%.1f\n", nLinhas(turma), aluno, n1, n2, rec);
		fclose(f);
		return 1;
	}
}
int removerAluno(char * turma, int matricula){
	FILE *f;
	FILE *f_aux;
	strcat(turma, ".txt");
	f=fopen(turma, "r");
	if(f==NULL){
		return 0;
	}else{
		fclose(f);
		f=fopen(turma, "r");
		f_aux=fopen("temp.txt", "w");
		int nLines=0;
		char str[100];
		while(fgets(str, 100, f)!=NULL){
	        if(nLines!=matricula)
	            fputs(str, f_aux);
	        nLines++;
	    }

		fclose(f_aux);
		fclose(f);
		remove(turma);
		rename("temp.txt", turma);
		return 1;
	}
}
int editarAluno(char * turma, int matricula, float n1, float n2, float rec){
	FILE *f;
	char turma_s[100];
	int mat, nLines=0;
	float n1_old, n2_old, rec_old;
	char str[100];
	char nome[100];
	strcpy(turma_s, turma);
	strcat(turma, ".txt");

	f=fopen(turma, "r");
	if(f==NULL){
		return 0;
	}
	else{
		while(fgets(str, 100, f)!=NULL){
	    	fscanf(f, "%i\t%s\t%f\t%f\t%f", &mat, nome, &n1_old, &n2_old, &rec_old);
	    	if(mat==matricula){
	    		printf("%i\t%s\t%.1f\t%.1f\t%.1f\n", mat, nome, n1_old, n2_old, rec_old);
	    		break;
	    	}
		}
		fclose(f);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    FILE *f_aux;
	    char str2[100];
	    nLines=0;

	    f=fopen(turma, "r");
	    if(f==NULL){return 0;}

	    f_aux=fopen("temporario.txt", "w");
	    if(f_aux==NULL){return 0;}
	    
	    while(fgets(str2, 100, f)!=NULL){
	        if(nLines==mat){
	            fprintf(f_aux, "%i\t%s\t%.1f\t%.1f\t%.1f\n", mat, nome, n1, n2, rec);
	            nLines++;
	            continue;
	        }
	        fputs(str2, f_aux);
	        nLines++;
	    }
	    fclose(f);
	    fclose(f_aux);
	    remove(turma);
	    rename("temporario.txt", turma);
	    return 1;
	}
}
void exibeAlunos(char * turma, char status){
	FILE *f;
	int nLines=0;
	char str[100];
	strcat(turma, ".txt");

	int mat;
	char nome[100];
	float n1, n2, rec;

	f=fopen(turma, "r");
	if(f==NULL){
		return 0;
	}
	else{
		if(status=='a'){
			printf("\n\nAprovados Sem Recuperacao:\n");
			while(fgets(str, 100, f)!=NULL){
		    	fscanf(f, "%i\t%s\t%f\t%f\t%f", &mat, nome, &n1, &n2, &rec);
		    	if( (n1+n2)/2>6 ){
		    		printf("%i\t%s\t%.1f\t%.1f\t%.1f\n", mat, nome, n1, n2, rec);
		    	}
			}
			printf("\n\n");
		}
		else if(status=='b'){
			printf("\n\nAprovados Com Recuperacao:\n");
			while(fgets(str, 100, f)!=NULL){
		    	fscanf(f, "%i\t%s\t%f\t%f\t%f", &mat, nome, &n1, &n2, &rec);
		    	if( ((n1+n2)/2<6)&&(rec>6) ){
		    		printf("%i\t%s\t%.1f\t%.1f\t%.1f\n", mat, nome, n1, n2, rec);
		    	}
			}
			printf("\n\n");
		}
		else if(status=='r'){
			printf("\n\nReprovados:\n");
			while(fgets(str, 100, f)!=NULL){
		    	fscanf(f, "%i\t%s\t%f\t%f\t%f", &mat, nome, &n1, &n2, &rec);
		    	if( ((n1+n2)/2<6)&&(rec<6) ){
		    		printf("%i\t%s\t%.1f\t%.1f\t%.1f\n", mat, nome, n1, n2, rec);
		    	
		    	}
			}
			printf("\n\n");	
		}
		fclose(f);
	}
}
void exibeEstatisticas(char * turma){
	FILE *f;
	int nLines=0;
	char str[100];
	strcat(turma, ".txt");

	int mat, i=0, n_alunos=nLinhas(turma)-1;
	char nome[100];
	int cont_aprovados=0, cont_aprovados_rec=0, cont_reprovados=0;
	float n1, n2, rec;
	float array_n1[n_alunos], array_n2[n_alunos], array_rec[n_alunos];
	float soma_n1=0, soma_n2=0, soma_rec=0;
	float media_total, media_aprovados, media_reprovados, media_aprovados_recuperacao;
	f=fopen(turma, "r");
	if(f==NULL){
		printf("\n\nTurma nao encontrada.\n\n");
		return 0;
	}
	else{
		while(fgets(str, 100, f)!=NULL){
	    	fscanf(f, "%i\t%s\t%f\t%f\t%f", &mat, nome, &n1, &n2, &rec);
	    	if( (n1+n2)/2>6 ){cont_aprovados++;}
	    	else if( ((n1+n2)/2<6)&&(rec>6)){cont_aprovados_rec++;}
	    	else if( ((n1+n2)/2<6)&&(rec<6) ){cont_reprovados++;}
	    	array_n1[i]=n1;
	    	array_n2[i]=n2;
	    	array_rec[i]=rec;
	    	i++;
		}
		i=0;
		while(i<=n_alunos){
			soma_n1+=array_n1[i];
			soma_n2+=array_n2[i];
			soma_rec+=array_rec[i];
			i++;
		}
		media_total=((soma_n1+soma_n2)/2)/n_alunos;
		media_aprovados=(cont_aprovados*100)/n_alunos;
		media_aprovados_recuperacao=(cont_aprovados_rec*100)/n_alunos;
		media_reprovados=(cont_reprovados*100)/n_alunos;

		printf("\n\nEstatisticas:\n\n");
		printf("Media Total - %.2f\nAprovados - %.2f%%\nAprovados com Recuperacao - %.2f%%\nReprovados - %.2f%%\n\n", media_total, media_aprovados, media_aprovados_recuperacao, media_reprovados);
	}
}
int main(){
	char op='Z';
	while(op!='a' || op!='b' || op!='c' || op!='d' || op!='e' || op!='f' || op!='g' || op!='h'){
		printf("Digite a opcao que voce deseja executar:\n\n");
		printf("(a) Definir informacoes da turma\n");
		printf("(b) Inserir aluno e notas;\n");
		printf("(c) Remover aluno;\n");
		printf("(d) Editar nota aluno;\n");
		printf("(e) Exibir alunos aprovados;\n");
		printf("(f) Exibir alunos reprovados;\n");
		printf("(g) Exibir estatisticas (media geral, %_ reprovados, %_ aprovados s/ recuperacao, %_ aprovados c/ rec.);\n");
		printf("(h) Sair do programa (fim).\n");
		op=getch();
		system("cls");

		if(op=='a'){
	    	system("cls");
	    	char *curso;
	    	char *sem_ano;
	    	char *turno;
	    	printf("Digite o Curso:\n");
	    	curso=readString();
	    	printf("Digite o Ano ou Semestre:\n");
	    	sem_ano=readString();
	    	printf("Digite o Turno:\n");
	    	turno=readString();
	    	char *str=defineTurma(curso, sem_ano, turno);
	    	printf("\n%s\n\n\n", str);
	    }
	    else if(op=='b'){
	    	system("cls");
	    	char *nome;
	    	char *turma;
	    	float n1, n2, rec;
	    	printf("Digite a Turma:\n");
	    	turma=readString();
	    	printf("Digite o Nome do Aluno:\n");
	    	nome=readString();
	    	printf("Digite a Nota 1:\n");
	    	scanf("%f", &n1);
	    	printf("Digite a Nota 2:\n");
	    	scanf("%f", &n2);
	    	printf("Digite a Nota da Recuperacao:\n");
	    	scanf("%f", &rec);
	    	int teste=inserirAluno(turma, nome, n1, n2, rec);
	    	printf("\n[%i]\n\n", teste);
	    }
	    else if(op=='c'){
	    	system("cls");
	    	char *turma;
	    	int matricula;
	    	printf("Digite a Turma:\n");
	    	turma=readString();
	    	printf("Digite a Matricula:\n");
	    	scanf("%i", &matricula);
	    	int teste=removerAluno(turma, matricula);
	    	printf("\n[%i]\n\n", teste);
	    }
	    else if(op=='d'){
	    	system("cls");
	    	char *turma;
	    	int matricula;
	    	float n1, n2, rec;
	    	printf("Digite a Turma:\n");
	    	turma=readString();
	    	printf("Digite a Matricula:\n");
	    	scanf("%i", &matricula);
	    	printf("Digite a Nota 1:\n");
	    	scanf("%f", &n1);
	    	printf("Digite a Nota 2:\n");
	    	scanf("%f", &n2);
	    	printf("Digite a Nota da Recuperacao:\n");
	    	scanf("%f", &rec);
	    	int teste=editarAluno(turma, matricula, n1, n2, rec);
	    	printf("\n[%i]\n\n", teste);
	    }
	    else if(op=='e'){
	    	system("cls");
	    	char *turma;
	    	printf("Digite a Turma:\n");
	    	turma=readString();
	    	char op;
	    	printf("Digite a opcao:\n(a)Aprovados sem recuperacao;\n(b)Aprovados com recuperacao;\n");
	    	scanf(" %c", &op);
	    	exibeAlunos(turma, op);
	    }
	    else if(op=='f'){
	    	system("cls");
	    	char *turma;
	    	printf("Digite a Turma:\n");
	    	turma=readString();
	    	exibeAlunos(turma, 'r');
	    }
	    else if(op=='g'){
	    	system("cls");
	    	char *turma;
	    	printf("Digite a Turma:\n");
	    	turma=readString();
	    	exibeEstatisticas(turma);
	    }
	    else if(op=='h'){
	    	system("cls");
	    	return 0;
	    }
	}
}
