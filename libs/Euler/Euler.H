
////////////////  derived class /////////////////

class Euler : public baseSolver {
	
   private:
		
	  double y_prime;
	

   public:
   
	  Euler (string solverName, double y_, double t_, double dt_, double tEnd) 
	  : baseSolver(solverName,y_,t_,dt_,tEnd)
	  {}
	  
      void solve(); 
         
};

#include "Euler.C"
