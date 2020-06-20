/**
  \brief Numerical integral using Romberg algorithm
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/06/17 Last revised: 2020/06/17 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// the integrated function
double f(double x);

int main(){
  double a = 0., b = 1., epsilon = 1e-20;
  double h = b - a;
  int k = 1; // times of range halfing + 1
  // T1-2: trapezoid integral; S1-2: Simpson integral
  // C1-2: Cotes integral; R1-2: Romberg integral
  double T1, T2, S1, S2, C1, C2, R1, R2;
  T1 = h / 2. * (f(a) + f(b));

  while(1){
    double sum = 0.; // T_{2n} = T_{n} / 2. + h/2 * sum, sum=\sum{f(xi_1/2)}
    double xx = a + h / 2.;
    while(xx < b){
      sum += f(xx);
      xx += h;
    }
    T2 = (T1 + sum * h) / 2.;
    S2 = T2 + (T2 - T1) / 3.;
    // half the step, and calculate T and S again //
    if(1 == k){
      T1 = T2; S1 = S2;
      h /= 2.; k++;
    } // end if(1 == k)
    else{
      C2 = S2 + (S2 - S1) / 15.;
      if(2 == k){
        T1 = T2; S1 = S2; C1 = C2;
        h /= 2.; k++;
      }
      else{
        R2 = C2 + (C2 - C1) / 63.;
        if(k >= 3){
          T1 = T2; S1 = S2; C1 = C2; R1 = R2;
          h /= 2.; k++;
        }
        if(k >= 4){ // R2 and R1 have both been assigend
          printf("\n\nR1 = %4.15f, R2 = %4.15f\n\n", R1, R2); // DEBUG
        }
        if(k >= 4 && fabs(R1 - R2) < epsilon) break;
      } // end of the inner else
    } // end of the outer else
  } // end the outer while

  int kk = int(pow(2, k-3)); // the final Romberg order
  printf("|R%d-R%d|=%6.10f\n", kk/2, kk, fabs(R1 - R2));
  printf("R%d=%6.10f\n", kk, R2);

  return 0;
} // end of the main function


// the objective function
double f(double x){
  if(fabs(x) < 1.e-6) return 1.;
  return sin(x) / x;
}
