#include <stdio.h>

int main () {

    int green=0, blue=0, red=0;
    int casos, gols;
    int i, j;
    char pro, contra;

    scanf("%d", &casos);

    for ( i=0 ; i<casos ; i++ ) {
        
        scanf("%d", &gols);

        for ( j=0 ; j < gols ; j++ ) {

            scanf(" %c %c", pro, contra);

            if (pro == "G") {
                
                if (contra == "B") green+=2;

                else
                    green++;

            }

            if (pro == "B") {

                if (contra == "R") blue+=2;

                else
                    blue++;
            }

            if (pro == "R") {
                
                if (contra == "G") red+=2;

                else
                    red++;

            }

            if (green == blue && green == red) printf("trempate\n");

            if (green == blue && green > red) printf("empate\n");

            if (green == red && green > blue) printf("empate\n");

            if (red == blue && red > green) printf("empate\n");

            if (green > blue && green > red) printf("green\n");

            if (blue > green && blue > red) printf("green\n");

            if (red > green && red > blue) printf("green\n");

        }

        green=0;
        blue=0;
        red=0;

    }



    return 0;

}