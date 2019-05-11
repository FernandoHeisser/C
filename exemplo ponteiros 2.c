#include <stdio.h>

int main(){

	int I=300;
	float F=300.600006;
	char C='z';

	int *PTR_I;
	float *PTR_F;
	char *PTR_C;

	PTR_I=&I;
	PTR_F=&F;
	PTR_C=&C;	

	printf("Endereco de I = %x\n", &I);
	printf("Endereco de F = %x\n", &F);
	printf("Endereco de C = %x\n\n", &C);

	printf("Valor no Endereco de I = %i\n", I);
	printf("Valor no Endereco de F = %f\n", F);
	printf("Valor no Endereco de C = %c\n\n", C);

	printf("Endereco apontado por PTR_I = %x\n", PTR_I);
	printf("Endereco apontado por PTR_F = %x\n", PTR_F);
	printf("Endereco apontado por PTR_C = %x\n\n", PTR_C);

	printf("Valor no Endereco PTR_I = %i\n", *PTR_I);
	printf("Valor no Endereco PTR_F = %f\n", *PTR_F);
	printf("Valor no Endereco PTR_C = %c\n\n", *PTR_C);

	return 0;

}
