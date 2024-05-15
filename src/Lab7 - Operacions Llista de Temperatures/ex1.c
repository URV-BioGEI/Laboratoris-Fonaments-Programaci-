#include <stdio.h>
#include <stdlib.h>
int main()
{
    int mitja15, mitja1015, mitja15inf;
    float prim, seg, ter, mitja, n, perc;

    mitja15=0;
    mitja1015=0;
    n=0;
    mitja15inf=0;

    printf("Introdueix la llista de temperatures acabada en -200\n");

    while (prim!=-200)
    {
        scanf("%f", &prim);
        if ((prim==-200) && (n==0))
        {
            printf("Molt malament, la secuencia esta buida, torna-ho a intentar\n");
            getch();
            main();
        }
        if (prim==-200)
        {
            goto batutdeplatan;
        }
        scanf("%f", &seg);
        if (seg==-200)
        {
            printf("Molt malament, falten dades, torna-ho a intentar\n");
            getch();
            main();
        }
        scanf("%f", &ter);
         if (ter==-200)
        {
            printf("Molt malament, falten dades, torna-ho a intentar\n");
            getch();
            main();
        }
        mitja=((prim+seg+ter)/3);
        n=n+1;
        if (mitja>15)
        {
            mitja15=mitja15+1;
        }
        if ((mitja>=10) && (mitja<15))
        {
            mitja1015=mitja1015+1;
        }
        if (mitja<15)
        {
            mitja15inf=mitja15inf+1;
        }
    }
    batutdeplatan:
    perc=((mitja15inf/n)*100);
    printf("El nombre de dies amb mitjana superior a 15 es: %i \n", mitja15);
    printf("El nombre de dies amb mitjana entre 10 i 15 es: %i \n", mitja1015);
    printf("El percentatge de dies amb temp inferior a 15 es: %f \n", perc);
    getch();
    main();

    return 0;
}
