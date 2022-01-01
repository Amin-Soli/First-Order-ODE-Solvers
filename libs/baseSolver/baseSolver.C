
/////////////////////////////////// New function ///////////////////////////

baseSolver* baseSolver::New(string solverName, double y_, double t_, double dt_, double tEnd)
{
    
    baseSolver* myObject = 0;
    
    if (solverName=="Euler")
    {
	    myObject = new Euler(solverName,y_,t_,dt_,tEnd);
	    return myObject;
    }
    
	  
    else if (solverName=="modifiedEuler")
    {
	    myObject = new modifiedEuler(solverName,y_,t_,dt_,tEnd);
	    return myObject;
    }                
    
    else if (solverName=="rungeKutta_2")
    {
	    myObject = new rungeKutta_2(solverName,y_,t_,dt_,tEnd);
	    return myObject;
    }
    
    else if (solverName=="rungeKutta_4")
    {
	    myObject = new rungeKutta_4(solverName,y_,t_,dt_,tEnd);
	    return myObject;
    }    
}

//////////////// constructor ///////////////////////

baseSolver::baseSolver (string solverName, double y_, double t_, double dt_, double tEnd)
{
	solverType = solverName;
	y = y_;
	t = t_;
	dt = dt_;
	t_end = tEnd;
	
	n = t_end/dt ;
	n = n + 1;
	
	time = new double [n];
	y_numerical = new double [n];
	y_exact = new double [n];
	Error = new double [n];		
}

//////////////////////////////////   destructor  ///////////////////////////////////////////////////

baseSolver::~baseSolver ()
{
     delete[] time;
     delete[] y_numerical;
     delete[] y_exact;
     delete[] Error;
}

//////////////////////////////// public functions /////////////////////////////////////

int baseSolver::get_n()
{
  return n;
}

///////////////////////////////////////////////////////////////////////////////////////////////
  
string baseSolver::get_solverType()
{
  return solverType;
}

///////////////////////////////////////////////////////////////////////////////////////////////

double * baseSolver::get_time()
{
  return time;
}

///////////////////////////////////////////////////////////////////////////////////////////////
	  
double * baseSolver::get_y_numerical()
{
  return y_numerical;
}

///////////////////////////////////////////////////////////////////////////////////////////////
	  
double * baseSolver::get_y_exact()
{
  return y_exact;
}

///////////////////////////////////////////////////////////////////////////////////////////////
	  
double * baseSolver::get_Error()
{
  return Error;
}

