/* Write a program detab that replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */
#include <stdio.h>
#define TABSTOPLIM 10
#define SPACESINTAB 8

int main(void)
{
	char ch;
	int i, tabstop = SPACESINTAB;

	while ((ch = getchar()) != EOF)
	{
		if (ch == '\t')
		{
			while (tabstop > 0)
			{
				putchar(' ');
				tabstop--;
			}
			tabstop = SPACESINTAB;
		} else
		{
			putchar(ch);
			--tabstop;
			if (ch == '\n' || tabstop == 0)
				tabstop = SPACESINTAB;
		}
	}

	return 0;
}
