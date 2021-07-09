#include "my_runge_kutta.hpp"


runge_kutta::runge_kutta (double step_, double initial_cond,double initial_time, double end_time, std::function<double (double,double)> f ) 
		: y{initial_cond},
		step{step_},
		t{initial_time},
		tend{end_time},
		dydt{f}
{

time.emplace_back(t) ; 
sol.emplace_back(y) ; 


}  


void runge_kutta::method(const std::string &method) {



if ( method=="RK4" ) {


		a = {{0 ,0 ,0 ,0},  {0.5, 0, 0 ,0 } , {0 ,0.5 ,0 ,0}, {0 ,0 ,0 ,1 }}; 
		c = {0 ,0.5 ,0.5 ,1} ; 
		b = {1.0/6.0 ,1.0/3.0 ,1.0/3.0 ,1.0/6.0} ; 
			s= 4 ;
}
else if(method=="Ral")  {
		
	        a = {{0,0},{2.0/3.0,0}} ; 
		c = { 0 ,2.0/3.0} ; 
		b = {1.0/4.0,3.0/4.0} ; 
		s = 2 ; 		

}

else if ( method=="Euler") {
	
		a = {{0}} ; 
		b = {1} ; 
		c = {0} ;
		s = 1 ; 
}




}

double runge_kutta::evolve_one_step () {









	k.resize(s,0) ; 
	


	// Setting initial condition 
        
	double yy{0}; 
	double kk{0}; 
	double tt{0}; 


	
	for ( unsigned int i = 0; i <s ; ++i ) 
{

                
	tt = t + c[i]*step ;
	
	// scalar product k*a 
	for ( unsigned int m = 0 ; m<= i ; ++m ) 
       
	{
		
		yy = yy + a[i][m]*k[m] ; 
        }


              
	// Filling the k vector 
	k[i] =  dydt(tt, y + yy*step)   ; 
       
        // Compute scalar product b*k 
        kk = kk + step*k[i]*b[i] ;  




}
     
	   // Compute next step      
	   y = y + kk ; 
	 
	   	       
return y ; 
	  

}



void runge_kutta::solve() 

{

	for( t = t+step ; t<= tend; t = t+ step  ) 

		
		
	{
		
		sol.emplace_back(this->evolve_one_step()) ; 
		
		time.emplace_back(t) ; 

		
	}	




}

 
  std::pair<std::vector<double>,std::vector<double>> runge_kutta::get_result ( ) 
{

	return std::pair<std::vector<double>,std::vector<double>> (sol,time) ; 

}

 



