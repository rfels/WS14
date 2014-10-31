#include <stdio.h>
#include <conio.h>

#define Nmax 63

//implementation without circular buffer, with shift operations
int main(int argc, char **argv)
{	
	// filter data 
	int filterLength,input[Nmax],coefficients[Nmax],output[Nmax];
	
	// operation counters
	int add=0,mult=0,shift=0;
	
	// other variables
	int sampleLength,temp,i,k;
	
	printf("Enter the amount of coefficients (N) of the filter please.\n");
	scanf("%d",&filterLength);
	
	printf("Enter the  %d Filter coefficients please. \n",filterLength);	
	for(i=0;i<filterLength;i++)
		scanf("%d",&coefficients[i]);
		
	printf("Enter the number of samples please.\n");
	scanf("%d",&sampleLength);
	
	for(i=0;i<sampleLength;i++)  //set input buffer to 0
		input[i]=0;
	
	for(i=0;i<sampleLength;i++)
	{
		printf("Enter sample value please x[%d]: ",i);	
		scanf("%d",&input[0]);
	
		temp = 0;
		for(k = 0; k < filterLength; k++)
		{
			if( (i - k) >= 0)
				temp = temp + coefficients[k]*input[k] ; // convolution
				mult++;
				add++;
		}
		
		for (k = filterLength; k > 0; k--)
			input[k] = input[k-1]; // shift operation
		shift++;
		
		output[i] = temp;
				
	}
	printf("The output of FIR filter is:\n");
	for(i=0;i<sampleLength;i++)
		printf("y[%d]:%d\t",i,output[i]);
	printf("\nThe total number of additions are: %d\tMultiplications: %d\tShift operations: %d",add,mult,shift);
	
	getch();
	return 0;
}
