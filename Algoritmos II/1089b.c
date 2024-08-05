#include <stdio.h>

int main(){
    
    int n, i, v[3], pico, p0, p1;
    
    while(1){
             scanf("%d", &n);
             if(n == 0) break;
             pico = 0;
             scanf("%d", &v[0]);
             scanf("%d", &v[1]);
             if(n == 2){
                  if(v[0] != v[1]) pico = 2;
             }
             else{
                  p0=v[0];
                  p1=v[1];
                  
                  for(i = 2; i < n; i++){
                        scanf("%d", &v[2]);
                        if(((v[1]>v[0]) && (v[1]>v[2])) || ((v[1]<v[0]) && (v[1]<v[2]))) ++pico;
                        v[0]=v[1];
                        v[1]=v[2];
                  }

                    if ((p0>p1 && p0>v[2]) || (p0<p1 && p0<v[2])) ++pico;

                    if ((v[2]>v[0] && v[2]>p0) || (v[2]<v[0] && v[2]<p0)) ++pico;
             }
             printf("%d\n", pico);
    }
    return 0;
}