#include "my_runge_kutta.hpp"
#include <fstream> 

int main () {


	
	
	

	auto fun  = [] (double t, double y) { return std::pow(y,2) ; }  ; 

	runge_kutta solver ( 10, 1., 0., 1.0, fun ) ; // steps, initial cond, start time, end time 
        solver.method("Euler") ; 
	solver.solve() ; 
        std::pair<std::vector<double>,std::vector<double>>  solution = solver.get_result() ; 
	std::vector<double> y = solution.first ;  
	std::vector<double> t = solution.second ; 
	std::ofstream ofile ( "my_file.txt" )  ; 
	for (unsigned int i=0; i<y.size() ; ++i  ) 
	{
	       std::cout<< t[i] << " " << y[i] <<std::endl ; 
	
	}		
        


}
