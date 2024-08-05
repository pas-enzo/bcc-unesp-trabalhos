#include <stdio.h>
int main() {
    
	int n, tempo, distancia, i;
    double media;
    
    while (scanf("%d", &n) != EOF) {
        media = -1.0;
        i = 0;
        
        while (i++ < n) {
            scanf("%d %d", &tempo, &distancia);
            if (distancia/(double)tempo > media) {
                printf("%d\n", i);
                media = distancia/(double)tempo;
            }
        }
    }
    return 0;
}