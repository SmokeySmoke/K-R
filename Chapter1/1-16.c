/* Revise the main routine of the longest-line program so it will correctly print the
 * length of arbitrary long input lines, and as much as possible of the text.
 */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getlin(char [], int);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
	int len;			/* current line length */
	int max;			/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];		/* longest line saved here */
	char ch;

	max = len = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			if (len >= MAXLINE)
				line[MAXLINE-1] = '\0';
			else
				line[len] = '\0';
			if (len > max)
			{
				max = len;
				copy(longest, line);
			}
			len = 0;

		} else
			len++;
		if (len < MAXLINE)
			line[len] = ch;
	}
	if (max > 0)	/* there was a line */
		printf("\n\n%d characters counted: %s\n", max, longest);

	return 0;
}

/* getlin: read a line into s, return length */
int getlin(char s[], int lim) 
{

	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) 
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
