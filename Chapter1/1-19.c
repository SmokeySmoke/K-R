/* Write a function reverse that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.
 */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int main(void)
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */
	char ch;

	len = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			if (len >= MAXLINE)
				line[MAXLINE-1] = '\0';
			else
				line[len] = '\0';
			for (int i = len < MAXLINE ? len-1 : MAXLINE-1; i >= 0; i--)
				putchar(line[i]);
			len = 0;
			putchar('\n');
		} else
		{
			if (len < MAXLINE)
				line[len] = ch;
			len++;
		}
	}

	return 0;
}
