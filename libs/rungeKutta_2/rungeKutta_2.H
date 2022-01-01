
////////////////  derived class /////////////////

class rungeKutta_2 : public baseSolver {
	
	private:
		
	  double K1, K2;
  
   public:
   
	  rungeKutta_2 (string solverName, double y_, double t_, double dt_, double tEnd) 
	  : baseSolver(solverName,y_,t_,dt_,tEnd)
	  {}
	  
      void solve(); 
         
};

#include "rungeKutta_2.C"
