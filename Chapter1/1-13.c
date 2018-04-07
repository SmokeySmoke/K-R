/* Write a program to print a histogram of the lengths of words in its input. Its easy to draw 
 * the histogram with the bars horizontal; a vertical orientation is more challenging.
 */
#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXWLEN 10

int main(void)
{
	char ch;
	int wlen = 0;
	int biggest = 0;
	int ovflow = 0;
	int state = OUT;
	int wrdlen[MAXWLEN] = {0};
	int i, j;

	while ((ch = getchar()) != EOF)	// count word lengths and store in appropriate array index
	{
		if ((ch == ' ' || ch == '\t' || ch == '\n') && state == IN)
		{
			state = OUT;
			if (wlen > MAXWLEN)
				ovflow++;
			else
				wrdlen[wlen-1]++;
			wlen = 0;
		} else
		{
			state = IN;
			wlen++;
		}
	}
	putchar('\n');
	printf("\tFrequency of word length\n");
	for (i = 0; i < MAXWLEN; i++)	// horizontal histogram
	{
		printf("%2d | ", i+1);
		for (j = 0; j < wrdlen[i]; j++)
			putchar('*');
		putchar('\n');
	}
	printf("\n%d words over %d letters.\n", ovflow, MAXWLEN);

	for (i = 0; i < MAXWLEN; i++)
		printf("=========");

	biggest = ovflow;
	for (i = 0; i < MAXWLEN; i++)	// vertical histogram
		if (wrdlen[i] > biggest)
			biggest = wrdlen[i];
	putchar('\n');
	for (i = biggest; i > 0; i--)
	{
		for (j = 0; j < MAXWLEN; j++)
		{
			if (wrdlen[j] >= i)
				printf("*\t");
			else
				printf(" \t");
		}
		if (ovflow >= i)
			printf("%4c\t", '*');
		putchar('\n');
	}
	for (i = 0; i < MAXWLEN; i++)
		printf("_________");
	putchar('\n');
	for (i = 1; i <= MAXWLEN; i++)
		printf("%d\t", i);
	printf("OVERFLOW");
	printf("\n \t \t \t  WORD LENGTH\n");
	
	return 0;
}
