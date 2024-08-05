#include <stdio.h>
#include <string.h>
struct num {
  int i;
  float f;
};
//---------------------
int main() {
  struct num n1, n2;
  scanf ("%d",&n1.i);
  scanf ("%f",&n1.f);
  n2 = n1; // copia
  printf("Valores da segunda struct: %d e %.2f",n2.i ,n2.f);
}
