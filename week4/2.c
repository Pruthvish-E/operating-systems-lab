//Orphan process
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
		exit(0);
	}
	else if (pid == 0)
	{
		printf("In child\n");
		printf("Child process ID : %d\n",getpid());
		printf("Parent -ID: %d\n",getppid());

		sleep(10);

		printf("After child process sleeps\n");
		printf("\nChild process ID : %d\n",getpid());
		printf("Parent -ID: %d\n",getppid());
	}
	else
	{
		printf("error while forking\n");
	}
	
	return 0;
}

