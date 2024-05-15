#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
float impvendaeu,impintroduiteu,impcanvieu;
int var,impcanvicent,mon2eu,mon1eu,mon50,mon20,mon10,mon5,mon2,mon1;

    printf("Introdueix limport del producte en euros: ");
    scanf("%f" , &impvendaeu);
    printf("Introdueix limport introduit en euros: ");
    scanf("%f" , &impintroduiteu);

    impcanvieu=impintroduiteu-impvendaeu;
    impcanvicent=impcanvieu*100;
    mon2eu=impcanvicent/200;
    var=impcanvicent%200;
    mon1eu=var/100;
    var=var%100;
    mon50=var/50;
    var=var%50;
    mon20=var/20;
    var=var%20;
    mon10=var/10;
    var=var%10;
    mon5=var/5;
    var=var%5;
    mon2=var/2;
    var=var%2;
    mon1=var/1;

printf("\nRetornara \n%d monedes de 2  euro \n%d monedes de 1 euro \n%d monedes de 50 cent \n%d monedes de 20 cent \n%d monedes de 10 cent\n%d monedes de 5 cent \n%d monedes de 2 cent \n%d monedes de 1 cent" , mon2eu, mon1eu, mon50, mon20, mon10, mon5, mon2, mon1);
getch();

    return 0;
}
