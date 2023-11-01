#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char buf[255];
	int byte_out;//Bytes for sending output from child
	int pid;//PID for child process
	int pfd[2][2];//Two arrays of two ints for pipe r/w between parent/child
		      //pfd[0] is parent-to-child; pfd[1] is child-to-parent

	if (pipe(pfd[0]) == -1 || pipe(pfd[1]) == -1)//Pipe fail
	{
		perror("Pipe Creation Failed!");
		exit(EXIT_FAILURE);
	}
	if ((pid = fork()) > 0)//Parent
	{
		close(pfd[0][0]);//Close read of p2c
		close(pfd[1][1]);//Close write of c2p
				 
		const char *mssg = "'Hello' from Parent!";//Send message to child
		write(pfd[0][1], mssg, strlen(mssg));

		byte_out = read(pfd[1][0], buf, sizeof(buf));//Read from child
		if (byte_out > 0)
		{
			buf[byte_out] = '\0';//Terminate string
			printf("Parent received %s\n", buf);//Print proof of reception
		}

		close(pfd[0][1]);//Close write of p2c
		close(pfd[1][0]);//Close read of c2p
	}
	else//Child
	{
		close(pfd[0][1]);//Close write of p2c
		close(pfd[1][0]);//Close read of c2p

		byte_out = read(pfd[0][0], buf, sizeof(buf));//Read from parent
		if (byte_out > 0)
		{
			buf[byte_out] = '\0';//Terminate string
			printf("Child received %s\n", buf);//Print proof of reception
		}

		const char *resp = "'Hello' from Child!";//Send message to parent
		write(pfd[1][1], resp, strlen(resp));

		close(pfd[0][0]);//Close read of p2c
		close(pfd[1][1]);//Close write of c2p
	}

	return EXIT_SUCCESS;//Fin
}
