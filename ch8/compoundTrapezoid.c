/**
  \brief Numerical integral using compound trapezoid rule
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/06/17 Last revised: 2020/06/17 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <stdlib.h>

// integral of f(x) over domain [x[0],x[n-1]]. n is the length of x and f
// composed with formula (8.3.6) p.212 Computing Method ver.3 by Guicheng Li
double trapezoid(int n, double *x, double *f);

int main(){
  const int n = 9;
  double x[9] = {0., 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1.};
  double y[9] = {1., 0.9973978, 0.9896158, 0.9767267, 0.9588510,
                     0.9361556, 0.9088516, 0.8771925, 0.8414709};
  double s = trapezoid(n, x, y);

  printf("Integral with compund trapezoid rule is %10.10f\n", s);

  return 0;
}



// integral of f(x) over domain [x[0],x[n-1]]. n is the length of x and f
// composed with formula (8.3.6) p.212 Computing Method ver.3 by Guicheng Li
double trapezoid(int n, double *x, double *f){

  double sum = f[0] + f[n-1];
  for(int i = 1; i < n - 1; i++) sum += 2.*f[i];

  const double h = (x[n-1] - x[0]) / (n - 1);
  if(n < 0){
    printf("Array x should be in ascending order!!!\n");
    printf("Exiting...\n");
    exit(1);
  }
  sum *=  h / 2.;

  return sum;
}
