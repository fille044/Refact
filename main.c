
/*
Detta program är en räknare som kan användas för ellära med enbart
växelspänningar och växelströmmar.
Räknaren tar upp räkning med spänningar i volt(U), resistanser upp till 20 000/ohm(R).
Ström upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V
mellan faserna.
även tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas
och enfas där cosinus fi/cosinus() används
som effektfaktorn som är mindre än 1 och inte mindre än 0.
Frekvenser i (Hz):  och totala motståndet i parallellkopplade kretsar med max 3
motstånd.

50 Hertz(Hz) Finns det i våra uttag i sverige Vid 50 Hz byter spänningen
polaritet och Strömmen riktning 100 gånger per
sekund.
spänningen i svenska eluttag pendlar upp och ner från -325 V till +325 V.
Att vi talar om 230 V beror på att det är spänningens(växelström ~)
effektivvärde eller roten ur.
spänningen V(U)=Toppvärdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: spänning i volt(U)=Resistans i ohm(R)*ström i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL för likström: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()
*/


/* General defines */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Local libraries */
#include "handle.h"
#include "calc.h"


void main()
{
    system("chcp 1252");
    system("cls");
    int Brakeout = 0;
    while (Brakeout == 0)
    {
        int val;
        printMenu();
        scanf("%d", &val);
        Brakeout = handleMenu(val);
    }
}
