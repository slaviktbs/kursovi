#include<stdio.h>
#include<math.h>


union Union_ALL
  {
    float y;
  };

int main() 
{
  float S_all, t_all, fuel_all, y;
  union Union_ALL union_pointer;

  S_all = 1.00;
  t_all = 2.00;
  fuel_all = 3.00;
  y = 0.00;


  for (int i=0; i<=2; i++)
  {
    if (i==0){
      union_pointer.y = S_all;
      printf(" S = %f\n",union_pointer.y);
    }

    else if (i==1){
      union_pointer.y = t_all;
      printf(" t = %f\n",union_pointer.y);
    }
    else if (i==2){
      union_pointer.y  = fuel_all;
      printf(" fuel = %f\n",union_pointer.y);
    }
  }  
return 0;
}

  // union_pointer.S = S_all;
  // union_pointer.t = t_all;
  // union_pointer.fuel = fuel_all;


  // printf("%f\n", union_pointer.S);
  // printf("%f\n",union_pointer.t);
  // printf("%f\n",union_pointer.fuel);
 
/*
    
    int arr[]={1,2,3,4,5};   //array initialization
    cout<<"The elements are: ";
    for(int i : arr)
    {
    	cout<<i<<" ";
    }
    */

/*
    float a[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float *p;
    p = a;     /*на p се присвояава адреса на началото на а*/
/*така се отпечатват първия, втория
и третия елемент на а    // УКАЗАТЕЛИ !!! ЛЕСНО ЗА МАСИВИ ATM...

    printf("%f %f %f\n", *p, *(p+1), *(p+2)); /*това извършва същото но използва а*/
  //  printf("%f %f %f\n", a[0], a[1], a[2]); */

  //   double x,y,result_PO, result_SQ;
  //   scanf("%lf",&x);
  //   scanf("%lf",&y);

  //   result_PO = pow(x,y);
  //   result_PO = pow(2,3);
  // //  result_SQ = sqrtf(x);
  // //  result_SQ = sqrtf(2);
  //  result_SQ = log(2);

  //  // result_PO = 2*2*2;
  //  // result_SQ = pow(x,y);
  //  //result_SQ = exp(x);

  //   printf("%lf\n%lf\n", result_PO,result_SQ);


 // float S_all, t_all, fuel_all;
  

