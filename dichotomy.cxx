// solving roots of a function by dichotomy

#include <cstdlib>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

// the objective function
double fun(double x){
  return x*x*x - x - 1.;
}

int main(int argc, char **argv){
  if(argc < 6){
    cout << "input format: <a> <b> <epsilon0> <epsilon1> <Nmax>" << endl;
    cout << "[a,b]: x domain;" << endl;
    cout << "epsilon0, epsilon1: allowed errors for f(x) and x" << endl;
    cout << "Nmax: maximum number of iterations." << endl;
    cout << "Please try again. The program is exiting..." << endl;
    exit(1);
  }
  // take in the inputs //
  // the search domain of the varialbe(s)
  double a = atof(argv[1]), b = atof(argv[2]);
  if(a == b){
    cout << "ERROR: a == b is not allowed. Exiting..." << endl;
    exit(1);
  }
  if(a > b){ double t = a; a = b; b = t; } // a should be less than b
  // the error tolerances for the function (epsilon0) and the variable(epsilon1)
  double epsilon0 = fabs(atof(argv[3]));
  double epsilon1 = fabs(atof(argv[4]));
  // the maximum count of iterations
  int Nmax = abs(atoi(argv[5]));
  // prepare for the iterations //
  double m = (a + b) / 2.;
  double fa = fun(a), fb = fun(b);
  if(fa * fb > 0.){
    cout << "f(a) and f(b) should have different signs. Exiting..." << endl;
    exit(1);
  }
  int k = 0; // the iteration number
  if(fa == 0){ m = a; b = a; }
  if(fb == 0){ m = b; a = b; }
  cout.precision(10);
  if(fabs(fa - fb) < epsilon0 || fabs(a - b) < epsilon1){
    cout << "The program has iterated " << k << " times." << endl;
    cout << "The obtained root is f(" << m << ") = " << fun(m) << endl;
    cout << "Bye." << endl;
  }

  // start the iteratons //
  while(fabs(a - b) > epsilon1 && k < Nmax){
    m = (a + b) / 2.;
    fb = fun(m); // SUPPOSE m is the end of the new search domain
    if(fabs(fb) < epsilon0) break;

    // reset the search domain
    if(fun(m) * fa < 0.) b = m; // confirm the ASSUMPTION
    else{ // ASSUMPTION failed, a set as the end of the new search domain
      a = m;
      fa = fb;
    }
    k++;
  } // end while

  cout << "The program has iterated " << k << " times." << endl;
  cout << "The obtained root is f(" << m << ") = " << fun(m) << endl;
  cout << "Bye." << endl;
} // end of the main function
