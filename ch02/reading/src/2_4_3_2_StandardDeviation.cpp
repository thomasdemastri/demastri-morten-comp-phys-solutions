/**
 *
 * A program to further demonstrate the risks of numerical precision errors.
 * We calculate standard deviation in two different ways - firstly via summing the square of the average
 * and the average of the square, subtracting and dividing by the proper amount. The second way we perform subtractions
 * individually before summing.
 */

#include <iostream>
#include <math.h>

#define PRECISION float
#define STARTING_POINT (PRECISION) 1.0E+4

void initializeArray(PRECISION arr[],int size);
PRECISION sumArray(PRECISION arr[], int size);
PRECISION averageArray(PRECISION arr[], int size);
PRECISION sumSqArray(PRECISION arr[], int size);

PRECISION sigmaTextbook(PRECISION arr[], int N);
PRECISION sigmaImproved(PRECISION arr[], int N);



int 
main
(int argc, char** argv)
{

	int N = 128;

	PRECISION data[N];
	initializeArray(data,N);
	
	PRECISION sigma1,sigma2;

	sigma1 = sigmaTextbook(data,N);
	sigma2 = sigmaImproved(data,N);

	std::cout << "sigma1=" << sigma1 << std::endl;
	std::cout << "sigma2=" << sigma2 << std::endl;

}

PRECISION
sigmaImproved
(PRECISION arr[], int N)
{

	PRECISION average, sumImproved;

	average = averageArray(arr,N);

	sumImproved = 0.0;

	for
	(int i = 0; i<N; i++)
	{
		sumImproved += (arr[i]-average)*(arr[i]-average);
	}

	return sqrt(sumImproved/((PRECISION) (N-1)));
}

PRECISION 
sigmaTextbook
(PRECISION arr[], int N)
{

	PRECISION sum,average,sumSq;
	
	sum = sumArray(arr,N);
	average = averageArray(arr,N);
	sumSq = sumSqArray(arr,N);

	return sqrt((sumSq-average*sum)/((PRECISION) (N-1)));
}


void 
initializeArray
(PRECISION arr[], int size)
{

	for(int i=0;i<size;i++){

		arr[i]=(PRECISION) ((PRECISION) STARTING_POINT+ (PRECISION) i);

	}

}

PRECISION 
sumArray
(PRECISION arr[], int size)
{

	PRECISION sum = 0.0;

	for(int i=0;i<size;i++){

                sum+=arr[i];

        }

	return sum;

}

PRECISION
averageArray
(PRECISION arr[], int size)
{

	PRECISION sum = sumArray(arr, size);

	return sum/((PRECISION) size);

}

PRECISION
sumSqArray
(PRECISION arr[], int size)
{

        PRECISION sumSq = 0.0;

        for(int i=0;i<size;i++){

                sumSq+=arr[i]*arr[i];

        }

        return sumSq;

}

