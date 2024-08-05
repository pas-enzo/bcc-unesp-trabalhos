#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int horas;
  int minutos;
} hm;
//------------------- Converte 
void converte (int t, hm *horario) {
  (*horario).horas = t / 60;
  (*horario).minutos = t % 60;
}    
//------------------- Programa Principal
int main() {
  int tempo;
  hm t;    
  system ("cls");
  printf ("Digite um tempo (em minutos): ");
  scanf ("%d",&tempo);
  converte (tempo,&t);
  printf ("\n%d minutos = %d horas e %d minutos.\n\n",tempo,t.horas,t.minutos);
}    
