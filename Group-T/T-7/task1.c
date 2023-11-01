#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int c = 1;//'Counter' (for printing line #)

void alarm_handler(int sig)//Alarm signal handler
{
	if (sig == SIGALRM)//If the alarm is triggered
	{
		printf("%d: Timer Fired!\n", c);//Print message
		c++;//Increment c
		alarm(3);//Start again
	}
}

int main()
{
	signal(SIGALRM, alarm_handler);//Register alarm signal handler

	alarm(3);//Initial alarm

	int count = 0;//Counter

	while (count < 5)//Five times
	{
		pause();//Wait for SIGALRM

		count++;//Increment counter
	}

	return 0;//Fin
}
