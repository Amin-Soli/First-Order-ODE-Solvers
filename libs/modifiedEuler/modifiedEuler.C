
//////////////////////////////// public functions /////////////////////////////////////

void modifiedEuler::solve()
{
	int i=0;
	
	do
	{
		y_exact[i] = exact_y(t,y); 
			
		y_numerical[i] = y;
		
		Error[i] = fabs ( (y_exact[i] - y_numerical[i]) / y_exact[i] )*100;
		
		time[i] = t;
				
		y_prime_0 = f(t,y); 
		
		y_prime_1 = f(t + dt, y + dt*y_prime_0);
		
		y = y + dt/2.0 *( y_prime_0 + y_prime_1);
		
		t = t + dt;
		
		i++;
	}
	while(t <= t_end);
		
}

