/**
  \brief solving roots of a function by iteration method
  \author SUN Yazhou, asia.rabbit@163.com
  \date Created: 2020/05/05 Last revised: 2020/05/05 by SUN Yazhou
  \copyright 2020, SUN Yazhou
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

// the objective function
double phi(double x){
  return pow(1.+x*x, 1./3.);
}

int main(int argc, char **argv){
  if(argc < 3){
    cout << "input format: <x0> <epsilon> <Nmax>" << endl;
    cout << "x0: initial value of x;" << endl;
    cout << "epsilon: error tolerance |x(k) - x(k-1)|" << endl;
    cout << "Nmax: maximum number of iterations." << endl;
    cout << "Please try again. The program is exiting..." << endl;
    exit(1);
  }
  // take in the inputs //
  // the search domain of the varialbe(s)
  double x0 = atof(argv[1]), x1 = phi(x0);
  double epsilon = fabs(atof(argv[2]));
  // the maximum count of iterations
  int Nmax = abs(atoi(argv[3])), k = 0;

  // the iteration //
  while(k < Nmax && fabs(x0-x1) > epsilon){
    x0 = x1;
    x1 = phi(x0);
    k++;
  } // end for over i

  cout << "The program has iterated " << k << " times." << endl;
  cout << "The obtained root is " << x1 << endl;
  cout << "Bye." << endl;
} // end of the main function
