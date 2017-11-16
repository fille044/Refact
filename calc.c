#include <math.h>
#include <limits.h>

/* Local libraries */
#include "calc.h"

double calcOhmsLag(double r, double i)
{
    double u = i * r;
    return u;
}



double calcResTot(double r1, double r2, double r3)
{
    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;
    return rtot;
}

double calcEffEnk(double u, double i)
{
    double p = u * i;
    return p;
}

double calcSkenEff(double u, double i)
{
    double s = u * i;
    return s;
}

double calcAktivEff(double u, double i, double cos)
{
    double p = u * i * cos;
    return p;
}


double calcSken3Fas(double u, double i)
{
    double s = u * i * sqrt(3);
    return s;
}


double calcAktiv3Fas(double u, double i, double cos)
{
    double p = u * i * sqrt(3) * cos;
    return p;
}
