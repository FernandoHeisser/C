#include <stdio.h>

float sqr(int a){
	return a*a;
}
float cube(int a){
	return sqr(a)*a;
}
int main(){
	float num;
	
	printf("Enter a number:");
	scanf("%f", &num);
	printf("Cube = %.2f", cube(num));
}
