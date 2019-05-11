#include <stdio.h>

float _saldo=0;

void consulta(){
	printf("\n\n Seu saldo atual: %.2f\n\n", _saldo);
}
float saque(float a){
	_saldo-=a;
	return _saldo;
}
float deposito(float a){
	_saldo+=a;
	return _saldo;
}
void limpa(){
	system("CLS");
}
int main(){
	
		char op;
		float dinheiro;
	do{	
		printf("\n a - Consultar Saldo\n b - Realizar Saque\n c - Realizar Deposito\n d - Sair do Programa\n\n");
		printf(" Digite a operacao:");
		scanf(" %c", &op);
		if (op=='a'){
			limpa();
			consulta();
		}
		if (op=='b'){
			limpa();
			printf("\n\n Voce escolheu Saque");
			printf("\n Digite o valor:");
			scanf("%f", &dinheiro);
			limpa();
			printf("\n\n Seu saldo atualizado: %.2f\n", saque(dinheiro));
		}
		if (op=='c'){
			limpa();
			printf("\n\n Voce escolheu Deposito");
			printf("\n Digite o valor:");
			scanf("%f", &dinheiro);
			limpa();
			printf("\n\n Seu saldo atualizado: %.2f\n", deposito(dinheiro));
		}
	}while(op!='d');
	return 0;
}
