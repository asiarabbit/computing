/**
  \brief solving linear equation set with
  direct LU factorization method
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
  const int n = 3; // the dimension of the coefficient matrix
  double A[3][3] = {
    { 2.,  1.,  5.},
    { 4.,  1., 12.},
    {-2., -4.,  5.}
  };
  double b[3] = { // the constant vector
    11., 27., 12.
  };

  // the LU factorization routine //
  for(int k = 0; k < n; k++){ // the k-the iteration
    for(int i = k; i < n; i++){
      // calculate u_ki = a_ki - sum(l_kj*u_ji), j: 0 -> k-1
      for(int j = 0; j < k; j++){
        // note that l and u have been stored inplace in matrix A
        // so the folowing statement is equivalent to a_ki -= l_kj*u_ji
        A[k][i] -= A[k][j] * A[j][i];
      } // end for over j
    } // end for over i
    printf("%d-th row of matrix U updated\n", k);
    ShowMatrix(A[0], n, n);
    getchar();
    // calculate l_ik = (a_ik - sum(l_ij*u_jk)) / u_kk, j: 0 -> k-1
    for(int i = k + 1; i < n; i++){
      for(int j = 0; j < k; j++) A[i][k] -= A[i][j] * A[j][k];
      A[i][k] /= A[k][k];
    } // end for over i
    printf("%d-th row of matrix L updated\n", k);
    ShowMatrix(A[0], n, n);
    getchar();
  } // end for over k
  printf("After LU factorization, A = LU (L\\U): \n");
  ShowMatrix(A[0], n, n);
  getchar();

  // Notation: Ax = b <=> LUx = b <=> Ly=b, y=Ux //
  // solve y with Ly=b //
  for(int i = 1; i < n; i++) for(int j = 0; j < i; j++) b[i] -= A[i][j] * b[j];
  // solve x with Ux=y //
  for(int i = n - 1; i >= 0; i--){ // solve x_i
    for(int j = i + 1; j < n; j++) b[i] -= A[i][j] * b[j];
    b[i] /= A[i][i];
  } // end for over i


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
