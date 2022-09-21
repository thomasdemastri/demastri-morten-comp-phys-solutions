/*
 * A simple program to test some i/o things
 *
*/

#include <iostream>
#include <math.h>

int
main(int argc, char* argv[]){

	if(argc==1){
	
		std::cout<<"Bad usage, please pass an argument to this program." <<std::endl;
		exit(1);
	
	}

	double arg;
	arg = atof(argv[1]);
	
	std::cout<<"Hello World! sin("<<arg<<")="<<sin(arg)<<std::endl;

}

