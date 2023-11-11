/* Libraries */

#include <iostream>
#include "generator.h"
#include <time.h>

/* Main */

int main()
{
	/* Timing */
	struct timespec s, e;
	double elapse;

	clock_gettime(CLOCK_MONOTONIC, &s);//Record initial time

	FILE *spam = fopen("Spam.txt", "w");//Open/create 'Spam.txt'
	if (spam == NULL)//Error opening/making file
	{
		perror("Error opening file!");
		return 1;
	}

	int generated = generate(spam);//Return result of user-defined function
	if (generated == -1)//Error writing to 'Spam.txt'
	{
		perror("Error writing to file!");
		fclose(spam);
		return -1;
	}

	fclose(spam);//Close fp to 'Spam.txt'
	
	clock_gettime(CLOCK_MONOTONIC, &e);//Record final time
	elapse = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1e9;//Calculate elapsed time in sec.

	printf("> Random chars written to 'Spam.txt'!\n");//Success message
	printf("> Elapsed time: %f seconds\n", elapse);//Time elapsed
	
	return 0;//Fin
}
