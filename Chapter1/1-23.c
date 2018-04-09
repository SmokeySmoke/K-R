/* Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants
 * properly. C comments don't nest.
 */
#include <stdio.h>

int main(void)
{
	char ch, prevch = 'c';

	while ((ch = getchar()) != EOF)
	{
		if (ch == '/')
		{
			prevch = ch;
		       	if ((ch = getchar()) == '*')		// remove header comments
				while ((ch = getchar()) != '/' || prevch != '*')
					prevch = ch;
			else if (ch == '/')
			{
				while (ch != '\n')		// remove these comments
					ch = getchar();
				putchar(ch);
			} else
			{
				putchar(prevch);
				putchar(ch);
			}
		} else 
		{
			putchar(ch);
			prevch = ch;
		}
	}

	return 0;
}
