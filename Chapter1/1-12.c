// Write a program that prints its input one word per line.
#include<stdio.h>
#define IN 1
#define OUT 0

int main(void)
{
	char ch;
	int state = OUT;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ' && state == IN)
		{
			putchar('\n');
			state = OUT;
		} else
		{
			putchar(ch);
			state = IN;
		}
	}

	return 0;
}	
