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
#include<cmath>
#include<string>
#include<functional>

#define PRECISION double

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

	if(argc==1){
		std::cout<<"Bad usage, please pass exactly one argument"<<std::endl;
		exit(1);
	}

	// grab N from the user
	N = atof(argv[1]);
	
	//intialize our sum values
	PRECISION s_up,s_down;	

	//perform the sum for incresasing from n=1
	s_up = sum(1.0,increase,sum_up_condition);
	std::cout<<"s_up = "<<s_up << std::endl;

	// do the same process for summing down
	s_down = sum(N,decrease,sum_down_condition);
	std::cout<<"s_down = "<< s_down << std::endl;

	
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



