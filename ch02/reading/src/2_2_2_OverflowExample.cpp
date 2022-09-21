/**
 *
 * A program that converts decimal numbers to a binary represenatation
 *
 */

#include<iostream>
#include<cmath>

int 
main
(int argc, char* argv[])
{
														
	int exponent;
	int powerOne;
	int powerOneShifted;
	int powerTwo;
	int powerTwoShifted;
	

	std::cout<<"Enter N for 2^N:  ";
	std::cin>>exponent;

	powerOne = (int) pow(2.,(double) exponent);
	powerOneShifted = powerOne-1;
	
	powerTwo = powerOne*powerOne;
	powerTwoShifted = powerOne*powerOneShifted;
	
	std::cout<<"2^N*2^N: " << powerTwo << std::endl;
        std::cout<<"2^N*(2^N-1): " << powerTwoShifted << std::endl;
        std::cout<<"2^N-1: " << powerOneShifted << std::endl;
}
