/*
 * fir.c
 *
 *  Created on: Aug 18, 2014
 *      Author: Robert Fels
 */

#include <stdio.h>
#include <stdlib.h>

#define Nmax 63

//variables for FIR filter

struct firFilter {
	int length;
	int *coefficients;
	int *delay;
	int *impulseResponse;
	int count;
};


int getOutput (struct firFilter *firPointer, int input) {
	firPointer->delay[firPointer->count] = input;
	int output = 0;
	int idx = firPointer->count;
	int i;
	for (i = 0; i < firPointer->length; i++) {
		output += firPointer->impulseResponse[i] * firPointer->delay[firPointer->count];
		firPointer->count--;
		if (idx<0) idx = firPointer->length-1;
	}
	firPointer->count++;
	if (firPointer->count >= firPointer->length) firPointer->count=0;
	return output;
}

void freeMem() {

}



int main(int argc, char **argv) {
	//flush for eclipse console output
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct firFilter fir;

	printf("Let's configure the FIR filter.\nThe maximum Value of N is set to %d! \n", (Nmax+1));

	printf("Do you want to do want to make a test run without preconfigurering all the variables? Please type [y|n]: ");
	char preconf;
	scanf("%c",&preconf);

	if (preconf=='n') {
		printf("Please type in the number of coefficients you want to use for the FIR filter:");
		scanf("%d",&fir.length);
	}
	else fir.length = 63;

	fir.coefficients=malloc(fir.length*sizeof(int));
	fir.impulseResponse=fir.coefficients;
	fir.delay=malloc(fir.length*sizeof(int));
	fir.count=0;
	int i =0;

	int coeff[] =
		{
		 -1468, 1058,   594,   287,    186,  284,   485,   613,
		   495,   90,  -435,  -762,   -615,   21,   821,  1269,
		   982,    9, -1132, -1721,  -1296,    1,  1445,  2136,
		  1570,    0, -1666, -2413,  -1735,   -2,  1770,  2512,
		  1770,   -2, -1735, -2413,  -1666,    0,  1570,  2136,
		  1445,    1, -1296, -1721,  -1132,    9,   982,  1269,
		   821,   21,  -615,  -762,   -435,   90,   495,   613,
		   485,  284,   186,   287,    594, 1058, -1468
		};

	printf("The number of coefficients is set to %d.\n",fir.length);

	if (preconf=='n') {
		printf(" Please enter each coefficient.\n");

		while (i<fir.length) {
			printf("Coefficient %d:",i+1);
			scanf("%d",fir.coefficients+i);
			i++;
		}

	}
	else {
		fir.coefficients = &coeff[0];
	}



	printf("You set the coefficients to: {");
	i=0;
	while (i<fir.length) {
		printf("%d, ",*(fir.coefficients+i));
		i++;
	}
	printf("}\n");


	int input;
	printf("Now please type the input x(n) integer value:");
	scanf("%d",&input);

	int output = getOutput(&fir,input);
	printf("The output is: %d", output );


	freeMem();
	return 0;
}
