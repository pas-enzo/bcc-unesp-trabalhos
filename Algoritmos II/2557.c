#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
	char linha[50];
    char *token;
    
	int v[3], r;
    
    while (fgets(linha, 50, stdin) != NULL) {
        
        r = 2;
        
        token = strtok(linha, "+");
        
        if (token[0] != 'R')
            v[0] = atoi(token);
            
        else {
            v[0] = 0;
            r = 0;
        }
        
        token = strtok(NULL, "=");
        
        if (token[0] != 'L')
            v[1] = atoi(token);
            
        else {
            v[1] = 0;
            r = 1;
        }
        
        token = strtok(NULL, "\n");
        
        if (token[0] != 'J')
            v[2] = atoi(token);
            
        else
            v[2] = 0;
        
        if (!r)
            printf("%d\n", v[2] - v[1]);
            
        else if (r == 1)
            printf("%d\n", v[2] - v[0]);
            
        else
            printf("%d\n", v[0] + v[1]);
    }

    return 0;
}