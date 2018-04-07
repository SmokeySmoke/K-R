/* Write a program to copy its input to its output, replacing each string
 * of one or more blanks by a single blank;
 */
#include <stdio.h>

int main(void)
{
	char ch, prevch = '0';

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ' && prevch == ' ')
			continue;
		else
			putchar(ch);
		prevch = ch;
	}

	return 0;
}
