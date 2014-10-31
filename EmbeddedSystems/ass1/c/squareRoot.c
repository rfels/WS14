#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(int argc, char **argv)
{
	int a,b,c,root1,root2,discriminant;
	printf("Enter 32 bit coefficients of quadratic equation ax^2+bx+c\n");
	scanf("%d",&a);
	printf("a=%d\n",a);
	scanf("%d",&b);
	printf("b=%d\n",b);
	scanf("%d",&c);
	printf("c=%d\n",c);
	
	//check for integer roots
	if(b%a != 0 || c%a != 0)
		printf("Integer roots doesn't exist for %dx^2+%dx+%d\n",a,b,c);
	else
	{
		discriminant = b*b-4*a*c; 
		printf("The discriminant is: %d \n",discriminant);
		//calculate roots
		if(discriminant>0)  
		{
			root1=(-b+sqrt(discriminant))/2*a;
			root2=(-b-sqrt(discriminant))/2*a;	
			printf("Roots of equation %dx^2+%dx+%d are: %d and %d",a,b,c,root1,root2);
		}
		else if (discriminant==0) {
			
			root1=-b/(2*a);
			printf("The root of the equation %dx^2+%dx+%d is: %d.",a,b,c,root1);
		}
		else printf("Real roots doesn't exist for %dx^2+%dx+%d\n",a,b,c);
	}
	getch();
	
	return 0;
}
