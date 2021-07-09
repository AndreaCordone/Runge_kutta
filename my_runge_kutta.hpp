#include<iostream>
#include<functional> 
#include<vector>
#include<string>
#include<math.h>
#include<map> 

class runge_kutta {
	
	public:

// Default constructor 		
runge_kutta (double step, double initial_cond,double initial_time, double end_time, std::function<double (double,double)> f ) ; 

void method ( const std::string & methods )  ; 


double evolve_one_step( ) ; 

	
void solve ( ) ; 

std::pair<std::vector<double>,std::vector<double>> get_result ( ) ; 

	private:
	
		// Solution
		double y ; 	
		
		// Time vector 
		std::vector<double> time ; 		
	
		// solution 
		std::vector<double> sol ; 


		// Step size 
		double step ; 


	
		// Initial_time t0 
		double t ; 

		//End Time tend
		double tend ; 
		
		//Stage number s
		unsigned int s ; 
			
		// This is the function dydt = f(t,y) 
		std::function<double (double,double)> dydt;  

		// Butcher Table 
		std::vector<std::vector<double>> a ; 
		

		//Vector of k 
		std::vector<double> k ; 

		// Butcher c elements
		std::vector<double> c ; 
	
		// Butcher b elements 
		std::vector<double> b ; 	
		

} ; 


