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
  return x*x - 2.*x + 1.;
}
// calculate the first derivative f'(x)
double funPrime(double x){
  return 2.*x - 2;
}

int main(){
  // the search domain of x
  double x0 = 1.5, x1 = x0 - fun(x0) / funPrime(x0);
  double epsilon = 1e-5;
  // Nmax: the maximum count of iterations
  // k: the total times of iterations
  int Nmax = 100, k = 0;

  // the iteration //
  while(k < Nmax && fabs(x0-x1) > epsilon){
    x0 = x1;
    x1 = x0 - fun(x0) / funPrime(x0);
    k++;
    printf("The %d-th iteration, x0: %10.8f, |x1-x0|: %10.8f", k, x0, fabs(x1-x0));
    getchar();
  } // end for over i

  printf("\n\nThis code is written by Sun Yazhou.\n");
  printf("\nThe program has iterated %d times.\n", k);
  printf("The obtained root is %10.10f\n", x1);
  printf("Bye.\n\n");

  return 0;
} // end of the main function
