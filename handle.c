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
    printf("V\xE4lj vilka storheter du vill ber�kna:\n");
    printf("V\xE4lj 1 f\xF6r: OHMS LAG\n");
    printf("V\xE4lj 2 f\xF6r: Rtot\n");
    printf("V\xE4lj 3 f\xF6r: EFFEKTLAGEN ENKEL\n");
    printf("V\xE4lj 4 f\xF6r: SKENBAR EFFEKT ENFAS\n");
    printf("V\xE4lj 5 f\xF6r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
    printf("V\xE4lj 6 f\xF6r: SKENBAR EFFEKT 3-FAS\n");
    printf("V\xE4lj 7 f\xF6r: AKTIV EFFEKT 3-FAS\n");
    printf("V\xE4lj 0 f\xF6r: f\xF6r ATT AVSLUTA\n");
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
            printf("Fel alternativ f\xF6rs\xF6k igen!: \n");
            return 0;
    }
}

/*    Check if input is higer than allowed limit        */
int checkOverflow(double Input, int Limit)
{
    if (Input > Limit) {
        printf("f\xF6r h\xF6gt v\xE4rde, f\xF6rs\xF6k igen: \n");
        return 0;
    }
    else {
        return 1;
    }
}

/*    Handles Ohms law, input and output                */
void handleOhmsLag(void)
{
    printf("Ohms lag sp\xE4nningen(volt/V) ben\xE4mns U lika med Resistansen(Ohm) \nben\xE4mns R ");
    printf("g\xE5nger Str\xF6mmen(Ampere) ben\xE4mns  I. Kort U=R*I. \n\n");
    double r, i;
    printf("Skriv resistans R < 20 000ohm: \n ");
    scanf("%lf", &r);
    if (!(checkOverflow(r, 20000))) return;

    printf("Skriv str\xF6m I < 440 Ampere: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f V\n", calcOhmAndEff(r, i));
}

/*    Handles total resistance, input and output        */
void handleResTot(void)
{
    printf("Resistans sammankopplade i parallella kretsar \xE4r lika med 1 delat Resistans R total \xE4r lika med\n");
    printf("Resistans 1/R1 + 1/R2 + 1/R3 d\xE5 vi h\xF6gst anv\xE4nder tre resistanser.\n\n");
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
    printf("Effektlagen enkel f\xF6r likstr\xF6m \xE4r effekten P i Watt (W) lika med sp\xE4nningen U i volt(V)\n");
    printf("g\xE5nger Str\xF6mmen I i Ampere(A): \n\n");
    double u, i;
    printf("Skriv sp\xE4nningen U i volt(V): \n ");
    scanf("%lf", &u);
    printf("Skriv str\xF6m Ampere I < 440A: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f W\n", calcOhmAndEff(u, i));
}

/*    Handles apparent effect law, input and output     */
void handleSkenEff(void)
{
    printf("Skenbar effekt enfas r\xE4knas med storheten VA(VoltAmpere) som \xE4r lika med sp\xE4nningen U i volt(V)\n");
    printf("g\xE5nger Str\xF6mmen I i ampere(A)\n\n");
    double u, i;
    printf("Skriv sp\xE4nningen U i volt: \n ");
    scanf("%lf", &u);
    printf("Skriv str\xF6m I < 440A: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f VA\n", calcOhmAndEff(u, i));
}

/*    Handles active effect law, input and output     */
void handleAktivEff(void)
{
    printf("Aktiv medelefdekt enfas \xE4r lika med effekt P i watt(W) lika med sp\xE4nningen U i volt(V) g\xE5nger Str\xF6mmen I \n");
    printf("i Ampere g\xE5nger cosinus fi/efkektfaktor < 1:\n\n");
    double u, i, cos;
    printf("Skriv sp\xE4nning U i volt: \n ");
    scanf("%lf", &u);
    printf("Skriv str\xF6m I: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
    scanf("%lf", &cos);
    if (cos < 0 && cos > 1)
    {
        printf("Fel v\xE4rde, f\xF6rs\xF6k igen\n");
    }
    printf("%f W\n", calcAktivEff(u, i, cos));
}

/*    Handles apparent 3 phase, input and output     */
void handleSken3Fas(void)
{
    printf("3-fas skenbar effekt \xE4r v\xE4xelsp\xE4nning \xE4r skenbar effekt S i voltampere(VA) lika med sp\xE4nningen U i volt(V) \n");
    printf("g\xE5nger Str\xF6mmen I i ampere(A) g\xE5nger roten ur 3 SQRT(3).\n\n");
    double u, i;
    printf("Skriv sp\xE4nning U i volt(V) < 400V: \n ");
    scanf("%lf", &u);
    if (!(checkOverflow(u, 400))) return;


    printf("Skriv str\xF6m I i ampere < 440: \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;

    printf("%f VA\n", calcSken3Fas(u, i));
}

/*    Handles active 3 phase, input and output     */
void handleAktiv3Fas(void)
{
    printf("3-fas aktiv effekt \xE4r effekten P i Watt(W) lika med sp\xE4nningen U i volt(V) g\xE5nger Str\xF6mmen I i ampere(A)\n");
    printf("g\xE5nger cos < 1 && cos > 0 g\xE5nger roten ur 3 SQRT(3).\n\n");
    double u, i, cos;
    printf("Skriv sp\xE4nningen U i volt(V): \n ");
    scanf("%lf", &u);
    if (!(checkOverflow(u, 400))) return;

    printf("Skriv str\xF6m I i ampere(A): \n");
    scanf("%lf", &i);
    if (!(checkOverflow(i, 440))) return;


    printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
    scanf("%lf", &cos);
    if (cos < 0 && cos > 1)
    {
        printf("f\xF6r h\xF6gt v\xE4rde, f\xF6rs\xF6k igen: \n");
    }

    printf("%f W\n", calcAktiv3Fas(u ,i, cos));
}
