#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This function reads the file and returns the number of lines
resulting from the specified format
*/
int ReadData(FILE *fpt, char first[20][30], char last[20][30])
{
	int total=0;

	while(1)//While there is data to read
	{
		if (fscanf(fpt,"%s %s",last[total],first[total]) != 2)
			break;//Two words per line: 'last' 'first'
		total++;
	}
	
	//Total number of lines resulting from specified format
	return total;
}

/*
This function performs the ASCII conversions for each
word on each line
*/
void CapFix(char word[30])
{
	if (word[0] >= 'a' && word[0] <= 'z')//First letter capitalized
		word[0]=word[0]-'a'+'A';

	for (int i=1; i<strlen(word); i++)//Rest of the letters lowercase
		if (word[i] >= 'A' && word[i] <= 'Z')
			word[i]=word[i]-'A'+'a';
}

int main(int argc, char *argv[]) 
{
	FILE *fpt;
	char first[20][30],last[20][30];
	int i,j,total;

	if (argc != 2)//Invalid usage
	{
		printf("Usage: CAPFIX [filename]\n");
		exit(0);
	}
	
	if ((fpt=fopen(argv[1],"r")) == NULL)//Invalid file
	{
		printf("Unable to open %s for reading\n",argv[1]);
		exit(0);
	}

	total = ReadData(fpt, first, last);

	for (i=0; i<total; i++)//Fix the first word on each line
	{
		CapFix(first[i]);
	}

	for (i=0; i<total; i++)//Fix the last word on each line
	{
		CapFix(last[i]);
	}

	for (i=0; i<total; i++)//Print the result
		printf("%s %s\n",first[i],last[i]);

	fclose(fpt);//Stop file read
}
