/**
  \brief Numerical integral using compound Simpson's rule
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/06/17 Last revised: 2020/06/17 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <stdlib.h>

// integral of f(x) over domain [x[0],x[n-1]]. n is the length of x and f
// composed with formula (8.3.6) p.212 Computing Method ver.3 by Guicheng Li
double simpson(int n, double *x, double *f);

int main(){
  const int n = 9;
  double x[9] = {0., 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1.};
  double y[9] = {1., 0.9973978, 0.9896158, 0.9767267, 0.9588510,
                     0.9361556, 0.9088516, 0.8771925, 0.8414709};
  double s = simpson(n, x, y);

  printf("Integral with compund Simpson's rule is %10.10f\n", s);

  return 0;
}



// integral of f(x) over domain [x[0],x[n-1]]. n is the length of x and f
// composed with formula (8.3.6) p.212 Computing Method ver.3 by Guicheng Li
double simpson(int n, double *x, double *f){
  // number of individual Simpson intervals
  int k = (n - 1) / 2; // f[n-1] is dropped in the case where n is even

  double sum = f[0] + f[2*k];
  for(int i = 0; i < k; i++) sum += 4.*f[2*i+1];
  for(int i = 1; i < k; i++) sum += 2.*f[2*i];

  const double h = (x[n-1] - x[0]) / (n - 1);
  if(n < 0){
    printf("Array x should be in ascending order!!!\n");
    printf("Exiting...\n");
    exit(1);
  }
  sum *=  h / 3.;
  // Simpson's rule is only for odd n
  // otherwise integral of f[n-1]*h should be explicitly included
  if(n % 2 == 0) sum += f[n-1] * h;

  return sum;
}
