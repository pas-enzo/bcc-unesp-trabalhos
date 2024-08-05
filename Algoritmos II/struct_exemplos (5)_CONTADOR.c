#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//--------------------------------------
// Definicao dos tipos
//--------------------------------------
typedef struct {
       int dia, mes, ano;
} data;
typedef struct {
       char nome[10], sobrenome[10], RG[10];
       data nasc, admissao;
       float salario;
} info;   
//--------------------------------------
// Leitura dos dados de um funcionario
//--------------------------------------    
void leDados (info *dado) {
  fflush(stdin);
  printf ("Digite o nome do funcionario: ");
  gets ((*dado).nome);
  printf ("Digite o sobrenome do funcionario: ");
  gets ((*dado).sobrenome);
  printf ("Digite o RG de %s: ",(*dado).nome);
  gets((*dado).RG);
  printf ("Digite a data de nascimento: ");
  scanf ("%d %d %d",&(*dado).nasc.dia,&(*dado).nasc.mes,&(*dado).nasc.ano);
  printf ("Digite a data de admissao: ");
  scanf ("%d %d %d",&(*dado).admissao.dia,&(*dado).admissao.mes,&(*dado).admissao.ano);
  printf ("Digite o salario de %s: ",(*dado).nome);
  scanf ("%f",&(*dado).salario);
  printf ("\n\n");
}
//--------------------------------------
// Mostra dados de um funcionario
//--------------------------------------
void mostraDados (info dado) {
  printf ("\n%s %s\nNASC: %d/%d/%d - RG: %s\n",dado.nome,dado.sobrenome,dado.nasc.dia,dado.nasc.mes,dado.nasc.ano,dado.RG);
  printf ("ADMISSAO: %d/%d/%d - SALARIO: %.2f\n",dado.admissao.dia,dado.admissao.mes,dado.admissao.ano,dado.salario);     
}
//--------------------------------------
// Programa Principal
//--------------------------------------
int main() {
  int i, n;
  info dados[MAX];
  system ("cls");
  do{
    printf ("Quantos funcionarios (maximo %d)? ",MAX);
    scanf ("%d",&n);
  } while (n <=0 || n > MAX);
  for (i = 0; i < n; i++)
    leDados (&dados[i]);
  printf ("\n\n");
  for (i = 0; i < n; i++)
    mostraDados (dados[i]);    
}    
