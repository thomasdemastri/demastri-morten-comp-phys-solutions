/*

A Very simple setup program to ensure that my C++ 
environment is up and running :) 

*/


#include <iostream>
#include <math.h>
#include <string>
#include "../include/ScientificHelloWorld.h"

class ScientificHelloWorld;

ScientificHelloWorld::ScientificHelloWorld(std::string phrase, double argument){
	message = phrase;
	arg = argument;
}

void ScientificHelloWorld::printMessage(){
	answer = sin(arg);
	std::cout<<message<<" sin(" << arg <<")="<<answer<< "\n";	
}
