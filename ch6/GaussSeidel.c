/**
  \brief solving linear equation set using Gauss-Seidel iteration method
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/05/26 Last revised: 2020/05/26 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

// show the matrix A
// nrow: number of rows; ncolumn: number of columns
void ShowMatrix(const double *A, const int ncol, const int nrow);
// give the infinity norm of vector x: max|x_i|
double maxAbs(double *x, int len);

int main(){
  const int n = 3; // the dimension of the coefficient matrix
  double A[3][3] = {
    { 5.,  2.,  1.},
    {-1.,  4.,  2.},
    { 2., -3., 10.}
  };
  double b[3] = { // the constant vector
     -12.,  20.,  3.
  };
  double x[] = {0.,0.,0.}; // x: x^((k))
  const double em = 1e-5; // error tolerance
  double e = 1.e200, ev[3]; // ||ev=x^((k)) - x^((k-1))||_\infty
  int Nmax = 100, k = 0; // the maximum iteration times and the iteration count

  // start the iteration routine //
  while(e > em && k <= Nmax){
    memcpy(ev, x, sizeof(x)); // store the x^((k-1)) vector in ev
    for(int i = 0; i < n; i++){ // loop over x_i
      // x^((k+1)) = (bi-\sum{aij*xj}/aii
      x[i] = b[i];
      for(int j = 0; j < n; j++) if(j != i) x[i] -= A[i][j] * x[j];
      x[i] /= A[i][i];
      ev[i] -= x[i]; // the error vector: x^((k)) - x^((k-1))
    } // end for over i
    e = maxAbs(ev, 3);
    printf("The solution and error vectors for the %d-th iteration:\n", k);
    ShowMatrix(x, n, 1);
    ShowMatrix(ev, n, 1);
    printf("e=||ev||_\\infty=%.3g\n", e);
    getchar();
    k++;
  } // end while

  printf("\n\nThe final solution and error vectors:\n");
  ShowMatrix(x, n, 1);
  ShowMatrix(ev, n, 1);
  return 0;
} // end of the main function


void ShowMatrix(const double *A, const int ncol, const int nrow){
  for(int i = 0; i < nrow; i++){
    for(int j = 0; j < ncol; j++){
      printf(" %10.4f", A[i*ncol+j]);
    } // end for over columns
    printf("\n");
  } // end loop over rows
  printf("\n");
  // getchar();
}
double maxAbs(double *x, int len){
  double m = fabs(x[0]), tmp;
  for(int i = 1; i < len; i++){
    tmp = fabs(x[i]);
    if(tmp > m) m = tmp;
  }
  return m;
}
