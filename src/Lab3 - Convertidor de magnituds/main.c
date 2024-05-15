#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    float grams, lliures;
    printf("Introduiu el pes en grams: ");
    scanf("%f" ,&grams);
    lliures=grams*(1/453.5923704);
    printf("\nEl pes en grams %.2f es correspon a %.4f lliures ", grams, lliures);
    getch();
    return 0;
}
