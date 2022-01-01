
////////////////  abstract class /////////////////

class baseSolver {
	
	protected:
	
	///////////// protected members //////////////////////
	
	int n;
	
	double dt, t_end, y, t;
	
	double *y_numerical, *y_exact, *time, *Error;
    
    string solverType; 
    
	       
   public:
   
	  baseSolver (string , double , double , double , double );
	  
	  ~baseSolver ();
	  
      virtual void solve() = 0; 
	  
      static baseSolver* New(string , double , double , double , double );
      
      int get_n();
 
	  string get_solverType();
  
      double * get_time();
	  
	  double * get_y_numerical();
	  
	  double * get_y_exact();
	  
	  double * get_Error();
 
      double f(double , double );  // defined in main function by user

	  double exact_y(double , double );  // defined in main function by user
      
};

#include "../Euler/Euler.H"
#include "../modifiedEuler/modifiedEuler.H"
#include "../rungeKutta_2/rungeKutta_2.H"
#include "../rungeKutta_4/rungeKutta_4.H"
#include "baseSolver.C"
