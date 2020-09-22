#include <stdio.h>

int main()
{
	int i,num,j;
	j = 1;
	printf("Enter the Number: ");
	scanf("%d",&num);
	
	for(int i =1;i<=num;i++) 
		j=j*i;
	
	printf("the Factorial of %d is %d\n",num,j);
}

