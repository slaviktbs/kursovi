/* The program calculates the phase transfer (Problem 2 of the fourth presentation) with calculations made in the SI system. */


#include <stdio.h>
#include <math.h>

double m_func_par (double a_par)
{
    return a_par*1000;
}

double m_func_tar (double a_tar)
{
    return a_tar*1000;
}

int main(void)
{
    double mu, v_par, a_par, v_tr_per_1, v_tr_per_2, v_tr_apo_1, v_tr_apo_2, v_tar, a_tar, a_tr_1, a_tr_2, delta_v_1, delta_v_2, delta_v_3, f;

    mu = 398600441999999.0;
    // a_par = 7000 km;

    printf ("\tEnter the radius of the parking orbit (in km): ");    // The user enters a_par 
    scanf ("%lf", &a_par);

    return 0;
}