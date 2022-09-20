/*
 * This is a program that calculates the sum:
 *
 * 	SIGMA_n=1^N[1/n]
 * 
 * in two different ways. The first way, it starts from the bottom
 * and works its way up (the analytical way) and the second way it 
 * starts from the top and works its way down.
 *
 * It reads in the value of N from the user and outputs their results to 
 * the screen.
 *
 */

#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<functional>
#include <typeinfo>

#define PRECISION float

PRECISION N;

auto increase = [](auto n){return n + (long) 1;};
auto decrease = [](auto n){return n - (long) 1;};

std::function<bool(unsigned long)> sum_up_condition = [](unsigned long n){return n<(unsigned long) N;};
std::function<bool(unsigned long)> sum_down_condition = [](unsigned long n){return n>(unsigned long) 1;};


PRECISION
sum
(PRECISION starting_index,std::function<unsigned long(unsigned long)> iterate,std::function<bool(unsigned long)> condition);


int
main
(int argc, char *argv[])
{

	if(argc>1){
		std::cout<<"Bad usage, no arguments required"<<std::endl;
		exit(1);
	}

	PRECISION N_vals[11];
	for(int i =0; i<11;i++){
		N_vals[i] = pow(10.,(double) i);
	}


	// make a filename based on the precision chosen	
	std::string filename = (typeid(N_vals[0])==typeid(double)) ? "2_6_2_2_double.dat" : ((typeid(N)==typeid(float)) ? "2_6_2_2_single.dat" : "bad");
	if(filename.compare("bad")==0){exit(1);};
	
	std::string directory_path = "data/";
	std::string filepath = directory_path+filename;

	std::ofstream file;
	file.open(filepath,std::ios::out);
	file.clear();
	file << "N, s_up, s_down, log10(N), log10(|s_up-s_down|/s_down)" <<std::endl;


	for(int i =0; i<11;i++){

		N = N_vals[i];

		PRECISION s_up,s_down;	

		s_up = sum(1.0,increase,sum_up_condition);
		std::cout<<"N= "<<N<< ", s_up = "<<s_up;

		s_down = sum(N,decrease,sum_down_condition);
		std::cout<<", s_down = "<< s_down << std::endl;

		file << N <<"	"<< s_up<<"	" << s_down<<"     " << log10(N)<<"     " <<  log10(fabs(s_up-s_down)/s_down) << std::endl;
	}
	
	file.close();

	std::cout << "data saved to " << filepath << std::endl;
}

PRECISION
sum
(PRECISION starting_index,std::function<unsigned long(unsigned long)> iterate,std::function<bool(unsigned long)> condition)
{

	unsigned long index = (unsigned long) starting_index;
	
	PRECISION n = (PRECISION) index;
	PRECISION sum = 1.0/n;

	while(condition(index)){
		index = iterate(index);
		n = (PRECISION) index;
		sum += 1.0/n;	

	}

	return sum;
}



