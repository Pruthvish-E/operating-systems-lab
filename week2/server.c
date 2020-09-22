#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 	
#include <dirent.h>

#define LIST "list"
#define GET "get"

int main(void)
{
	int listenfd = 0;				// listen - listen file descriptor
	int connfd = 0;					// connect - connect file descriptor
	char recvBuff[256];				
	struct sockaddr_in serv_addr;			// // A sockaddr_in is a structure containing an internet address. 
								// This structure is defined in <netinet/in.h>.
	char sendBuff[1024];
	int numrv;
	char filename[1024];

	listenfd = socket(AF_INET, SOCK_STREAM, 0);	// listen - listen for connections on a socket
							// AF_INET refers to the address family ipv4. 
							// The SOCK_STREAM means connection oriented TCP protocol.

	printf("Socket retrieve success\n");

  	memset(&serv_addr, '0', sizeof(serv_addr));	// memset() is used to fill a block of memory with a particular value.
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;			
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5050);

	bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));	//        bind - bind a name to a socket


	if (listen(listenfd, 10) == -1)			// listen - listen for connections on a socket
  	{
		printf("Failed to listen\n");
		return -1;
  	}

	while (1)
  	{
		connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);

		// TODO:  Read if the client wants a GET or a LIST using a read() systemcall.
		read(listenfd,recvBuff,256);

		// If client sends a GET

		if (strcmp(GET, recvBuff) == 0)
		{
			sleep(3);
		
			// TODO:  Read the name of the file sent by the client using the connfd file descriptor.
			read(listenfd,recvBuff,256);
			// TODO:  Open the file that we wish to transfer using open system call.
			int fd = open(sendBuff,O_RDONLY|O_CREAT);
			     /*TODO:  Read data from file and send it */

			while (1)
		        {
			        /*TODO:  First read file in chunks of 256 bytes */
				unsigned char buff[256] = {0};
				if(read(fd,buff,256)>0)
				{
					write(listenfd,buff,256);
				}
				else break;
				
			        
			        /*TODO:  If read was success, send data. to the client*/
		        }

			}    // If client sends a LIST
	
			if (strcmp(LIST, recvBuff) == 0)
    			{ 
				      // If list is sent by the client.
			      DIR *d;
		
			      struct dirent *dir;	

			      d = opendir(".");		// Open the current directory. "." means current directory
			
			      if (d)
			      {

					while ((dir = readdir(d)) != NULL)	// read the current directory
        				{

					         // TODO:  send the names of the file using the write() system call.
						write(listenfd,dir->d_name,sizeof(dir->d_name));
          					 // TODO:  Use man page of readdir to figure out how to use the "dir" variable
        				}
        				closedir(d);
      			     }
    			}
    			sleep(1);		// Suspend for 1 second
  		}
  		return 0;
}

