/* Libraries */

#include <stdio.h>
#include <stdlib.h>

/* Count Function */
int count_char(const char *f_in, char targ)
{
	int count = 0;//Counter
	int c;//Target char

	FILE *file = fopen(f_in, "r");//Read file
	if (file == NULL)//Error opening file
	{
		perror("Error opening file!");
		exit(1);
	}

	while ((c = fgetc(file)) != EOF)//While there are still chars to read
	{
		if (c == targ)//If the char matches the intended target char
			count++;
	}

	fclose(file);//Close fp
	
	return count;
}


/* Main */

int main(int argc, char *argv[])//Take params from cli
{
	if (argc != 3)//Correct arg amnt.
	{
		printf("Usage: %s <filename> <target char>\n", argv[0]);
		return 1;
	}

	const char *fn = argv[1];//Pointer to specified file
	char targ = argv[2][0];//Specified char to look for (first char given is taken)
			       //
	int char_count = count_char(fn, targ);//Call function w/specified arguments

	printf("> %s '%c' Count: %d\n", fn, targ, char_count);//Target chars counted in specified file
	
	return 0;//Fin
}
