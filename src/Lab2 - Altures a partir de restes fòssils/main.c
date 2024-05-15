#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()  {
    float fem, hum;
    int altfemdonam, althumdonam, altfemhomem, althumhomem, altfemdonacm, althumdonacm, altfemhomecm, althumhomecm;
    printf("Introdueixi llargada del femur: ");
    scanf("%f", &fem);
    printf("Introdueixi llargada del humer: ");
    scanf("%f", &hum);
altfemdonam=((fem*1.94 + 28.7)*2.54)/100;
altfemhomem=((fem*1.88 + 32)*2.54)/100;
althumdonam=((hum*2.8 + 28.2)*2.54)/100;
althumhomem=((hum*2.9 + 27.9)*2.54)/100;
altfemdonacm=(((fem*1.94 + 28.7)*2.54)-altfemdonam*100);
altfemhomecm=(((fem*1.88 + 32)*2.54)-altfemhomem*100);
althumdonacm=(((hum*2.8 + 28.2)*2.54)-althumdonam*100);
althumhomecm=(((hum*2.9 + 27.9)*2.54)-althumdonam*100);
    printf("Estimacio de l'altura a partir del femur \n");
    printf("Altura d'una dona: %d m %d cm \n", altfemdonam, altfemdonacm);
    printf("Altura d'un home: %d m %d cm \n", altfemhomem, altfemhomecm);
    printf("Estimacio de l'altura a partir del humerus \n");
    printf("Altura d'una dona: %d m %d cm \n", althumdonam, althumdonacm);
    printf("Altura d'un home: %d m %d cm \n", althumhomem, althumhomecm);
    getch();
    return 0;
}
