#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   
#include <string.h> 
typedef struct {
	char nome[20], curso[4];
    int RA;
    float P1, P2, MT, freq;
  } dados;
//------------------------------------
char confirma () {
  char resp;
  printf ("Confirma (S/N)?");
  do {
    resp = toupper(getch());
  } while (resp != 'S' && resp != 'N');
  return resp;
}  
//------------------------------------
void menu (char *opcao) {
  system ("cls");
  printf ("\n    M E N U ");
  printf ("\n 1 - Cadastra alunos");
  printf ("\n 2 - Mostra todos alunos");
  printf ("\n 3 - Lista Alunos Aprovados");
  printf ("\n 4 - Consulta por Curso");
  printf ("\n 5 - Consulta Alunos com Baixa Frequencia");
  printf ("\n 6 - Altera dados de Alunos");
  printf ("\n 7 - Sair");
  printf ("\n\n Opcao ---> ");
  do {
    *opcao = getch();
  } while (*opcao < '1' || *opcao > '7'); 
  printf ("%c",*opcao);   
  printf ("\n\n--------------------------------------------------------\n");   
}    
//------------------------------------
void cadastra (char nomearq[]){
  dados aluno;
  char resp, numstr[10];
  FILE *arquivo;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "wb")) == NULL) {
    printf ("\nErro da abertura do arquivo.\n\n");
    return;
  }    
  // Leitura dos registros e gravacao
  do {
    fflush (stdin); // "Limpa" o buffer de entrada - teclado
    printf("\n\nNome do aluno: ");
    gets(aluno.nome);
    printf("RA do aluno: ");
    gets(numstr);
    aluno.RA = atoi(numstr);
    printf("Curso: ");
    gets(aluno.curso);
    printf("Nota da P1: ");
    gets(numstr);
    aluno.P1 = atof(numstr);
    printf("Nota da P2: ");
    gets(numstr);
    aluno.P2 = atof(numstr);
    printf("Media dos Trabalhos: ");
    gets(numstr);
    aluno.MT = atof(numstr);
    printf("Frequencia: ");
    gets(numstr);
    aluno.freq = atof(numstr);
    fwrite(&aluno,sizeof(aluno),1,arquivo);
    printf("\n Adicionar outro aluno (s/n)?: ");
    do {
      resp = toupper(getch());
    } while (resp != 'S' && resp != 'N');
  } while (resp == 'S');
  fclose (arquivo);     
}     
//------------------------------------
void mostra (char nomearq[]){
  FILE *arquivo;
  dados aluno;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  // Leitura dos registros  
  printf ("\nALUNOS CADASTRADOS\n");
  printf ("\n       Nome do aluno\t  RA   Curso\t   P1       P2       MT     Freq");
  while (fread (&aluno, sizeof(dados), 1, arquivo) == 1) 
    printf ("\n %19s  %6d %7s %8.2f %8.2f %8.2f %8.1f",aluno.nome,aluno.RA,aluno.curso,aluno.P1,aluno.P2,aluno.MT,aluno.freq);
  fclose (arquivo);
  getch();
}
//------------------------------------
void mostraaprovados (char nomearq[]){
  FILE *arquivo;
  dados aluno;
  float MF;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  // Leitura dos registros  
  printf ("\nALUNOS APROVADOS\n");
  printf ("\n       Nome do aluno\t  RA   Curso\t   MF     Freq");
  while (fread (&aluno, sizeof(dados), 1, arquivo) == 1) {
    MF = (aluno.P1+aluno.P2)/2*0.8+aluno.MT*0.2;
    if (MF >= 5 && aluno.freq>= 70)
      printf ("\n %19s  %6d %7s %8.2f %8.1f",aluno.nome,aluno.RA,aluno.curso,MF,aluno.freq);
  }
  fclose (arquivo);
  getch();
}
//------------------------------------
void consultaCurso (char nomearq[]){
  FILE *arquivo;
  dados aluno;
  float MF;
  char curso[4];
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  printf ("\nQual curso deseja consultar? ");
  fflush (stdin);
  gets (curso);
  // Leitura dos registros  
  printf ("\nALUNOS DO CURSO %s",curso);
  printf ("\n       Nome do aluno\t  RA\t   MF     Freq");
  while (fread (&aluno, sizeof(dados), 1, arquivo) == 1)
    if (stricmp(aluno.curso,curso)==0) {
      MF = (aluno.P1+aluno.P2)/2*0.8+aluno.MT*0.2;	
      printf ("\n %19s  %6d %8.2f %8.1f",aluno.nome,aluno.RA,MF,aluno.freq);
  }
  fclose (arquivo);
  getch();
}
//------------------------------------
void consultaBaixaFrequencia (char nomearq[]){
  FILE *arquivo;
  dados aluno;
  float MF;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  // Leitura dos registros  
  printf ("\nALUNOS COM BAIXA FRQUENCIA");
  printf ("\n       Nome do aluno\t  RA   Curso\t   MF     Freq");
  while (fread (&aluno, sizeof(dados), 1, arquivo) == 1)
    if (aluno.freq < 70) {
      MF = (aluno.P1+aluno.P2)/2*0.8+aluno.MT*0.2;	
      printf ("\n %19s  %6d %7s %8.2f %8.1f",aluno.nome,aluno.RA,aluno.curso,MF,aluno.freq);
  }
  fclose (arquivo);
  getch();
}
//------------------------------------
void alt_cad(char nomearq[]){
	dados aluno;
	char resp, numstr[10];
	FILE *arquivo;

  // Leitura dos registros e gravacao
    fflush (stdin); // "Limpa" o buffer de entrada - teclado
    printf("\n\nNome do aluno: ");
    gets(aluno.nome);
    printf("RA do aluno: ");
    gets(numstr);
    aluno.RA = atoi(numstr);
    printf("Curso: ");
    gets(aluno.curso);
    printf("Nota da P1: ");
    gets(numstr);
    aluno.P1 = atof(numstr);
    printf("Nota da P2: ");
    gets(numstr);
    aluno.P2 = atof(numstr);
    printf("Media dos Trabalhos: ");
    gets(numstr);
    aluno.MT = atof(numstr);
    printf("Frequencia: ");
    gets(numstr);
    aluno.freq = atof(numstr);
    fwrite(&aluno,sizeof(aluno),1,arquivo);

  fclose (arquivo); 
}
//------------------------------------
void altera(char nomearq[]){
	
	FILE *arquivo;
	dados aluno;
	char strbusca[20];
	int find=0;
	
	if ((arquivo = fopen(nomearq, "r+b")) == NULL) {
    printf ("\nErro da abertura do arquivo.\n\n");
    return;
}
	printf("Digite o RA do aluno cujo dados gostaria de alterar:\n");
	
	
	while(!find){	
		
			fseek(arquivo, -sizeof(dados), SEEK_CUR);
		
			if(){
				alt_cad(nomearq);
				find=1;
			} 
	}
	
	fclose(arquivo);
}
//------------------------------------
int main() {
  char opcao, nome_arquivo[20];
  printf ("Nome do arquivo a ser manipulado: ");
  gets (nome_arquivo);
  do{
    menu(&opcao);
    switch (opcao) {
      case '1': cadastra(nome_arquivo);
                break;
      case '2': mostra (nome_arquivo);
                break;
      case '3': mostraaprovados(nome_arquivo);
                break;
      case '4': consultaCurso(nome_arquivo);
                break;
      case '5': consultaBaixaFrequencia(nome_arquivo);
                break;     
	  case '6': altera(nome_arquivo);
	  			break;		
	  case '7': break;
      default: printf ("\nOpcao errada.\n");
    }
  } while (opcao != '7');
  
  return 0;
}    
//------------------------------------
