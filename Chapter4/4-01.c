/* Write the function strindex(s,t) which returns the position of the rightmost occurance
 * of t in s, or -1 if there is none.
 */
#include <stdio.h>
#include <stdbool.h>
#define SLEN 128
#define TARGET_S "ary"
int strindex(const char s[], const char t[]);

int main(void)
{
	char string[SLEN];
	int index;

	printf("Enter a string to search for target string \"%s\" (EOF to quit):\n", TARGET_S);
	while (scanf("%s", string) == 1)
	{
		putchar('\n');
		if ((index = strindex(string, TARGET_S)) != -1)
		{
			printf("Target string: %s\n", TARGET_S);
			printf("Source string: %s\n", string);
			while (index-- != 0)
				putchar(' ');
			puts(  "               ^\n");
		}
		else
			puts("Target not found!");
		puts("Enter another string: ");
	}
	puts("Done!");

	return 0;
}

int strindex(const char s[], const char t[])
{
	int i, j, targeti;
	bool found = false;

	for (j = i = 0; s[i] != '\0'; i++)
		if (s[i] == t[0])
		{
			targeti = i;
			while (t[++j] != '\0')
				if (s[i+j] != t[j])
					break;
			if (t[j] == '\0')
				found = true;
		}
	return found ? targeti : -1;
}
