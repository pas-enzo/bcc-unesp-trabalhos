#include <stdio.h>

int main() {
    
    short int n = 1;
    
    while (1) {
        
        scanf("%hd", &n);
        
        if (n == 0) break;
        
        short int matriz[n], linha, coluna, primeiro = 1;
        
        for (linha = 0; linha < n; linha++) {
            
            primeiro = linha + 2;
        
            for (coluna = 0; coluna < n; coluna++) {
        
                if (linha < coluna)
                    primeiro++;
                    
                else if (linha > coluna)
                    primeiro--;

                else
                    primeiro = 1;

                if (coluna == 0)
                    printf("%3hd", primeiro);
        
                else
                    printf(" %3hd", primeiro);
            }
            
            printf("\n");
        }
        
        printf("\n");
    }

    return 0;
}
