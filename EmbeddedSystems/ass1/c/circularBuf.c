#include <stdio.h>
#include <conio.h>

#define Nmax 63

// implementation with circular buffer
int main(int argc, char **argv)
{	
	// filter data 
	int filterLength,input[Nmax],coefficients[Nmax],output[Nmax];
	
	// operation counters
	int add=0,mult=0,shift=0;
	
	// other variables
	int index,pointer,temp,sampleLength,i,k;
	
	printf("Enter the amount of coefficients (N) of the filter please.\n");
	scanf("%d",&filterLength);
	
	printf("Enter the  %d Filter coefficients please. \n",filterLength);	
	for(i=0;i<filterLength;i++)
		scanf("%d",&coefficients[i]);
	
	printf("Enter the number of samples please.\n");
	scanf("%d",&sampleLength);
	
	for(i=0;i<sampleLength;i++)  
		input[i]=0;
	
	pointer=0;
	for(i=0;i<sampleLength;i++)
	{
		printf("Enter sample value please x[%d]: ",i);	
		scanf("%d",&input[pointer]);
	
		temp = 0;
		for(k = 0; k < filterLength; k++)
		{
			index=(pointer-k)%(filterLength+1);
			if(index<0)
				continue;
			temp = temp + coefficients[k]*input[index] ; // convolution 
			add++;
			mult++;
		}
	
		pointer = (pointer+1)%(filterLength+1);
		output[i] = temp;
				
	}
	printf("The output of FIR filter using circular buffer is:\n");
	for(i=0;i< sampleLength;i++)
		printf("y[%d]:%d\t",i,output[i]);
	printf("\nThe total number of additions are: %d\tMultiplications: %d\tShift operations: %d",add,mult,shift);
	
	getch();
	return 0;
}
