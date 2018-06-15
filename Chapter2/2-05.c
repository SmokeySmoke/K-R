/* Write the function any(s1,s2), which returns the first location in a string s1
 * where any character from the string s2 occurs, or -1 if s1 contains no characters
 * from s2. (The standard library function strpbrk does the same job but returns a
 * pointer to the location.)
 */
#include <stdio.h>
#define SLEN 15
int any(char s1[], char s2[]);

int main(void)
{
	char s1[SLEN], s2[SLEN];
	int index;

	puts("Enter first word (EOF to quit):");
	while (scanf("%s", s1) == 1)
	{
		puts("Enter second word:");
		scanf("%s", s2);

		index = any(s1, s2);
		if (index < 0)
			puts("Not found!");
		else
		{
			printf("First character from %s found in %s is \'%c\'\n\n", s2, s1, s1[index]);
			puts(s1);
			while (index-- > 0)
				putchar(' ');
			putchar('^');
		}
		puts("\nEnter another word(EOF to quit):");
	}
	puts("Done!");

	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	return -1;
}				
