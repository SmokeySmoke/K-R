// Write a program to print all input lines that are longer than 80 characters.
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */
#define BREAK 80	// breakpoint to print line

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
			if (len > BREAK)
				printf("%s\n", line);
			len = 0;

		} else
			len++;
		if (len < MAXLINE)
			line[len] = ch;
	}

	return 0;
}
