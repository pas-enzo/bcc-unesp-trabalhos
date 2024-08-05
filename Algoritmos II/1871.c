#include <stdio.h>
#include <math.h>
#include <string.h>


char* altera(int valor, char* resu, int base) {
		
	if (base < 2 || base > 36){ 
		*resu = '\0'; return resu; 
	}
		
		char* ptr=resu, *ptr1=resu, tmp_char;	
		int tmp_valor;

	do{
		tmp_valor=valor;
		valor/=base;
		*ptr++="zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35+(tmp_valor-valor*base)];
	}while(valor);


	if(tmp_valor<0) 
		*ptr++='-';

	*ptr--='\0';
	
	while(ptr1<ptr) {

		tmp_char=*ptr;
		*ptr--=*ptr1;
		*ptr1++=tmp_char;
	}

	return resu;
}


int main(){

	int m=1, n=1, num;
	int i, tamanho, c=0;
	char num_str[12],aux[12];

	while(m!=0 && n!=0){

		c=0;

		scanf("%i %i", &m, &n);
		if(m==0 && n==0){
			continue;
			}

		num=m+n;
	
		altera(num,num_str,10);
	
		tamanho=strlen(num_str);
	
		for(i=0;i<tamanho;i++){
			if(num_str[i]!='0'){
				aux[c++]=num_str[i];
			}
		}
	
		for(i=0;i<c;i++){
			if(i!=c-1){
				printf("%c",aux[i]);
			}

			else{
				printf("%c\n",aux[i]);
			}
		}
}

	return 0;
}