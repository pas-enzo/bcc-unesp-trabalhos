#include <stdio.h>

int main(){
	
	float a, b, c, media;
	
	printf("Insira as tres medias do aluno: \n");
	scanf("%f%f%f", &a, &b, &c);
	
	media = (a + b + c) / 3;
	
	printf("A media do aluno sera de: %.2f\n", media);
}
