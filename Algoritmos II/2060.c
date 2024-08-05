#include <stdio.h>

int main(){
	
	int i, j;
    int n, m2=0, m3=0, m4=0, m5=0;
	
	scanf("%d", &n);

    int vet[n+1];

    for(i=0;i<n;i++){
        
        scanf("%d", &vet[i]);

    }

    for(j=0;j<n;j++){
    	if(vet[j]%2==0){
    		m2++;
		}
		
		if(vet[j]%3==0){
    		m3++;
		}
		
		if(vet[j]%4==0){
    		m4++;
		}
		
		if(vet[j]%5==0){
    		m5++;
		}
	}
	


    printf("%d Multiplo(s) de 2\n", m2);
    printf("%d Multiplo(s) de 3\n", m3);
    printf("%d Multiplo(s) de 4\n", m4);
    printf("%d Multiplo(s) de 5\n", m5);
	
	
	return 0;
}