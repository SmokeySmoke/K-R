/* Write a function expand(s1,s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */
#include <stdio.h>
#include <stdbool.h>
#define SLEN 40
void expand(char s1[], char s2[]);

int main(void)
{
	char s1[SLEN];
	char s2[SLEN];

	puts("Enter a shorthand string in the format a-z or 0-1\n"
	     "(EOF to quit):");
	while (scanf("%s", s1) == 1)
	{
		printf("Original string: %s\n", s1);
		expand(s1,s2);
		printf("Expanded string: %s\n", s2);
		puts("\nEnter another string: ");
	}
	puts("Done!");

	return 0;
}

void expand(char s1[], char s2[])
{
	bool hyph_found = false;
	char start, end;
	int i, j = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == '-')
		{
			hyph_found = true;
			start = s1[i-1];
			end = s1[i+1];
		}
		if (hyph_found)
		{
			if (start == s2[j-1])
				j--;
			while (start <= end)
				s2[j++] = start++;
			s2[j] = '\0';
		}
		hyph_found = false;
	}
}
