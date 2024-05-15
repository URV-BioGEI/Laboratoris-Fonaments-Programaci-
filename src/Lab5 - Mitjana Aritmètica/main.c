#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
int n, i, k;
float total, mitjana, val;
    printf("\nIntrodueix el nombre de valors dels quals vols fer la mitjana: ");
    scanf("%i", &n);
    if (n>=0)
    {
        for (i=0;i!=n;i++)
        {
            k=i+1;
            printf("Introdueix valor %i: ", k);
            scanf ("%f", &val);
            total=val + total;
        }
        mitjana=total/n;
        printf("\nLa mitjana es %f", mitjana);
        getch();
    }
    else
    {
    printf("\nValor incorrecte, torni-ho a intentar");
    main();
    }
    return 0;
}
