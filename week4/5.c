/* demonstrate how local and global variables are shared or not shared by the parent and child processes*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int global=100; 

int main()
{
	

	int local = 1;
	int *heap = malloc(sizeof(int));
	*heap = 2;
	int pid = fork(); 
	if (pid > 0)
	{
		printf("In parent\n");
		printf("Parent process ID : %d\n",getpid());
		printf("Parent:- global: %d , local: %d ,heap: %d\n",global,local,*heap);
		
	}
	else if (pid == 0)
	{
		printf("In child\n");
		printf("Child process ID : %d\n",getpid());
		printf("Parent -ID: %d\n",getppid());
		printf("Child without changing variables:- global: %d , local: %d ,heap: %d\n",global,local,*heap);
		local = 10;
		global = 2000;
		*heap = 20;
		printf("Child process after changing variables:- global: %d , local: %d ,heap: %d\n",global,local,*heap);		

	}
	else
	{
		printf("error while forking\n");
	}
	
	return 0;
}


