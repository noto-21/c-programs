#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fptr, *outptr;//Input and Output pointers
	char ch;//Char holder

	if ((fptr = fopen("Input.txt", "r")) == NULL)//Test opening input file
	{
		printf("Error opening Input.txt!\n");

		return 1;//Return w/error
	}

	if ((outptr = fopen("Heaven.txt", "w+")) == NULL)//Test opening output file
	{
		printf("Error writing to Heaven.txt!\n");
		fclose(fptr);
		return 1;//Close input file pointer and return w/error
	}

	while ((ch = fgetc(fptr)) != EOF)//Read until End-of-File
	{
		/* Replace 'A' with 'B' and 'a' with 'b' */

		if (ch == 'A')
			ch = 'B';
		else if (ch == 'a')
			ch = 'b';

		fputc(ch, outptr);//Write to Heaven.txt
	}

	printf("> Changed each \'a\' to \'b\'!\n\n" 
			"> Displaying 'Heaven.txt':\n\n");//Success message

	/* Close all pointers */

	fclose(fptr);
	fclose(outptr);

	//Open and display Heaven.txt
	if ((outptr = fopen("Heaven.txt", "r")) == NULL)
	{
		printf("Error opening Heaven.txt!\n");

		return 1;//Return w/error if fail
	}

	while ((ch = fgetc(outptr)) != EOF)
		putchar(ch);//Print all chars in Heaven.txt to screen

	printf("\n\n");//Space

	fclose(outptr);//Close output pointer

	return 0;//End main
}
