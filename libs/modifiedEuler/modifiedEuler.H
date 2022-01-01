
////////////////  derived class /////////////////

class modifiedEuler : public baseSolver {
	
	private:
		
	  double y_prime_0, y_prime_1;
  
   public:
   
	  modifiedEuler (string solverName, double y_, double t_, double dt_, double tEnd) 
	  : baseSolver(solverName,y_,t_,dt_,tEnd)
	  {}
	  
      void solve(); 
         
};

#include "modifiedEuler.C"
