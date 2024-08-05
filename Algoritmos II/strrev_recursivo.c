#include <stdio.h>
#define MAX 300


void reverse (char *str){

    if (*str) {

        reverse(str + 1);
        putchar(*str);

    }

}


int main() {

    char string[MAX];
    int size;

    fflush(stdin);
    gets(string);

    printf("\n");

    reverse(string);

    return 0;

}