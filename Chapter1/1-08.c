// Write a program to count blanks, tabs, and newlines
#include <stdio.h>

int main(void)
{
	char ch;
	int nb, nt, nl;
	nb = nt = nl = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
			nb++;
		else if (ch == '\t')
			nt++;
		else if (ch == '\n')
			nl++;
	}
	printf("\n# blanks   = %3d\n"
                 "# tabs     = %3d\n"
	         "# newlines = %3d\n",
	      		   nb, nt, nl);

	return 0;
}
