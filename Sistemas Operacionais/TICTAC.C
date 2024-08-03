#include <system.h>
#include <stdio.h>

PTR_DESC c01, c02, prin;

/* co-rotinas */
void far corotina1()
{
 while(1)
 {
  printf("tic-");
  transfer(c01, c02);
 }
}

void far corotina2()
{
 while(1)
 {
  printf("tac\n");
  transfer(c02,c01);
 }
}

/* Programa Principal */

main()
{
 clrscr();

 /* cria descritores de co-rotinas */
 c01 = cria_desc();
 c02 = cria_desc();
 prin = cria_desc();

 /* associa descritores com as co-rotinas */
 newprocess(corotina1, c01);
 newprocess(corotina2, c02);

 /* transfere o controle para a co-rotina 1 */
 transfer(prin, c01);
 getch();
}
