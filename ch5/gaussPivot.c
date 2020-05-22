/**
  \brief solving linear equation set with
  sequential gaussian elimination method using pivoting.
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
  double Ab[3][4] = {
    // {0., 1., 1., 1.},
    // {1., 2., 3., 0.},
    // {1., 4., 6., 2.}
    { 12., -3.,  3.,  15.},
    {-18.,  3., -1., -15.},
    {  1.,  1.,  1.,   6.}
  };

  // the elimination routine //
  for(int k = 0; k < n - 1; k++){ // the k-th elimination
    //// pick out the pivotal element from Ab[i][k], i: k -> n ////
    // to begin with, assume the pivotal element is Ab[k][k]
    int r = k; double max = fabs(Ab[r][k]);
    for(int i = k + 1; i < n; i++) if(fabs(Ab[i][k]) > max){
      r = i; max = fabs(Ab[r][k]); // update the pivotal element
    }
    // now we have the pivotal element in row[r], then place it in row[k]
    // exchange row[k] and row[r] in augmented matrix (A|b)
    if(r != k){ // no need for exchane if r == k
      printf("Pivotal element in row[%d], it's %7.3f.\n", r, Ab[r][k]);
      double tmp = 0.;
      for(int i = k; i <= n; i++){
        tmp = Ab[r][i];
        Ab[r][i] = Ab[k][i];
        Ab[k][i] = tmp;
      }
      printf("row[%d] and row[%d] exhanged.\n", r, k);
      ShowMatrix(Ab[0], n, n + 1); // Ab[0] points to Ab[0][0]
      getchar();
    } // end if
    //// pivoting completed :) ////

    // back to conventional gaussian elimination //
    for(int i = k + 1; i < n; i++){ // subtract l_ik*row_k from row_i in (A|b)
      Ab[i][k] /= Ab[k][k]; // used as l_{ik}
      for(int j = k + 1; j <= n; j++) Ab[i][j] -= Ab[i][k] * Ab[k][j];
      Ab[i][k] = 0.; // not necessary, only for showcase (can be removed)
    } // end for over i
    printf("Implement the %d-th elimination\n", k);
    ShowMatrix(Ab[0], n, n + 1); // Ab[0] points to Ab[0][0]
    getchar();
  } // end for over k

  // solving {x_k} by backward substitution //
  // the result would be stored inplace in vector b
  Ab[n - 1][n] /= Ab[n - 1][n - 1]; // x_n = bn/Ann
  for(int i = n - 2; i >= 0; i--){ // loop over x_i
    // calculate sum(Ab[i][j]*x[j]) (j = i+1 -> n)
    double sum = 0.;
    for(int j = i + 1; j < n; j++) sum += Ab[i][j] * Ab[j][n];
    Ab[i][n] = (Ab[i][n] - sum) / Ab[i][i];
  } // end for over i

  printf("\n\nThe solution to the linear equation set is {%10.8f", Ab[0][n]);
  for(int i = 1; i < n; i++) printf(", %10.8f", Ab[i][n]);
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
