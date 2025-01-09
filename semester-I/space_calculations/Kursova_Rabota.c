/*
    Програмата пресмята расхода на горивото, време за пътуване от Земя до Луна/Марс, със ракета Starship на кампанията SpaceX, като исползва дани въведени от потребител: 
        дистинацията (destination)
        масата на товара (mass)
    ** също така използва даните за времето в космодром "НАЗВАНИЕ" (взима се от интернет, съхранява се във файла и се използва от програмата)
        
        
*/

#include <stdio.h>
#include<math.h>

float mass_func (float M_Starship, float mass)
    {
        return M_Starship + mass;
    }

int main(void)
{
    int first_choose, details;

    float mass, M_Starship, R_Moon, R_Mars, Lambda, g, Ro, k, S, V_1, v_space, m_space, m_landing, M_Moon, M_Mars, G, S_all, S_space, S_atmos, S_landing, M_Eath, t_all, t_atmos, t_space, t_landing, t_all_min, t_all_hour, fuel_all, fuel_atmos, fuel_space, fuel_landing, *u_ATMOS, *u_SPACE, *u_LANDING, *u_ALL;
    const float R_Eath = 6378000;;

    float ATPOSPHERE[3];
    float LANDING[3];
    float SPACE[3];
    float ALL[3];

    printf ("Welcome to interplanetary travel ! \n\n");

    printf ("Choose the destination: \n");
    printf ("\t 1 - Moon \n");
    printf ("\t 2 - Mars \n\n");
    printf ("To chouse press 1 or 2 \n");
    scanf ("%d", &first_choose);


    printf ("\nEnter the mass of the product you want to send on the destination (in kg): \n");
    scanf ("%f", &mass);


    S_atmos = 150000;
    S_landing = 40000;
    R_Moon = 1737000;
    R_Mars = 3390000;
    M_Starship = 4000000;
    V_1 = 7910;
    Lambda = 50200000;
  //G = 6.67430*10^-11;
  //G = 0.0000000000667430  
    G = 6.6743E-11;   // !! CAN CHANGE VALUE !!
 // G = 66743*0.0001;
 // G = 66743*10^-15;
    g = 98E-1;
    M_Eath = 59722*10^20;
    M_Moon = 7.35E22;
  //M_Mars = 6.417E23;
    M_Mars = 6417*10^20;
//  Ro = 1.2754;  // плотность воздуха
    Ro = 12754*0.0001;
    k = 0.5;  // Коэфициент сопротивления формы грубо
    S = 3; //площадь поперечного сечения !! очень грубо пока !!!
 // v_space = 1444.44;  // Скоростта на ракета в космоса
    v_space = 144444*0.01;
// Пресмятане на първата част от пътя: атмосферата

    if (first_choose == 1)  // Потребителя е избрал за дестинация Луната
    {
        t_atmos = (2*S_atmos)/V_1;

        fuel_atmos=(mass_func(M_Starship, mass)*g*R_Eath-0.5*mass_func(M_Starship, mass)*(V_1*V_1)-mass_func(M_Starship, mass)*G*M_Eath-0.5*Ro*k*S*(V_1*V_1)*S_atmos)/Lambda;
        //fuel_atmos=5;
    }

    else if (first_choose == 2)  // Потребителя е избрал за дестинация Марс
    {
       t_atmos = (2*S_atmos)/V_1;

       fuel_atmos=(mass_func(M_Starship, mass)*g*R_Eath-0.5*mass_func(M_Starship, mass)*(V_1*V_1)-mass_func(M_Starship, mass)*G*M_Eath-0.5*Ro*k*S*(V_1*V_1)*S_atmos)/Lambda;
        //fuel_atmos=6;
    }

    ATPOSPHERE[0] = S_atmos;
    ATPOSPHERE[1] = t_atmos;
    ATPOSPHERE[2] = fuel_atmos;


// Пресмятане на втората част от пътя: космоса, далеч от планетите

    if (first_choose == 1)
    {
        S_space = 384400000 - S_atmos - S_landing - R_Eath - 1737400;

        t_space = S_space/v_space;

        m_space = mass_func(M_Starship, mass) - fuel_atmos;

       fuel_space = (m_space*g*(R_Eath+S_atmos)+0.5*m_space*(V_1*V_1)-0.5*m_space*(v_space*v_space))/(Lambda);

    }

    else if (first_choose == 2)
    {
        S_space = 225000000000 - S_atmos - S_landing - R_Eath - 3389000;

        t_space = S_space/v_space;

        m_space = mass_func(M_Starship, mass) - fuel_atmos;     // 1590080

       fuel_space = (m_space*g*(R_Eath+S_atmos)+0.5*m_space*(V_1*V_1)-0.5*m_space*(v_space*v_space))/(Lambda);      

    }

    SPACE[0] = S_space;
    SPACE[1] = t_space;
    SPACE[2] = fuel_space;


// Пресмятане на третата част от пътя: космоса, близо до втората планета така, 
// че ракетата трябва да се забавя, за да спре


    if (first_choose == 1)
    {
        t_landing = (2*S_landing)/v_space;

        m_landing = mass_func(M_Starship, mass) - fuel_space;

        fuel_landing = ((m_landing*M_Moon*G)/R_Moon - 0.5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
        
        //fuel_landing = (0,5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
    }

    else if (first_choose == 2)
    {
        t_landing = (2*S_landing)/v_space;

        fuel_landing = ((m_landing*M_Mars*G)/R_Mars - 0.5*m_landing*(v_space*v_space) + m_landing*M_Mars*G/(R_Mars+S_landing))/Lambda;;
        
        //fuel_landing = (0,5*m_landing*(v_space*v_space) + m_landing*M_Moon*G/(R_Moon+S_landing))/Lambda;
    }

    LANDING[0] = S_landing;
    LANDING[1] = t_landing;
    LANDING[2] = fuel_landing;

    
    S_all = S_atmos + S_space + S_landing;
    t_all = t_atmos + t_space + t_landing;
    fuel_all = fuel_atmos + fuel_space + fuel_landing;

    ALL[0] = S_all;
    ALL[1] = t_all;
    ALL[2] = fuel_all;

    u_ATMOS = ATPOSPHERE;
    u_SPACE = SPACE;
    u_LANDING = LANDING;
    u_ALL = ALL;


    printf ("\n\n \t The total distance of the flight is: %f  meters \n", *u_ALL);
    
    printf ("\t The total time of the flight is: %f seconds\n", *(u_ALL+1));

    printf ("\t The fuel consumption of the flight is: %f  kilograms of liquid methane \n", *(u_ALL+2));

    printf("\nIf you want to see a details, press 1 \n");
    printf("If you don't want to, press 2 \n");
    scanf ("%d", &details);

    if (details == 1)
    {

// Лучше сделать указател като параметр на функция, преподу такое нравиться !!

        printf ("\n\tThe journey is divided into 3 parts: atmosphere, space and landing \n ");

        printf("About atmosphere : \n");

        printf ("\t The distance of the flight is: %f meters \n \t The time of the flight is: %f seconds \n \t The fuel consumption is: %f kilograms \n", *u_ATMOS, *(u_ATMOS+1), *(u_ATMOS+2));

        printf("About space : \n");
        printf ("\t The distance of the flight is: %f meters \n \t The time of the flight is: %f seconds \n \t The fuel consumption is: %f kilograms \n", *u_SPACE, *(u_SPACE+1), *(u_SPACE+2));

        printf("About landing : \n");
        printf ("\t The distance of the flight is: %f meters \n \t The time of the flight is: %f seconds \n \t The fuel consumption is: %f kilograms \n", *u_LANDING, *(u_LANDING+1), *(u_LANDING+2));

    }
    else if (details == 2)
    {
        printf ("\nBye bue \n\n");
    }

    return 0;
}


/*

    Добавить СТЕПЕНЬ для скоростей (для math.h)



        ПРОВЕРИТЬ, КОНЕЧНО, ФОРМУЛЫ И РАСЧЕТЫ
        ПРОСЧИТАТЬ ВСЕ НА БУМАГЕ -> ПОЛУЧИТЬ ЧИСЛА (вычисления на калькуляторе, лучше на  MAPLE), СРАВНИТЬ С ЧИСЛАМИ В ПРОГРАММЕ
      
        СДЕЛАТЬ КОММЕНТАРИИ НА АНГЛИЙСКОМ



    
    Также лучше выдавать время в ч и мин, что удобнее -->> изменить немного код...

*/