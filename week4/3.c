/* Zombie process */

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
		printf("Parent sleeps\n");
		sleep(20);
		exit(0);
	}
	else if (pid == 0)
	{
		printf("In child\n");
		printf("Child process ID : %d\n",getpid());
		printf("Parent -ID: %d\n",getppid());
		exit(0);

	}
	else
	{
		printf("error while forking\n");
	}
	
	return 0;
}

