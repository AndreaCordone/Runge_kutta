#include "my_runge_kutta.hpp"


runge_kutta::runge_kutta (unsigned int steps_number, double initial_cond,double initial_time, double end_time, std::function<double (double,double)> f ) 
		: y0{initial_cond},
		n{steps_number},
		t0{initial_time},
		tend{end_time},
		dydt{f}
{
		
	
      step = (tend-t0)/n ;  

// Filling the time vector 
      this->t.resize(n,0) ; 
      
      this->t[0] = t0 ; 
      

for (unsigned int i = 1; i <= n ; ++i ) 
      {

	      this->t[i] = this->t[i-1] + step ;

      }	
		
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
void runge_kutta::solve ( ) {
	
	
	this->y.resize(n,0) ; 
	std::vector<double> k(s,0) ; 
	k[0] = dydt(t0,y0) ; 
	y[0] = y0 ; 
        double yy{0}; 
	double kk{0}; 
	double tt{0}; 

	for (unsigned int j = 1 ; j <= n ; ++j ) 
{
		
	kk = 0 ; 
	yy = 0 ; 
	
	for ( unsigned int i = 0; i <s ; ++i ) 
{

       tt = this->t[j] + c[i]*step ;

        
	
       for ( unsigned int m = 0 ; m<= i ; ++m ) 
       {

                       

	       yy = yy + a[i][m]*k[m] ; 
       }


       k[i] = dydt(tt, y[j-1] + yy*step) ; 
       
       std::cout<<"k"<<i<<"="<<k[i] <<std::endl; 
       
       kk = kk+ step*k[i]*b[i] ;  

}
     
	       
	   y[j] = y[j-1] + kk ; 
	      
	       


}





}




std::pair<std::vector<double>,std::vector<double>> runge_kutta::get_result ( ) 
{

	return std::pair<std::vector<double>,std::vector<double>> (this->y,this->t) ; 

}





