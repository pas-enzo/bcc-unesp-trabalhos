#include <stdio.h>

typedef struct{
	float x;
	float y;
	float z;
}vetor;


int main(){
	
	vetor soma[3];
	
	
	printf("Digite as coordenadas do vetor u=(x1,y1,z1) no R^3: \n");
	scanf("%f%f%f", &soma[0].x, &soma[0].y, &soma[0].z);
	
	printf("Digite as coordenadas do vetor v=(x2,y2,z2) no R^3: \n");
	scanf("%f%f%f", &soma[1].x, &soma[1].y, &soma[1].z);
	
	soma[2].x = soma[0].x + soma[1].x;
	soma[2].y = soma[0].y + soma[1].y;
	soma[2].z = soma[0].z + soma[1].z;
	
	printf("\n\nu+v=(%.f,%.f,%.f)\n", soma[2].x, soma[2].y, soma[2].z);
	
	return 0;
	
}