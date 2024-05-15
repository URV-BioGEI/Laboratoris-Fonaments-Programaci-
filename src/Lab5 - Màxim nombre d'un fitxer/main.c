#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	FILE *n;
	int opc;
	float x, major;
	n = fopen("números.txt", "r");
	if (n==0)
    {
        printf("El fitxer no existeix");
        getch();
    }
    else
    {
        fscanf (n, "%f", &x);
        major = x;
        while (!feof(n))
       {
        fscanf (n, "%f", &x);
        if (x > major)
        {
            major = x;
        }
       }
        printf ("el major es %f", major);
        getch();
        printf("\nVols tornar a fer servir el programa? (1/0)");
        scanf("%i", &opc);
        if (1 == opc)
        {
            main();
        }

    }
	return 0;
}
