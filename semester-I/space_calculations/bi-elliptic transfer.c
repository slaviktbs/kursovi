/* The program calculates the orbital inclination change (Problem 2 of the third presentation) with calculations made in the SI system.  */

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
    double mu, v_par, a_par, v_tr_per, v_tr_apo, v_tar, a_tar, a_tr_1, delta_v, delta_v_2, f;

    mu = 398600441999999.0;
    // a_par = 7000 km; 
    // a_tar = 105000 km;
    // f = 2;

    printf ("\tEnter the radius of the parking orbit (in km): ");    // The user enters a_par 
    scanf ("%lf", &a_par);                   

    printf ("\tEnter the radius of the target orbit (in km): ");      // The user enters a_tar
    scanf ("%lf", &a_tar);

    printf ("\tEnter the transfer orbit factor: ");      // The user enters f
    scanf ("%lf", &f);

    a_par = m_func_par(a_par);
    a_tar = m_func_tar(a_tar);

    v_par = sqrt(mu/a_par);

    a_tr_1 = (a_tar*f+a_par)/2;


    
    
    return 0;
}