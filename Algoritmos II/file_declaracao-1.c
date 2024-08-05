/* Declaração da estrutura */
FILE *arquivo;

/* o arquivo exemplo.dat está localizado no diretório corrente */
arquivo = fopen ("exemplo.dat","wb");
if (!arquivo) { // if (arquivo == NULL)
  printf ("Erro na abertura do arquivo.");
  exit (1);
}

