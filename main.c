/*
Detta program är en räknare som kan användas för ellära med enbart
växelspänningar och växelströmmar.
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
    system("cls");
    int Brakeout = 0;
    while (Brakeout == 0)
    {
        int val;
        printMenu();
        scanf("%d", &val);
        system("cls");
        Brakeout = handleMenu(val);
    }
}
