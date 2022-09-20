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

#define PRECISION float

int N;
auto increase = [](auto n){return n+1;};
auto decrease = [](auto n){return n-1;};
auto sum_up_condition = [](auto n){return n==N;};
auto sum_down_condition = [](auto n){return n==1;};


void sum(int n, PRECISION *sum,
		std::function<int(int)> iterate,
		std::function<bool(int)> condition);


int
main
(int argc, char *argv[])
{

	if(argc==1){
		std::cout<<"Bad usage, please pass exactly one argument"<<std::endl;
		exit(1);
	}

	// grab N from the user
	N = atoi(argv[1]);
	
	//intialize our sum up values
	PRECISION sum_val;	
	PRECISION *s_up=&sum_val;

	// perform the sum
	*s_up = 0.0;
	sum(1,s_up,increase,sum_up_condition);
	std::cout<<"s_up = "<<*s_up << std::endl;

	/*do the same process for summing down
	PRECISION *s_down=&sum_val;
	*s_down=0.0;
	sum(N,s_down,decrease,sum_down_condition);
	std::cout<<"s_down = "<<*s_down << std::endl;
*/
	
}

void
sum
(int n, PRECISION *sum_val,std::function<int(int)> iterate,std::function<bool(int)> condition)
{
	*sum_val += 1.0/((PRECISION) n);
	if(condition(n)){return;}
	sum(iterate(n),sum_val,iterate,condition);
}


