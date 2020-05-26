/**
  \brief inverse square matrix using
  Gauss-Jordan elimination method with pivoting.
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
  const int n = 4, n2 = 2*n; // the dimension of the coefficient matrix
  double AE[4][8] = { // the augmented matrix (A|b), b[j] = A[n+1][j]
    {3.,  2.,  0., -1., 1, 0, 0, 0},
    {0.,  2.,  2.,  1., 0, 1, 0, 0},
    {1., -2.,  3., -2., 0, 0, 1, 0},
    {0.,  1.,  2.,  1., 0, 0, 0, 1}
  };

  // the elimination routine //
  for(int k = 0; k < n; k++){ // the k-th elimination
    //// pick out the pivotal element from AE[i][k], i: k -> n ////
    // to begin with, assume the pivotal element is AE[k][k]
    int r = k; double max = fabs(AE[r][k]);
    for(int i = k + 1; i < n; i++) if(fabs(AE[i][k]) > max){
      r = i; max = fabs(AE[r][k]); // update the pivotal element
    }
    // now we have the pivotal element in row[r], then place it in row[k]
    // exchange row[k] and row[r] in augmented matrix (A|b)
    if(r != k){ // no need for exchane if r == k
      printf("Pivotal element in row[%d], it's %7.3f.\n", r, AE[r][k]);
      double tmp = 0.;
      for(int i = k; i < n2; i++){
        tmp = AE[r][i];
        AE[r][i] = AE[k][i];
        AE[k][i] = tmp;
      }
      printf("row[%d] and row[%d] exhanged.\n", r, k);
      ShowMatrix(AE[0], n, n2); // AE[0] points to AE[0][0]
      getchar();
    } // end if
    //// pivoting completed :) ////

    // Gauss-Jordan elimination //
    // firstly, scale row[k] with 1./AE[k][k]
    for(int i = k + 1; i <= n2; i++) AE[k][i] /= AE[k][k];
    AE[k][k] = 1.; // not necessary, only for showcase (can be removed)
    // secondly, subtract AE[i][k]*row_k from row_i in (A|b)
    // note that i starts from 0, not k+1 (different from gaussian)
    for(int i = 0; i < n; i++){
      if(i != k){
        for(int j = k + 1; j <= n2; j++) AE[i][j] -= AE[i][k] * AE[k][j];
        AE[i][k] = 0.; // not necessary, only for showcase (can be removed)
      }
    } // end for over i
    printf("Implement the %d-th elimination\n", k);
    ShowMatrix(AE[0], n, n2); // AE[0] points to AE[0][0]
    getchar();
  } // end for over k

  // solving {x_k} by backward substitution //
  // -- advantage for G-S method: there'd be no backward substitution -- //
  // the solution has been stored in vector b once the iteration is done. //
  printf("The inverse of matrix A is\n");
  ShowMatrix(AE[0], n, n2); // AE[0] points to AE[0][0]
  printf("}\n\nBye.\n\n");

  return 0;
} // end of the main function

void ShowMatrix(double *A, const int nrow, const int ncol){
  for(int i = 0; i < nrow; i++){
    for(int j = 0; j < ncol; j++){
      printf(" %7.3f", A[i*ncol+j]);
    } // end for over columns
    printf("\n");
  } // end loop over rows
  printf("\n");
  // getchar();
}
