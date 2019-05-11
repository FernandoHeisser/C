#include <stdio.h>
#include <string.h>

int ispalindrome(char *str, int index){
	static int i, j;
	i=0;
	j=index;
	if (*(str+i)==*(str+j-1) || i==j){
		return 1;
	}
	else if(*(str+i)==*(str+j-1)){
		i++;
		j--;
		return ispalindrome(str, index);
	}
	else{
		return 0;
	}
}
int main(){
	char str[50];
	printf("Digite a frase:\n");
	gets(str);
	int index=strlen(str);
	int res=ispalindrome(str, index);
	printf("'%s' eh palindromo? %i\n", str, res);
	

	return 0;
}
