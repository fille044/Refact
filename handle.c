/* General defines */
#include <stdio.h>
#include <stdbool.h>

/* Local libraries */
#include "handle.h"
#include "calc.h"


bool handleMenu(int val)
{
    switch (val) {
        case 0:
            return true;
        case 1:
            handleOhmsLag();
            break;
        case 2:
            handleResTot();
            break;
        case 3:
            handleEffEnk();
            break;
        case 4:
            handleSkenEff();
            break;
        case 5:
            handleAktivEff();
            break;
        case 6:
            handleSken3Fas();
            break;
        case 7:
            handleAktiv3Fas();
            break;
        default:
            printf("Fel alternativ försök igen!: \n");
            break;
    }
}


void handleOhmsLag(void)
{
    printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n");
    printf("gånger Strömmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
    double r, i;
    printf("Skriv resistans R < 20 000ohm: \n ");
    scanf("%lf", &r);
    if(r > 20000)
    {
        printf("för högt värde, försök igen: \n");
    }

    printf("Skriv ström I < 440 Ampere: \n");
    scanf("%lf", &i);
    if(i > 440)
    {
        printf("för högt värde, försök igen: \n");
    }

    printf("%f V\n", calcOhmsLag(r, i));
}


void handleResTot(void)
{
    printf("Resistans sammankopplade i parallella kretsar är lika med 1 delat Resistans R total är lika med\n");
    printf("Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder tre resistanser.\n\n");
    double r1,r2,r3;
    printf("Skriv resistans R1 < 20 000ohm: \n ");
    scanf("%lf", &r1);
    if(r1 > 20000)
    {
        printf("för högt värde, försök igen: \n");
    }
    printf("Skriv resistans R2 < 20 000ohm: \n ");
    scanf("%lf", &r2);
    if(r2 > 20000)
    {
        printf("för högt värde, försök igen: \n");
    }
    printf("Skriv resistans R3 < 20 000ohm: \n ");
    scanf("%lf", &r3);
    if(r3 > 20000)
    {
        printf("för högt värde, försök igen: \n");
    }
    printf("%f Ohm\n", calcResTot(r1, r2, r3));
}



void handleEffEnk(void)
{
    printf("Effektlagen enkel för likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n");
    printf("gånger Strömmen I i Ampere(A): \n\n");
    double u, i;
    printf("Skriv spänningen U i volt(V): \n ");
    scanf("%lf", &u);
    printf("Skriv ström Ampere I < 440A: \n");
    scanf("%lf", &i);
    if(i > 440)
    {
        printf("för högt värde, försök igen: \n");
    }
    printf("%f W\n", calcEffEnk(u, i));
}




void handleSkenEff(void)
{
    printf("Skenbar effekt enfas räknas med storheten VA(VoltAmpere) som är lika med spänningen U i volt(V)\n");
    printf("gånger Strömmen I i ampere(A)\n\n");
    double u, i;
    printf("Skriv spänningen U i volt: \n ");
    scanf("%lf", &u);
    printf("Skriv ström I < 440A: \n");
    scanf("%lf", &i);
    if(i > 440)
    {
        printf("för högt värde, försök igen: \n");
    }
    printf("%f VA\n", calcSkenEff(u, i));
}



void handleAktivEff(void)
{
    printf("Aktiv medelefdekt enfas är lika med effekt P i watt(W) lika med spänningen U i volt(V) gånger Strömmen I \n");
    printf("i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n");
    double u, i, cos;
    printf("Skriv spänning U i volt: \n ");
    scanf("%lf", &u);
    printf("Skriv ström I: \n");
    scanf("%lf", &i);
    if(i > 440){
        printf("för högt värde, försök igen:\n");
    }
    printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
    scanf("%lf", &cos);
    if (cos < 0 && cos > 1)
    {
        printf("Fel värde, försök igen\n");
    }
    printf("%f W\n", calcAktivEff(u, i, cos));
}



void handleSken3Fas(void)
{
    printf("3-fas skenbar effekt är växelspänning är skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n");
    printf("gånger Strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n");
    double u, i;
    printf("Skriv spänning U i volt(V) < 400V: \n ");
    scanf("%lf", &u);
    if(u > 400)
    {
        printf("för högt värde, försök igen: \n");
    }

    printf("Skriv ström I i ampere < 440: \n");
    scanf("%lf", &i);
    if(i > 440)
    {
        printf("för högt värde, försök igen: \n");
    }
    printf("%f VA\n", calcSken3Fas(u, i));
}


void handleAktiv3Fas(void)
{
    printf("3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen U i volt(V) gånger Strömmen I i ampere(A)\n");
    printf("gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n");
    double u, i, cos;
    printf("Skriv spänningen U i volt(V): \n ");
    scanf("%lf", &u);
    if(u > 400)
    {
        printf("för högt värde, försök igen.\n");
    }
    printf("Skriv ström I i ampere(A): \n");
    scanf("%lf", &i);
    if(i > 440)
    {
        printf("för högt värde, försök igen.\n");
    }

    printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
    scanf("%lf", &cos);
    if (cos < 0 && cos > 1)
    {
        printf("för högt värde, försök igen: \n");
    }

    printf("%f W\n", calcAktiv3Fas(u ,i, cos));
}
