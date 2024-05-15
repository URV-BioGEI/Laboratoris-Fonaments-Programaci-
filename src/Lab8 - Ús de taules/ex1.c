#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    float mitjana, desvest, quad, suma, total, notes[282];
    int mitjax, i, k;
    total=0;
    mitjax=0;
    suma=0;
    i=0;
    k=0;
    printf("Introdueix les notes de laboratori acabades en -1:\n");
    while((notes[i]!=-1) && (i<282))
    {
        scanf("%f", &notes[i]);
        if(notes[i]!=-1)
        {
            total=total+notes[i];
            i++;
        }
    }
    mitjana=total/i;
    while(notes[k]!=-1)
    {
        if(notes[k]>mitjana)
        {
            mitjax++;
        }
        quad=notes[k]-mitjana;
        suma=suma+(pow(quad, 2));
        k++;
    }
    desvest=sqrt(suma/(i-1));
    printf("Nota mitjana del laboratori: %.2f\n", mitjana);
    printf("La desviacio tipica es: %.2f\n", desvest);
    printf("Total d'alumnes per sobre la mitjana: %d\n", mitjax);
    getch();
    return(0);
}
