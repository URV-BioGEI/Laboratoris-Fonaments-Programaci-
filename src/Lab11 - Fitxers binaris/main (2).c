#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
typedef struct
{
    int hora, minuts, segons;
}hora_t;
typedef struct
{
    int codi;
    float nota;
    char qualificacio;
    hora_t hora;
    int temps;
}dades;
	int lecturaenter, i, k, p;
	float mitjana, acumulador;
    FILE *fitxer;
    FILE *f;
	dades llista[25];
	hora_t tempsinici;
    p=0;
    k=0;
    i=0;
    lecturaenter=0;
    acumulador=0;
	printf("Introdueix l'hora (hores) de comencament del laboratori: ");
	scanf("%i", &tempsinici.hora);
	printf("Introdueix l'hora (minuts) de comencament del laboratori: ");
	scanf("%i", &tempsinici.minuts);
	printf("Introdueix l'hora (segons) de comencament del laboratori: ");
	scanf("%i", &tempsinici.segons);
    fitxer=fopen("Lab10_L15.bin","rb+");
	if (fitxer==NULL)
    {
		printf("El fitxer no existeix");
    }
	else
    f=fopen("Lab10_L15_nou.bin","w");
    {
        while (i!=18)
        {
            fread(&llista[i], sizeof(dades), 1, fitxer);
            if ((llista[i].nota<=10) && (llista[i].nota>=9))
            {
                llista[i].qualificacio='E';
            }
            if ((llista[i].nota<9) && (llista[i].nota>=7))
            {
                llista[i].qualificacio='N';
            }
            if ((llista[i].nota<7) && (llista[i].nota>=6))
            {
                llista[i].qualificacio='B';
            }
            if ((llista[i].nota<6) && (llista[i].nota>=5))
            {
                llista[i].qualificacio='A';
            }
                if ((llista[i].nota<5) && (llista[i].nota>=0))
            {
                llista[i].qualificacio='S';
            }
            acumulador=acumulador+llista[i].nota;
            llista[i].temps=(llista[i].hora.hora*3600+llista[i].hora.minuts*60+llista[i].hora.segons)-(tempsinici.hora*3600+tempsinici.minuts*60+tempsinici.segons);
            fwrite(&llista[i], sizeof(dades), 1, f);
            p=1;
            if (llista[i].temps>lecturaenter)
            {
                lecturaenter=llista[i].temps;
                llista[i].temps=lecturaenter;
                k=i;
            }
            i++;
        }
        p=i;
		if (p==0)
        {
			printf("\n\nEl fitxer esta buit");
        }
        else
        {
        mitjana=acumulador/i;
        printf("L'alumne %i te nota %f, amb qualificacio %c i va entregar a les %i %i %i amb una diferencia de %i segons; sent l'alumne que va tardar mes en entregar\n\n", llista[k].codi, llista[k].nota, llista[k].qualificacio, llista[k].hora.hora, llista[k].hora.minuts, llista[k].hora.segons, llista[k].temps);
        printf("La mitjana de tots els alumnes es %f", mitjana);
        }
    }
    getch();
    return 0;
}
