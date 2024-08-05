#include <stdio.h>
#include <string.h>

struct tipo_endereco {
  char rua [50];
  int  numero;
  char bairro [20];
  char cidade [30];
  char sigla_estado [3];
  long int CEP;
};

struct ficha_pessoal {
  char nome [50];
  long int telefone;
  struct tipo_endereco endereco;
};

typedef struct ficha_pessoal fp;

int main () {
  fp ficha;
  strcpy (ficha.nome,"LEPEC Unesp");
  ficha.telefone = 31036080;
  strcpy (ficha.endereco.rua,"Av. Luis Edmundo Carrijo Coube");
  ficha.endereco.numero = 1401;
  strcpy (ficha.endereco.bairro,"Vargem Limpa");
  strcpy (ficha.endereco.cidade,"Bauru");
  strcpy (ficha.endereco.sigla_estado,"SP");
  ficha.endereco.CEP = 17033360;
  //-----------------
  printf ("%s\n%s, %d",ficha.nome,ficha.endereco.rua,ficha.endereco.numero);
}
