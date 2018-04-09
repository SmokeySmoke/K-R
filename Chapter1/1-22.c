/* Write a program to "fold" long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with
 * very long lines, and if there are no blanks or tabs before the specified
 * column.
 */
#include <stdio.h>
#define NCOL_IN 10

int main(void)
{
	char ch; 
	int nc = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ' || ch == '\t' || ch == '\n')
		{
			nc = 1;
			while (ch == ' ' || ch == '\t')
				ch = getchar();
			putchar('\n');
		} else
			++nc;
		if (nc > NCOL_IN)
		{
			nc = 1;
			putchar('\n');
		}
		putchar(ch);

	}

	return 0;
}

