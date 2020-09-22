#include <stdio.h>
#include "dependency.h"

int main()
{
	int t = getmynumber();
	int squareOfT = squaremynumber(t);
	printf("\nMyNumber: %d and square of my number:%d\n",t,squareOfT);
	return 0;
}
