/**
  \brief solving roots of a function by iteration method
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/05/05 Last revised: 2020/05/05 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <math.h>

// the objective function
double phi(double x){
  return pow(1.+x*x, 1./3.);
}

int main(int argc, char **argv){
  // the search domain of x
  double x0 = 1, x1 = 2;
  double epsilon = 1e-5;
  // Nmax: the maximum count of iterations
  // k: the total times of iterations
  int Nmax = 100, k = 0;

  // the iteration //
  while(k < Nmax && fabs(x0-x1) > epsilon){
    x0 = x1;
    x1 = phi(x0);
    k++;
  } // end for over i


  printf("The program has iterated %d times.\n", k);
  printf("The obtained root is %10.8f\n", x1);
  printf("Bye.\n\n");

  return 0;
} // end of the main function
