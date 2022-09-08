/**
 *
 * A first stab at an algorithm for calculating exp(-x)
 * We simply calculate each term in the taylor series up to a certain 
 * specificied tolerance and add the terms together.
 * This approach will not be fruitful.
 *
 */
#include<iostream>
#include<math.h>

#define PRECISION double
#define PHASE(a)  (1-2*(abs(a)%2))
#define TRUNCATION 1.0E-16

//PRECISION factorial(int n);

int
main
(int argc, char** argv)
{

	int n;
	PRECISION arg,term,sum;

	for(arg=0.0;arg<=100.0;arg+=10.0){
//	for(arg=0.0;arg<=1.0;arg+=10.0){	
		
		n=1;
		
		term = 1.0;

		sum = 1.0;

		while(fabs(term)>TRUNCATION){
	
			term *= -arg/((PRECISION) n);			
			sum+=term;
			n++;
		}

		std::cout << " x = " << arg << " exp = " << exp(-arg) <<" series = " << sum;
		std::cout << " number of terms = " << n-1 << std::endl;
	}
	

}

/*
PRECISION
factorial
(int n)
{
	int loop;
	PRECISION fac;
	for(loop = 1, fac = 1.0; loop <= n; loop++) {
		fac *= loop;
	}
	return fac;
}*/
