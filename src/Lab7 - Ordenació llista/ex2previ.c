#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int x,y,z;
    bool trobat, creixent, decreixent;

    trobat=false;
    creixent=false;
    decreixent=false;
    printf("Introdueix llistat finalitzat en -1 \n");
    scanf("%i", &x);

    if ((x==-1))
    {
        printf("sequencia buida, torna a introduir-la. \n");
        scanf("%i", &x);
    }

    while ((x!=-1) || (y!=-1) || (z!=-1))
    {
        scanf("%i", &y);
        if (x<y)
        {
            scanf("%i", &z);
            if (z<y)
            {
                trobat=true;
            }
            else
            {
                creixent=true;
            }
        }
        if (x>y)
        {
            scanf("%i", &z);
            if (z>y)
            {
                trobat=true;
            }
            else
            {
                decreixent=true;
            }
        }
        scanf("%i", &x);
    }
    if (trobat==true)
        {
            printf("No estan ordenats");
        }
    if (creixent==true)
    {
        printf("estan ordenats creixentment");
    }
    if (decreixent==true)
    {
        printf("estan ordenats decreixentment");
    }
    return 0;
}
