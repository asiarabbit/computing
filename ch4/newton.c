/**
  \brief solving roots of a function by Newton iteration method
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/05/19 Last revised: 2020/05/19 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <math.h>

// the objective function
double fun(double x){
  return x*x*x - x - 1.;
}
// calculate the first derivative f'(x) with Richardson extrapolation
double funPrime(double(*fun)(double), double x);
// newton iterative formula
double newton(double(*fun)(double), double x){
  return x - fun(x)/funPrime(fun, x); // the newton iterative formula
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
    x1 = newton(fun, x0);
    k++;
    printf("x0: %10.8f, |x1-x0|: %10.8f\n", x0, fabs(x1-x0));
    getchar();
  } // end for over i

  printf("The program has iterated %d times.\n", k);
  printf("The obtained root is %10.8f\n", x1);
  printf("Bye.\n\n");

  return 0;
} // end of the main function

// first partial derivative of function double fun(double)
double funPrime(double(*fun)(double), double x){
	double h = 1E-6, h2 = 2.*h; // the step
  // Dh = (f(p+h) - f(p-h))/(2*h)
	double Dh = (fun(x+h) - fun(x-h))/(2.*h);
  // D2h = (f(p+2h) - f(p-2h))/(2*h)
	double D2h = (fun(x+h2) - fun(x-h2))/(2.*h2);

	return (4.*Dh-D2h) / 3.; // Richardson extrapolation ~o(h^2)
}
