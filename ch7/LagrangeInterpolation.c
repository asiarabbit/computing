/**
  \brief Lagrange Interplation method - algebraic interpolation
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/06/17 Last revised: 2020/06/17 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>

int main(){
  const int n = 5;
  double x[5] = {1., 2., 3., 4., 5.};
  double y[5] = {1., 4., 7., 8., 6.};

  double sum = 0., xx = 1.5; // xx: the interpolation point to evaluate at
  for(int i = 0; i < n; i++){ // the outer loop, for the summation
    double prod = 1.;
    for(int j = 0; j < n; j++){ // the inner loop, to do the multiplication
      if(j != i) prod *= (xx - x[j]) / (x[i] - x[j]);
    } // end of the inner loop
    sum += prod * y[i];
  } // end of the outer loop
  printf("The Lagrange interpolation result at x = %f is %10.8f.\n", xx, sum);

  return 0;
} // end of the main function
