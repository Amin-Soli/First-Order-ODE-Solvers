
////////////////  derived class /////////////////

class rungeKutta_4 : public baseSolver {
	
	private:
		
	  double K1, K2, K3, K4;
  
   public:
   
	  rungeKutta_4 (string solverName, double y_, double t_, double dt_, double tEnd) 
	  : baseSolver(solverName,y_,t_,dt_,tEnd)
	  {}
	  
      void solve(); 
         
};

#include "rungeKutta_4.C"
