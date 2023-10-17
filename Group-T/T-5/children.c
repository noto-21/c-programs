#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void nums(int proc_id)
{
	printf("Child Process %d: ", proc_id);

	for (int i = 1; i <= 5; i++)
		printf("%d ", i);

	printf("\n");
}

int main()
{
	pid_t children[2];

	children[0] = fork();

	if (children[0] == 0)
	{
		nums(1);
		exit(0);
	}
	
	children[1] = fork();

	if (children[1] == 0)
	{
		nums(2);
		exit(0);
	}
	
	wait(NULL);//First child finishes
	wait(NULL);//Second child finishes

	printf("Parent Process\n");

	return 0;
}
