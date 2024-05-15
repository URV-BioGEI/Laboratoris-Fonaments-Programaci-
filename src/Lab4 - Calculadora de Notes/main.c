#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	float Qt, Qp, Qpr, Qpa, Ntp, Nf;

printf("Introdueix nota teoria: ");
scanf("%f", &Qt);
printf("\nIntrodueix nota problemes: ");
scanf("%f", &Qp);
printf("\nIntrodueix nota de participacio: ");
scanf("%f", &Qpa);
printf("\nIntrodueix nota practiques: ");
scanf("%f", &Qpr);

Ntp = ((Qt + Qp)/2);
if ((Ntp >= 5) && (Qpr > 4))
{
    Nf=Qpr*0.15+Qpa*0.05+0.8*Ntp;
    if (Nf >= 5)
        {
		printf("La teva nota es %.2f", Nf);
		getch();
        }
    else
        {
		printf("SUSPES");
		getch();
        }
}
else
{
	printf("SUSPES");
	getch();
}
return 0;
}

