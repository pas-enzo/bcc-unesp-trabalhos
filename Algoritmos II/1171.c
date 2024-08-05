#include <stdio.h>
#define max 2001

int main(){
	
	int v[max], n, i, j, temp;
	int skipper, cont=0, jumper;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &v[i]);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(v[j]>v[j+1]){
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
//---------------------------------------------	
	//for(i=0;i<n;i++)
	//	printf("%d\n", v[i]);
//---------------------------------------------
	
	for(i=0;i<n;i+=jumper){
		skipper=v[i];
		cont=0;
		for(j=0;j<n;j++){
			if(v[j]==skipper)
				cont++;
		}
		jumper=cont;
		printf("%d aparece %d vez(es)\n", skipper, cont);
	}
	
	return 0;
}