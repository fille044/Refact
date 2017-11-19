/* General defines */
#include <math.h>
#include <limits.h>

/* Local libraries */
#include "calc.h"


/*    if Ohm:     a = I, b = R, c = U               */
/*    if Effect:  a = U, b = I, c = P or S          */
double calcOhmAndEff(double a, double b)
{
    double sum = a * b;
    return sum;
}

/*    Calculate total resistance                    */
double calcResTot(double r1, double r2, double r3)
{
    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;
    return rtot;
}

/*    Calculate active Effect                       */
double calcAktivEff(double u, double i, double cos)
{
    double p = u * i * cos;
    return p;
}

/*    Calculate apparent 3 phase effect                      */
double calcSken3Fas(double u, double i)
{
    double s = u * i * sqrt(3);
    return s;
}

/*    Calculate active 3 phase effect               */
double calcAktiv3Fas(double u, double i, double cos)
{
    double p = u * i * sqrt(3) * cos;
    return p;
}
