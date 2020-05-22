/**
  \brief solving roots of a function by dichotomy
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/05/04 Last revised: 2020/05/14 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// the objective function
// f(x) = 0 
double fun(double x){
  return sin(x) - x*x/4.;
}

int main(){
  // [a,b] is the initial search domain //
  double a = 1.5, b = 2.;
  // tolerated errors for x (epsilon0) and f(x) (epsilon1)
  double epsilon0 = 1e-2, epsilon1 = 1e-3;
  int Nmax = 100; // the maximum iteration times
  double fa = fun(a), fb = fun(b); // f(a), f(b)
  double m = (a + b) / 2.;
  // prepare for the iterations //
  int k = 0; // the iteration number

  // start the iteratons //
  while(fabs(a - b) > epsilon0 && k < Nmax){
    m = (a + b) / 2.;
    fb = fun(m); // SUPPOSE m is the end of the new search domain
    if(fabs(fb) < epsilon1) break;

    // reset the search domain
    if(fb * fa < 0.) b = m; // confirm the ASSUMPTION
    else{ // ASSUMPTION failed, a set as the end of the new search domain
      a = m;
      fa = fb;
    }
    k++;
    printf("m: %10.8f\n", m);
    getchar();
  } // end while


  printf("The program has iterated %d times.\n", k);
  printf("The obtained root is f(%10.8f) = %10.8f\n", m, fun(m));
  printf("Bye.\n\n");

  return 0;
} // end of the main function
