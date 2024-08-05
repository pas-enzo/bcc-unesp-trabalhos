#include <stdio.h>
#include <string.h>

int main () {
 	char str[] ="- Veja, este exemplo de string.";
 	char *c;
 	printf ("Dividindo a string \"%s\":\n\n",str); 
	 c = strtok (str," .,-"); 
 	while (c != NULL) {
	 printf ("%s\n",c);
	 c = strtok(NULL," .,-");
	 }
	 return 0;
} 