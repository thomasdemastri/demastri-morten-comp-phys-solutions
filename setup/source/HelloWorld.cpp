#include <math.h>
#include <string>
#include <iostream>

#include "../include/ScientificHelloWorld.h"


int main(){

	std::string message = "Hello World!";
	double argument = 0.0;

	ScientificHelloWorld* helloWorld = new ScientificHelloWorld(message,argument);

	helloWorld->printMessage();

}
