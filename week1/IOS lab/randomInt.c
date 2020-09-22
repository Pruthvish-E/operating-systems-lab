#include "random.h"
#include<time.h>
int randomInt()
{
	srand(time(NULL));
	return rand()%100+2;
}
