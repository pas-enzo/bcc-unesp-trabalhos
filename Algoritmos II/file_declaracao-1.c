/* Declara��o da estrutura */
FILE *arquivo;

/* o arquivo exemplo.dat est� localizado no diret�rio corrente */
arquivo = fopen ("exemplo.dat","wb");
if (!arquivo) { // if (arquivo == NULL)
  printf ("Erro na abertura do arquivo.");
  exit (1);
}

