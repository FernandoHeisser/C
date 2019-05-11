#include <stdio.h>

float pi=3.1416;

float circle(int r){
	float diameter, circum, area;
	diameter = r*2;
	circum = 2*pi*r;
	area = pi*(r*r);
	printf("Diameter = %.2f\nCircumference = %.2f\nArea = %.2f\n", diameter, circum, area);
	return 0;
}

int main(){
	float r;
	printf("Enter a Radius:");
	scanf("%f", &r);
	circle(r);
}
