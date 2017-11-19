/* General defines */
#include <stdio.h>
#include <stdbool.h>

/* Local libraries */
#include "handle.h"
#include "calc.h"


/*    Handles all output written to menu            */
void printMenu(void)
{
    printf("\n");
    printf("Välj vilka storheter du vill ber�kna:\n");
    printf("Välj 1 för: OHMS LAG\n");
    printf("Välj 2 för: Rtot\n");
    printf("Välj 3 för: EFFEKTLAGEN ENKEL\n");
    printf("Välj 4 för: SKENBAR EFFEKT ENFAS\n");
    printf("Välj 5 för: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
    printf("Välj 6 för: SKENBAR EFFEKT 3-FAS\n");
    printf("Välj 7 för: AKTIV EFFEKT 3-FAS\n");
    printf("Välj 0 för: för ATT AVSLUTA\n");
}


/*    Handles choices from menu                     */
int handleMenu(int val)
{
    switch (val) {
        case 0:
            return 1;
        case 1:
            handleOhmsLag();
            return 0;
        case 2:
            handleResTot();
            return 0;
        case 3:
            handleEffEnk();
            return 0;
        case 4:
            handleSkenEff();
            return 0;
        case 5:
            handleAktivEff();
            return 0;
        case 6:
            handleSken3Fas();
            return 0;
        case 7:
            handleAktiv3Fas();
            return 0;
        default:
            printf("Fel alternativ försök igen!: \n");
            return 0;
    }
}

/*    Check if input is higer than allowed limit        */
int checkOverflow(double Input, int Limit)
{
    if (Input > Limit) {
        printf("för högt värde, försök igen: \n");
        return 0;
    }
    else {
        return 1;
    }
}

/*    Handles Ohms law, input and output                */
void handleOhmsLag(void)
{
    printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n");
    printf("gånger Strömmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
    double r, i;
    printf("Skriv resistans R < 20 000ohm: \n ");
    scanf("%lf", &r);
    if (!(checkOverflow(r, 20000))) return;

    printf("Skriv ström I < 440 Ampere: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f V\n", calcOhmAndEff(r, i));
}

/*    Handles total resistance, input and output        */
void handleResTot(void)
{
    printf("Resistans sammankopplade i parallella kretsar är lika med 1 delat Resistans R total är lika med\n");
    printf("Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder tre resistanser.\n\n");
    double r1,r2,r3;
    printf("Skriv resistans R1 < 20 000ohm: \n ");
    scanf("%lf", &r1);
    if (!(checkOverflow(r1, 20000))) return;

    printf("Skriv resistans R2 < 20 000ohm: \n ");
    scanf("%lf", &r2);
    if (!(checkOverflow(r2, 20000))) return;

    printf("Skriv resistans R3 < 20 000ohm: \n ");
    scanf("%lf", &r3);
    if (!(checkOverflow(r3, 20000))) return;

    printf("%f Ohm\n", calcResTot(r1, r2, r3));
}

/*    Handles simple effect law, input and output       */
void handleEffEnk(void)
{
    printf("Effektlagen enkel för likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n");
    printf("gånger Strömmen I i Ampere(A): \n\n");
    double u, i;
    printf("Skriv spänningen U i volt(V): \n ");
    scanf("%lf", &u);
    printf("Skriv ström Ampere I < 440A: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f W\n", calcOhmAndEff(u, i));
}

/*    Handles apparent effect law, input and output     */
void handleSkenEff(void)
{
    printf("Skenbar effekt enfas räknas med storheten VA(VoltAmpere) som är lika med spänningen U i volt(V)\n");
    printf("gånger Strömmen I i ampere(A)\n\n");
    double u, i;
    printf("Skriv spänningen U i volt: \n ");
    scanf("%lf", &u);
    printf("Skriv ström I < 440A: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f VA\n", calcOhmAndEff(u, i));
}

/*    Handles active effect law, input and output     */
void handleAktivEff(void)
{
    printf("Aktiv medelefdekt enfas är lika med effekt P i watt(W) lika med spänningen U i volt(V) gånger Strömmen I \n");
    printf("i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n");
    double u, i, cos;
    printf("Skriv spänning U i volt: \n ");
    scanf("%lf", &u);
    printf("Skriv ström I: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
    scanf("%lf", &cos);
    if (cos < 0 && cos > 1)
    {
        printf("Fel värde, försök igen\n");
    }
    printf("%f W\n", calcAktivEff(u, i, cos));
}

/*    Handles apparent 3 phase, input and output     */
void handleSken3Fas(void)
{
    printf("3-fas skenbar effekt är växelspänning är skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n");
    printf("gånger Strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n");
    double u, i;
    printf("Skriv spänning U i volt(V) < 400V: \n ");
    scanf("%lf", &u);
    if (!(checkOverflow(u, 400))) return;


    printf("Skriv ström I i ampere < 440: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f VA\n", calcSken3Fas(u, i));
}

/*    Handles active 3 phase, input and output     */
void handleAktiv3Fas(void)
{
    printf("3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen U i volt(V) gånger Strömmen I i ampere(A)\n");
    printf("gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n");
    double u, i, cos;
    printf("Skriv spänningen U i volt(V): \n ");
    scanf("%lf", &u);
    if (!(checkOverflow(u, 400))) return;

    printf("Skriv ström I i ampere(A): \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;


    printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
    scanf("%lf", &cos);
    if (cos < 0 && cos > 1)
    {
        printf("för högt värde, försök igen: \n");
    }

    printf("%f W\n", calcAktiv3Fas(u ,i, cos));
}
