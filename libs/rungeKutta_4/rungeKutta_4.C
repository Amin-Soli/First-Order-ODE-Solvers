
//////////////////////////////// public functions /////////////////////////////////////

void rungeKutta_4::solve()
{
	int i=0;
	
	do
	{
		y_exact[i] = exact_y(t,y); 
			
		y_numerical[i] = y;
		
		Error[i] = fabs ( (y_exact[i] - y_numerical[i]) / y_exact[i] )*100;
		
		time[i] = t;
				
		K1 = dt*f(t,y); 
		
		K2 = dt*f(t + dt/2.0, y + K1/2.0); 
		
		K3 = dt*f(t + dt/2.0, y + K2/2.0); 
		
		K4 = dt*f(t + dt, y + K3);
		
		y = y + 1.0/6 * (K1 + 2*K2 + 2*K3 + K4);
		
		t = t + dt;
		
		i++;
	}
	while(t <= t_end);
		
}

