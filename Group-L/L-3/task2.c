#include <stdio.h>
#include <string.h>

int main()
{
	FILE *in, *out;//Input and Ouptut file pointers
	char targ[][50] = {"Inferno", "In dark woods", "those woods", "to enter", "crest", "Below a hill", "shoulders", "planet", "dante"};//Phrases to look out for
	char rep[][50] = {"Paradisio", "using Windows 8.1", "Windows 8.1", "to use 8.1", "screen", "Before a monitor", "GUI", "UNIX", "Shakespeare"};//Phrases to replace the target phrases with

	if ((in = fopen("Input.txt", "r")) == NULL)//Try to open Input.txt
	{
		perror("Error opening Input.txt!");
		return 1;//Return error if fopen returns NULL
	}

	if ((out = fopen("Dante.txt", "w+")) == NULL)//Try to write to Dante.txt
	{
		perror("Error creating Dante.txt");
		
		fclose(in);//Close input FP

		return 1;//Return error if fopen returns NULL
	}

	char buff[1024];//Buffer saves lines from Input.txt

	while (fgets(buff, sizeof(buff), in))//While there are still lines to read from Input.txt
	{
		char outBuff[1024];//Buffer for storing modified output line
		outBuff[0] = '\0';//Initialize output buffer

		char *buffPt = buff;//Pointer to start of buffer

		for (int i = 0; i < sizeof(targ) / sizeof(targ[0]); i++)
		{
			char *pos = strstr(buff, targ[i]);//Points to occurrence of one of the target strings

			while (pos != NULL)
			{
				int index = (pos - buffPt);//Find pos. of target string
				strncat(outBuff, buffPt, index);//Copy original line up to the match
				strcat(outBuff, rep[i]);//Append replacement string
				buffPt = buffPt + index + strlen(targ[i]);//Move buffer forward
				pos = strstr(buffPt, targ[i]);//Search for next occurrence of target string
			}
		}
		strcat(outBuff, buffPt);//Copy remaining content from input buffer to output buffer

		fputs(outBuff, out);//Write modified line to Dante.txt
	}

	printf("> Switched target phrases with their replacements!\n\n"
			"> Displaying \'Dante.txt\':\n\n");//Success message
	
	/* Close file pointers */

	fclose(in);//Close input FP
	fclose(out);//Close output FP

	/* Open and display Dante.txt */

	if ((out = fopen("Dante.txt", "r")) == NULL)
	{
		printf("Error opening Dante.txt!\n");

		return 1;//Return error if Dante.txt cannot be opened
	}

	char ch;//Placeholder char

	while ((ch = fgetc(out)) != EOF)//While there are still lines to be read
		putchar(ch);//Print all chars in Dante.txt to screen

	printf("\n\n");//Space

	fclose(out);//Close output FP

	return 0;//End main
}
