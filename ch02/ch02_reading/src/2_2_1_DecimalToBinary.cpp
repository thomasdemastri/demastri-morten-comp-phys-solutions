/**
 *
 * A program that converts decimal integers to a binary represenatation
 *
 */

#include<iostream>
#include<cmath>

int 
main
(int argc, char* argv[])
{
	if(argc==1){
	
		std::cout<<"Bad usage, please pass exactly one argument"<<std::endl;
		exit(1);	
	}

	int decimal = atoi(argv[1]);
	int digits[32];

	int index;

	// initialize all values of the array to zero
	for(int j = 0;j<32;j++){
		digits[j]=0;
	}

	std::cout << decimal << " can be represented with ";
 
	for(index = 0; index<32; index++){

		if(decimal==0 && index>0){
			break;
		}

		digits[31-index] = decimal%2;
		decimal /= 2;
	}

	std::cout << index << " bits!" << std::endl;


	std::cout<<"(";

	for(int i=32-index;i<32;i++){

		std::cout<<digits[i];

	}

	std::cout<<")_2"<<std::endl;


}
