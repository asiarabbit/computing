/**
  \brief solving tridiagonal linear equation set with chasing method
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/05/22 Last revised: 2020/05/22 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <stdio.h>
#include <math.h>

// show the matrix A
// nrow: number of rows; ncolumn: number of columns
void ShowMatrix(double *A, const int nrow, const int ncol);

int main(){
  const int n = 4; // the dimension of the coefficient matrix
  double A[4][4] = {
    {4., 2., 0., 0.},
    {1., 4., 2., 0.},
    {0., 1., 4., 2.},
    {0., 0., 1., 4.}
    // {3., 1., 0., 0.},
    // {2., 3., 1., 0.},
    // {0., 2., 3., 1.},
    // {0., 0., 1., 3.}
  };
  double b[4] = { // the constant vector
    // 1., 0., 1., 0
    1., 2., 3., 4.
  };

  // CHASE //
  A[0][1] /= A[0][0]; // u1 = c1/l1
  // Notation: Ax = b <=> LUx = b <=> Ly=b, y=Ux //
  b[0] /= A[0][0]; // Ly=b => y_0 = b_0 / l_0
  for(int i = 1; i < n; i++){
    A[i][i] -= A[i][i - 1] * A[i - 1][i]; // l_i = b_i - a_i*u_(i-1)
    A[i][i + 1] /= A[i][i]; // u_i = c_i / l_i
    b[i] = (b[i]-A[i][i-1]*b[i-1]) / A[i][i]; // y_i = (b_i - a_i*y_(i-1)) / l_i
  } // end for over i
  printf("After LU factorization, A = LU (L\\U): \n");
  ShowMatrix(A[0], n, n);
  ShowMatrix(b, n, 1);
  getchar();

  // solve x with Ux=y: CHASE BACK //
  for(int i = n - 1; i >= 0; i--) b[i] -= A[i][i + 1] * b[i + 1];


  printf("\n\nThe solution to the linear equation set is {%10.8f", b[0]);
  for(int i = 1; i < n; i++) printf(", %10.8f", b[i]);
  printf("}\n\nBye.\n\n");

  return 0;
} // end of the main function

void ShowMatrix(double *A, const int nrow, const int ncol){
  for(int i = 0; i < nrow; i++){
    for(int j = 0; j < ncol; j++){
      printf(" %10.4f", A[i*ncol+j]);
    } // end for over columns
    printf("\n");
  } // end loop over rows
  printf("\n");
  // getchar();
}
