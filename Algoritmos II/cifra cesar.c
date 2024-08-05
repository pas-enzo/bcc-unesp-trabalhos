#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    
	char palavra[50];
	int i, cipher=0, repeticoes=0, codigo=0;
    
	scanf("%d", &repeticoes);
    
	while(repeticoes--){
        
		gets(palavra);
        
		scanf("%d", &cipher);
        
		for (i = 0; i < 50 && palavra[i]!='\0'; i++){
       	        
            if ((palavra[i] - cipher) < 65)
                codigo = (palavra[i] - cipher) + 26;
                
            else
                codigo = palavra[i] - cipher;
        
		printf("%c", codigo);
		
        }
        
        printf("\n");
    }
    return 0;
}