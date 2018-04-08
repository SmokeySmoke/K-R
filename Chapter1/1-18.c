/* Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int main(void)
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */
	char ch, prevch = 'c';

	len = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			if (prevch != '\n')
			{
				if (len >= MAXLINE)
					line[MAXLINE-1] = '\0';
				else
					line[len] = '\0';
				printf("%s\n", line);
			}
			len = 0;
		} else
		{
			if (len < MAXLINE)
				line[len] = ch;
			if ((prevch != ' ' && prevch != '\t') ||
				       	((prevch == ' ' || prevch == '\t') && (ch != ' ' && ch != '\t')))
				len++;
		}
		prevch = ch;
	}

	return 0;
}
