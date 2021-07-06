#include<iostream>
#include<functional> 
#include<vector>
#include<string>
#include<math.h>
#include<map> 

class runge_kutta {
	
	public:

// Default constructor 		
runge_kutta (unsigned int steps_number, double initial_cond,double initial_time, double end_time, std::function<double (double,double)> f ) ; 

void method ( const std::string & methods )  ; 
void solve ( ) ; 
std::pair<std::vector<double>,std::vector<double>> get_result ( ) ; 

	private:
	
		// Initial condition
		double y0 ; 
		
		// Step size 
		unsigned int n ;
	

		// Initial_time t0 
		double t0  ; 

		//End Time tend
		double tend ; 
		
		//Stage number s
		unsigned int s ; 
			
		// This is the function dydt = f(t,y) 
		std::function<double (double,double)> dydt;  

		// Butcher Table 
		std::vector<std::vector<double>> a ; 
		
		// Solution vetor 
		std::vector<double> y ; 


		// Step size 
		double step ; 

	        // Butcher c elements
		std::vector<double> c ; 
	
		// Butcher b elements 
		std::vector<double> b ; 	
		
		//time vector 
		std::vector<double> t ; 

} ; 


