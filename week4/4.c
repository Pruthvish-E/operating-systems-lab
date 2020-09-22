/* parent displays uppercase A-Z and child displays lowercase a-z with delay of 2 seconds to demonstrate racing*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	

	int pid = fork();
	if (pid > 0)
	{
		printf("In parent\n");
		printf("Parent process ID : %d\n",getpid());
		for(char i = 'A';i<='Z';i++)
		{
			printf("Parent : %c\n",i);
		}
		sleep(1);
	}
	else if (pid == 0)
	{
		printf("In child\n");
		printf("Child process ID : %d\n",getpid());
		printf("Parent -ID: %d\n",getppid());

		for(char i = 'a';i<='z';i++)
		{
			printf("Child : %c\n",i);
		}

	}
	else
	{
		printf("error while forking\n");
	}
	
	return 0;
}

