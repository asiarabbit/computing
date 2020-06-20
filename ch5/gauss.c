/**
  \brief solving linear equation set with
  sequential gaussian elimination method.
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
    { 2.,  1.,  1.},
    { 1.,  3.,  2.},
    { 1.,  2.,  2.}
  };
  double b[3] = { // the constant vector
    4., 6., 5.
  };

  // the elimination routine //
  for(int k = 0; k < n - 1; k++){ // the k-th elimination
    for(int i = k + 1; i < n; i++){ // subtract l_ik*row_k from row_i in (A|b)
      A[i][k] /= A[k][k]; // used as l_{ik}
      for(int j = k + 1; j < n; j++) A[i][j] -= A[i][k] * A[k][j];
      b[i] -= A[i][k] * b[k];
      A[i][k] = 0.; // not necessary, only for showcase
    } // end for over i
    printf("Implement the %d-th elimination\n", k);
    ShowMatrix(A[0], n, n); // Ab[0] points to Ab[0][0]
    ShowMatrix(b, n, 1); // Ab[0] points to Ab[0][0]
    getchar();
  } // end for over k

  // solving {x_k} by backward substitution //
  // the result would be stored inplace in vector b
  for(int i = n - 1; i >= 0; i--){ // loop over x_i
    // calculate sum(A[i][j]*x[j]) (j = i+1 -> n)
    double sum = 0.;
    for(int j = i + 1; j < n; j++) sum += A[i][j] * b[j];
    b[i] = (b[i] - sum) / A[i][i];
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
