FILE *arquivo;

if ((arquivo=fopen ("exemplo.dat","wb")) == NULL) {
  printf ("Erro na abertura do arquivo.");
  exit (1);
}
