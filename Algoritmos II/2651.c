#include <stdio.h>
#include <string.h>

int main ()
{
	char zelda[100001];
	
	scanf("%d", zelda);
	
	if(strstr(zelda,"zelda") != NULL)
		printf("Link Tranquilo\n");
		
	else
	{
		printf("Link Bolado\n");
	}
	
	return 0;
}