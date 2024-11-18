/*
    Програмата пресмята расхода на горивото, време за пътуване от Земя до Луна/Марс
    от космодром "НАЗВАНИЕТО",
    като исползва дани въведени от потребител: 
        дистинацията (destination)
        масата на товара (mass)
    също така използва даните за времето във космодром "НАЗВАНИЕ" (взима се от интернет, съхранява се във файла и се използва от програмата)
        
        
*/
#include <stdio.h>


int main(void)
{
    int first_choose;
    float mass;
    float S_all, S_atmos, S_space, S_landing;
    float t_all, t_atmos, t_space, t_landing;
    float fuel_all, fuel_atmos, fuel_space, fuel_landing;

    printf ("Choose the destination: Moon (1) or Mars (2) \n");
    printf ("Click 1 or 2 to choose it \n");
    scanf ("%d", &first_choose);
    printf ("You have chosen: %d", first_choose);


    printf ("Enter the mass of the product in kg: \n");
    scanf ("%lf", &mass);
    printf ("Your entered mass: %lf", mass);


/*
    Започва да се пресмята време за пътуване, като се отчитат климатичните условия
    в даден момент на 
*/

    S_all = S_atmos + S_spac + S_landing;
    t_all = t_atmos + t_space + t_landing;
    fuel_all = fuel_atmos + fuel_space + fuel_landing;
    S_atmos = 50000;
    S_landing = ;

    if (first_choose == 1)  // Потребителя е избрал за дестинация Луната
    {
        S_space = 
/*
    От кинематика (без отчитане на съпротивление на въздуха) знаем,
    че 
*/

    }

    else if (first_choose == 2)  // Потребителя е избрал за дестинация Марс
    {
        S_space =
    }    
}