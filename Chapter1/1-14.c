// Write a program to print a histogram of the frequencies of different characters in its input. 
#include <stdio.h>
#define NUMALPHA 26

int main(void)
{
	char ch;
	int i, j, biggest;
	int alphafreq[NUMALPHA] = {0};
	int nonalpha = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
			alphafreq[ch - 'a']++;
		else if (ch >= 'A' && ch <= 'Z')
			alphafreq[ch - 'A']++;
		else
			nonalpha++;
	}
	putchar('\n');
	printf("\tFrequency of characters\n");
	for (i = 'a'; i <= 'z'; i++)	// horizontal histogram
	{
		printf("%c | ", i);
		for (j = 0; j < alphafreq[i - 'a']; j++)
			putchar('*');
		putchar('\n');
	}
	printf("\n%d non-alphabet characters.\n", nonalpha);

	for (i = 0; i < NUMALPHA; i++)
		printf("=========");

	biggest = nonalpha;
	for (i = 0; i < NUMALPHA; i++)	// vertical histogram
		if (alphafreq[i] > biggest)
			biggest = alphafreq[i];
	putchar('\n');
	for (i = biggest; i > 0; i--)
	{
		for (j = 0; j < NUMALPHA; j++)
		{
			if (alphafreq[j] >= i)
				printf("*\t");
			else
				printf(" \t");
		}
		if (nonalpha >= i)
			printf("%4c\t", '*');
		putchar('\n');
	}
	for (i = 0; i < NUMALPHA; i++)
		printf("_________");
	putchar('\n');
	for (i = 'A'; i <= 'Z'; i++)
		printf("%c\t", i);
	printf("NON-ALPHA");
	printf("\n \t \t \t  CHARACTER FREQUENCY\n");
	
	return 0;
}
