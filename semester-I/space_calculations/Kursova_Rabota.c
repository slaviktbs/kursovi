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
    double mass, M_Starship, R_Eath, R_Moon, R_Mars, Lambda, g, Ro, k, S;
    float S_all, S_atmos, S_space, S_landing;
    float t_all, t_atmos, t_space, t_landing;
    float fuel_all, fuel_atmos, fuel_space, fuel_landing;
    long V_1, M_Eath, v_space, m_space, m_landing, M_Moon, M_Mars;
    float G;
    char details;

    printf ("Choose the destination: 1 - Moon \n");
    printf ("Choose the destination: 2 - Mars \n");
    scanf ("%d", &first_choose);


    printf ("Enter the mass of the product in kg: \n");
    scanf ("%lf", &mass);


/*
    Започва да се пресмята време за пътуване, като се отчитат климатичните условия
    в даден момент на 
*/

    S_atmos = 50000;
    S_landing = 40000;
    R_Eath = 6378000;
    R_Moon = 1737000;
    R_Mars = 3390000;
    M_Starship = 4*10^6;
    V_1 = 7800;
    Lambda = 50200000;
  //G = 6.67430*10^-11;
    G = 0.0000000000667430;
    g = 9,8;
 // M_Eath = 5.9722*10^24;
    M_Eath = 59722*10^20;
    M_Moon = 735*10^20;
    M_Mars = 6417*10^20;
    Ro = 1.2754;  // плотность воздуха
    k = 0.5;  // Коэфициент сопротивления формы грубо
    S = 3; //площадь поперечного сечения !! очень грубо пока !!!
    v_space = 7222,2;  // Скоростта на ракета в космоса

 

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


// трябва да напиша функция за масса: M_Starship + mass



// Пресмятане на втората част от пътя: космоса, далеч от планетите

    if (first_choose == 1)
    {
        S_space = 384400000 - S_atmos - S_landing - R_Eath - 1737400;

        t_space = S_space/v_space;

        m_space = M_Starship + mass - fuel_atmos;

//      fuel_space = (m_space*g*(R_Eath+S_atmos)+0.5*m_space*(V_1^2)-0.5*m_space*(v_space^2))/(Lambda);

        fuel_space = (75000000*S_space)/Lambda;
    }

    else if (first_choose == 2)
    {
        S_space = 225000000000 - S_atmos - S_landing - R_Eath - 3389000;

        t_space = S_space/v_space;

        m_space = M_Starship + mass - fuel_atmos;

//      fuel_space = (m_space*g*(R_Eath+S_atmos)+0.5*m_space*(V_1^2)-0.5*m_space*(v_space^2))/(Lambda);

        fuel_space = (75000000*S_space)/Lambda;
    }


// Пресмятане на третата част от пътя: космоса, близо до втората планета така, 
// че ракетата трябва да се забавя, за да спре


    if (first_choose == 1)
    {
        t_landing = (2*S_landing)/v_space;

       m_landing = M_Starship + mass - fuel_atmos - fuel_space;

        fuel_landing = ((m_landing*M_Moon*G)/R_Moon - 0,5*m_landing*(v_space^2) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;

    }

    else if (first_choose == 2)
    {
        t_landing = (2*S_landing)/v_space;

        fuel_landing = ((m_landing*M_Mars*G)/R_Mars - 0,5*m_landing*(v_space^2) + m_landing*M_Mars*G/(R_Mars+S_landing))/Lambda;;
    }

     S_all = S_atmos + S_space + S_landing;
    t_all = t_atmos + t_space + t_landing;
    fuel_all = fuel_atmos + fuel_space + fuel_landing;

    printf ("The total distance of the flight is: %f  meters \n", S_all);

    printf ("The total time of the flight is: %f  seconds \n", t_all);

    printf ("The fuel consumption of the flight is: %f  kilograms of liquid methane \n", fuel_all);



    printf("If you want to see a details, press d or D \t \n");
    printf("If you don't want to, press e or E\n");
    scanf ("%ch", &details);

    if (details == "d" || details == "D")
    {
        printf ("The journey is divided into 3 parts: atmosphere, space and landing \n");
        printf ("");

        printf ("The time of the flight in atmosphere is: %f seconds \n", t_atmos);
        printf ("The fuel consumption per atmosphere is: %f kilograms \n", fuel_atmos);
        printf ("");
   
        printf ("The time of the flight in space is: %f seconds \n", t_space);
        printf ("The fuel consumption per space is: %f kilograms \n", fuel_space);

        printf ("The time of the flight in landing is: %f seconds \n", t_landing);
        printf ("The fuel consumption per space is: %f kilograms \n", fuel_landing);
    }
    else if (details == "e" || details == "E")
    {
        printf ("Bye bue");
    }

    return 0;
}


// Ошибка в формулах !!! Очень большие числа !!

// !!! Пересчитать все вычисления на калькуляторе, лучше на  MAPLE !! на всякий случай !!!