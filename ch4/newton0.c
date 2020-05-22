/**
  \brief solving roots of a function by Newton iteration method
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/05/21 Last revised: 2020/05/22 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <math.h>

// the objective function
double fun(double x){
  return x*x*x - x - 1.;
}
// calculate the first derivative f'(x)
double funPrime(double x){
  return 3.*x*x - 1.;
}

int main(){
  // the search domain of x
  double x0 = 1.5, x1 = newton(fun, x0);
  double epsilon = 1e-6;
  // Nmax: the maximum count of iterations
  // k: the total times of iterations
  int Nmax = 100, k = 0;

  // the iteration //
  while(k < Nmax && fabs(x0-x1) > epsilon){
    x0 = x1;
    x1 = x0 - fun(x0) / funPrime(x0);
    k++;
    printf("x0: %10.8f, |x1-x0|: %10.8f\n", x0, fabs(x1-x0));
    getchar();
  } // end for over i

  printf("The program has iterated %d times.\n", k);
  printf("The obtained root is %10.10f\n", x1);
  printf("Bye.\n\n");

  return 0;
} // end of the main function
