#include <stdio.h>

double Fib (int n)
{ if (n == 1)
    return 1;
  else if (n ==2)
    return (2);
    else return (Fib(n-1)+Fib(n-2));
 }       
 
 int main ()
 {  int X;
    double F;
      printf ("Entre com valor positivo inteiro > 0 e < ...\n");
      scanf ("%d" , & X); 
       if (X<1)
        printf ("Fora da Configuracao\n");
       else 
       { F = Fib(X);
          printf ("O Fibonacci de %d = %.2lf\n", X,F);
        }  
   return 0;
 }       
