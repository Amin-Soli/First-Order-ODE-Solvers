#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

#include "../libs/baseSolver/baseSolver.H"

////////////////// defined functions f and exact_y in baseSolver class by user ///////////////////////

double baseSolver::f(double t, double y)  // derivative of y
{
	return 2.0 - exp(-4*t) - 2*y;
}

double baseSolver::exact_y(double t, double y)  // exact y
{
	return 1.0 + 1.0/2 *exp(-4*t) - 1.0/2 *exp(-2*t);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

  //////////////////////////////// input data section given by user //////////////////////////////////////

  string solverName = "Euler";  // (Euler, modifiedEuler, rungeKutta_2, rungeKutta_4)

  double y,t,dt,t_end;

  // initial condition:
  y = 1;
  t = 0;

  // input data
  dt = 0.1;
  t_end = 0.5;      // t_end should be a multiple of dt

  ////////////////////////////////////////////////////////////////////////////////////////////////////////

  baseSolver *myObject;

  myObject = myObject -> baseSolver::New(solverName,y,t,dt,t_end);

  myObject -> solve();

  /////////////////////// print result data:

  int n_;
  n_ = myObject -> get_n();

  double *time_, *y_numerical_, *y_exact_, *Error_;
  time_ = myObject -> get_time();
  y_numerical_ = myObject -> get_y_numerical();
  y_exact_ = myObject -> get_y_exact();
  Error_ = myObject -> get_Error();

  string solverType_;
  solverType_ = myObject -> get_solverType();

  cout << "input data of the problem:" << endl << endl;
  cout << "solver type is: " << solverType_ << endl;
  cout << "initial condition y(t = " << t << "): " << y << endl;
  cout << "delta_t: " << dt << endl;
  cout << "t_end: " << t_end << endl << endl;
  cout << "result data: " << endl << endl;

  cout << "Time" << '\t' << '\t' << "." << '\t' << "Approximation" << '\t' << "." << '\t' ;
  cout << "Exact" << '\t' << '\t' << "." << '\t' << "Error (%)" << endl << endl;
  cout << "................................................................................." << endl <<endl;

  cout << fixed;
  cout << setprecision(6);

  for (int i=0;i<n_;i++)
  {
	  cout << time_[i] << '\t' << "." << '\t' << y_numerical_[i] << '\t' << "." << '\t';
	  cout << y_exact_[i] << '\t' << "." << '\t'  << Error_[i] << endl << endl;
  }

  cout << "end of the program." << endl;

}
