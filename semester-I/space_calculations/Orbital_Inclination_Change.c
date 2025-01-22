/* The program calculates the orbital inclination change (Problem 2 of the third presentation) with calculations made in the SI system.  */

#include <stdio.h>
#include <math.h>

double m_func_par (double a)
{
    return a*1000;
}

double deg_to_rad (double alpha)
{
    return alpha*(M_PI/180);
}

int main(void)
{
    double delta_v_norm, delta_v_neg, delta_V, V, v_orig, alpha, a, mu;

    mu = 398600441999999.0;

    printf ("\tEnter the radius of the parking orbit (in km): ");    // The user enters a_par 
    scanf ("%lf", &a);

    a = m_func_par(a);

    printf ("\tEnter the angle setting the desired inclination change (in degrees): ");    // The user enters alpha
    scanf ("%lf", &alpha);

    alpha = deg_to_rad(alpha);

    V = sqrt(mu/a);  // да реша със VisViva

    delta_v_norm = v_orig*sin(alpha);

    delta_v_neg = (-1.0)*v_orig*(1-cos(alpha));

    delta_V = sqrt(delta_v_norm*delta_v_norm + delta_v_neg*delta_v_neg);

    printf ("\tDelta V = %lf m/s\n", delta_V);
    
    printf ("\tThe normal component = %lf m/s\n", delta_v_norm);

    printf ("\tThe negative component = %lf m/s\n", delta_v_neg);
    
    return 0;
}