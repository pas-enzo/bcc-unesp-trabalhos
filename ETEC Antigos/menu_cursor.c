#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59

//-------------------------------------------------------------------------
void gotoxy (int x, int y){
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//-------------------------------------------------------------------------
int SetColor (char color){
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
//-------------------------------------------------------------------------
void escreveTexto (int x, int y, char texto[], int cor){
  SetColor (cor);
  gotoxy (y,x);
  printf ("%s",texto);
}
//-------------------------------------------------------------------------
void menu (int op){
  char vet[][50] = {"<G> Sacar dinheiro <G>", "<G> Escrever cheque por extenso <G>", "<G> Sobre a nossa empresa <G>", 
  "<G> F1 para ajuda <G>", "<G> Esc para sair <G>"};
  int i;
  system ("cls");
  for (i = 0; i < 11; i++)
    escreveTexto (3+i,10,vet[i],2);
  escreveTexto (2+op,10,vet[op-1],3);  
}
//-------------------------------------------------------------------------
