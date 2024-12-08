/*
    Програмата пресмята расхода на горивото, време за пътуване от Земя до Луна/Марс
    от космодром "НАЗВАНИЕТО", със ракета Starship на кампанията SpaceX
    като исползва дани въведени от потребител: 
        дистинацията (destination)
        масата на товара (mass)
    също така използва даните за времето във космодром "НАЗВАНИЕ" (взима се от интернет, съхранява се във файла и се използва от програмата)
        
        
*/
#include <stdio.h>


int main(void)
{
    int first_choose;
    double mass, M_Starship, R_Eath, Lambda, g, Ro, k, S;
    float S_all, S_atmos, S_space, S_landing;
    float t_all, t_atmos, t_space, t_landing;
    float fuel_all, fuel_atmos, fuel_space, fuel_landing;
    long V_1, M_Eath;
    float G;

    printf ("Choose the destination: 1 - Moon \n");
    printf ("Choose the destination: 2 - Mars \n");
    scanf ("%d", &first_choose);


    printf ("Enter the mass of the product in kg: \n");
    scanf ("%lf", &mass);


/*
    Започва да се пресмята време за пътуване, като се отчитат климатичните условия
    в даден момент на 
*/

    S_all = S_atmos + S_space + S_landing;
    t_all = t_atmos + t_space + t_landing;
    fuel_all = fuel_atmos + fuel_space + fuel_landing;
    S_atmos = 50000;
    R_Eath = 6378000;
    M_Starship = 4*10^6;
    V_1 = 7800;
    Lambda = 50200000;
  //G = 6.67430*10^-11;
    G = 0.0000000000667430;
    g = 9.8;
 // M_Eath = 5.9722*10^24;
    M_Eath = 59722*10^20;
    Ro = 1.2754;  // плотность воздуха
    k = 0.5;  // Коэфициент сопротивления формы грубо
    S = 3; //площадь поперечного сечения !! очень грубо пока !!!

// Пресмятане на първата част от пътя: атмосферата

    if (first_choose == 1)  // Потребителя е избрал за дестинация Луната
    {
        t_atmos = (2*S_atmos)/V_1;

        fuel_atmos=((M_Starship+mass)*g*R_Eath-0.5*(M_Starship+mass)*(V_1^2)-(M_Starship+mass)*G*M_Eath-0.5*Ro*k*S*(V_1^2)*S_atmos)/Lambda;

    }

    else if (first_choose == 2)  // Потребителя е избрал за дестинация Марс
    {
       t_atmos = (2*S_atmos)/V_1;

       fuel_atmos=((M_Starship+mass)*g*R_Eath-0.5*(M_Starship+mass)*(V_1^2)-(M_Starship+mass)*G*M_Eath-0.5*Ro*k*S*(V_1^2)*S_atmos)/Lambda;
    } 
printf ("The time of the flight in atmosphere is: %f seconds\n", t_atmos);
printf ("The fuel consumption per atmosphere is: %f kilograms\n", fuel_atmos);


// трябва да напиша функция за масса: M_Starship + mass



// Пресмятане на втората част от пътя: космоса, далеч от планетите

    if (first_choose == 1)
    {
        S_space = ;

        t_space = ;

        fuel_space = ;

    }

    else if (first_choose == 2)
    {
        S_space = ;

        t_space = ;

        fuel_space = ;

    }
printf ("The time of the flight in space is: %f seconds\n", t_space);
printf ("The fuel consumption per space is: %f kilograms\n", fuel_space);

// Пресмятане на третата част от пътя: космоса, близо до втората планета така, 
// че ракетата трябва да се забавя, за да спре


    if (first_choose == 1)
    {
        S_landing = ;

        t_landing = ;

        fuel_landing = ;

    }

    else if (first_choose == 2)
    {
        S_landing = ;

        t_landing = ;

        fuel_landing = ;

    }
printf ("The time of the flight in landing is: %f seconds\n", t_landing);
printf ("The fuel consumption per landing is: %f kilograms\n", fuel_landing);


printf ("The total distance of the flight is: %f \n meters", S_all);
printf ("The total time of the flight is: %f \n seconds", t_all);
printf ("The fuel consumption of the flight is: %f \n kilograms of liquid methane", fuel_all);
}