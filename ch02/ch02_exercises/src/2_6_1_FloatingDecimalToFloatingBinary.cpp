/**
 *
 * A program that converts floating decimal numbers to floating binary numbers
 *
 * The number it converts is entered as an argument by the user.
 *
 * It calculates the scale first by finding the interval [2^N,2^N+1] it falls on, checking N
 * on the interval [-MAX_EXPONENT, MAX_EXPONENT]
 *
 * It calculates 32 bits of percision on the mantissa. Something like the method of bisection is used,
 * where the mnantissa is summed through the current digit. It attempts to add the next digit. If that 
 * goes over the decimal passed, the digit is set to zero and the process is repeated with the next
 * digit.
 *
 */

#include<iostream>
#include<cmath>
#include<string>
#define PRECISION double
#define TRUNCATION 1.0E-16
#define MAX_EXPONENT 64

PRECISION sum(int digits[], int scale, PRECISION decimal);
int getScale(PRECISION decimal);

int 
main
(int argc, char* argv[])
{
	
	if(argc==1){
	
		std::cout<<"Bad usage, please pass exactly one argument"<<std::endl;
		exit(1);	
	}

	PRECISION decimal = atof(argv[1]);
	
	int signum = (decimal>0) ? 1 : ((decimal<0) ? -1 : 0);
	decimal = fabs(decimal);

	int scale = getScale(decimal);
	int digits[32];

	digits[0] = 1;	
	for(int j =1;j<32;j++){

		digits[j]=0;

	}



	int index = 0;

	while(index<32){

		digits[index]=1;

		PRECISION currSum = sum(digits,scale,decimal);

		if(currSum>decimal){	
		
			digits[index]=0;
		
		}

		if(fabs(currSum-decimal)<=TRUNCATION){
			break;
		}

		index += 1;
	}

	std::string sign = (signum==1) ? "+" : ((signum==-1) ? "-" : "");

	std::cout<<"("<<sign;

	for(int i=0;i<32;i++){

		std::cout<<digits[i];
		if(i==0){
			std::cout<<".";
		}

	}

	std::cout<<")_2 * 2^"<< scale <<std::endl;
	return 0;
}

int
getScale
(PRECISION decimal)
{

	if(decimal==0){return 0;}

	int scale = -MAX_EXPONENT;
	
	while(scale < MAX_EXPONENT){

		if( pow(2.,(PRECISION) scale) > decimal) {

			return scale-1;

		}
		
		scale++;

	}

	return 0;

}

PRECISION
sum
(int digits[], int scale, PRECISION decimal){

	PRECISION sum = 0.0;

	for(int i =0; i<32;i++){

		sum += (PRECISION) digits[i]*pow(2.,(PRECISION) scale-i);

	}

	return sum;
}
