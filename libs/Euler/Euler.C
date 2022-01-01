
//////////////////////////////// public functions /////////////////////////////////////

void Euler::solve()
{
	int i=0;
	
	do
	{
		y_exact[i] = exact_y(t,y); 
			
		y_numerical[i] = y;
		
		Error[i] = fabs ( (y_exact[i] - y_numerical[i]) / y_exact[i] )*100;
		
		time[i] = t;
				
		y_prime = f(t,y); 
		
		y = y + dt*y_prime;
		
		t = t + dt;
		
		i++;
	}
	while(t <= t_end);
		
}

