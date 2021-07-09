#include "my_runge_kutta.hpp"
#include <fstream> 

int main () {


	
	
	

	auto fun  = [] (double t, double y) { return std::pow(y,2) ; }  ; 

	runge_kutta solver ( 0.01, 1.0, 0.0, 1.0, fun ) ; // step, initial cond, start time, end time 
        
	solver.method("Euler") ; 
	
	solver.solve() ; 
	

	std::pair<std::vector<double>,std::vector<double>> results = solver.get_result() ; 
	std::vector<double> y = results.first ; 	
        std::vector<double> t = results.second; 


	for (unsigned int i=0; i<y.size() ; ++i  ) 
	{
	       std::cout<< t[i] << " " << y[i] <<std::endl ; 
	
	}		
        

}
