#include <stdio.h>

int main(){

	int num, *ptr;
	
	num=29;

	printf("Endereco de num:%x\n\nValor de num:%i\n\n", &num, num);

	ptr=&num;

	printf("Endereco apontado pelo ponteiro ptr:%x\n\nConteudo do ponteiro ptr:%i\n\n", ptr, *ptr);

	num=34;

	printf("Endereco apontado pelo ponteiro ptr:%x\n\nConteudo do ponteiro ptr:%i\n\n", ptr, *ptr);

	*ptr=7;

	printf("Endereco de num:%x\n\nValor de num:%i\n\n", &num, num);	

	return 0;

}
