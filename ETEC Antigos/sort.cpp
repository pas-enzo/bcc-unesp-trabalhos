#include <stdio.h>

int main(){
	
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	
	if(a>b && b>c){
		printf("%i\n%i\n%i\n\n%i\n%i\n%i\n", c, b, a, a, b, c);
	}
	
		else if(a>c && c>b){
			printf("%i\n%i\n%i\n\n%i\n%i\n%i\n", b, c, a, a, b, c);
		}
		
			else if(b>a && a>c){
				printf("%i\n%i\n%i\n\n%i\n%i\n%i\n", c, a, b, a, b, c);
			}
			
				else if(b>c && c>a){
					printf("%i\n%i\n%i\n\n%i\n%i\n%i\n", a, c, b, a, b, c);
				}
				
					else if(c>a && a>b){
						printf("%i\n%i\n%i\n\n%i\n%i\n%i\n", b, a, c, a, b, c);
					}
					
						else if(c>b && b>a){
							printf("%i\n%i\n%i\n\n%i\n%i\n%i\n", a, b, c, a, b, c);
						}
	
	return 0;
}
