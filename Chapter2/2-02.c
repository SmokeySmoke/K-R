/* Write a loop equivalent to the for loop above without
 * using && or ||.
 */
#include <stdio.h>
void orig(void);
int main(void)
{
	int i = 0;
	int lim = 10;
	char s[lim], c;

	puts("ORIGINAL:");
	orig();

	puts("\nMINE:");
	while (i < lim-1)
	{
		c = getchar();
		if (c != '\n')
		{
			if (c != EOF)
			{
				s[i] = c;
				++i;
			}
			else
				i = lim-1;
		} else
			i = lim-1;
	}

	for (i = 0; i < lim; i++)
		putchar(s[i]);
	putchar('\n');

	return 0;
}

void orig(void)
{
	int i;
	int lim = 10;
	char s[lim], c;

	for (i = 0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	
	for (i = 0; i < lim; i++)
		putchar(s[i]);
	putchar('\n');
}
