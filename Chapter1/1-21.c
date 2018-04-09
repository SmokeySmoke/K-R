/* Write a program entab that replaces strings of blanks by the miniumum
 * number of tabs and blanks to achieve the same spacing. Use the same 
 * tab stops as for detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference?
 */
#include <stdio.h>
#define SPACESINTAB 8
#define OUT 0
#define IN 1

int main(void)
{
	char ch, prevch = 'c';
	int inblankstr = OUT;
	int nb = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch != ' ' && prevch == ' ')
		{
			if (inblankstr)
			{
				inblankstr = OUT;
				while (nb >= SPACESINTAB)
				{
					putchar('\t');
					nb = nb - SPACESINTAB;
				}
				while (nb > 0)
				{
					putchar(' ');
					--nb;
				}
			}
			putchar(ch);
		} else if (ch == ' ')
		{
			inblankstr = IN;
			nb++;
		} else
		{
			inblankstr = OUT;
			nb = 0;
			putchar(ch);
		}
		prevch = ch;
	}

	return 0;
}
