#include <stdio.h>
#include <string.h>

int main(){
	
	char inp_string[51], code_string[51];
	int coder, n;
	int i, j;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		
		fflush(stdin);
		gets(inp_string);
		
		
		scanf("%d", &coder);
		
		for(j=0;j!='\0';j++){
			
			if(inp_string[j]-coder<65)
				inp_string[j]+=26;
			
			code_string[j]=inp_string[j]-coder;
			
			printf("%c", code_string);
			
		}
		
		printf("\n");
		
	}
	
	
	
	
	return 0;
}