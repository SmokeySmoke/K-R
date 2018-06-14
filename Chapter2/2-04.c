/* Write an alternative version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string
 * s2
 */
#include <stdio.h>
#define SLEN 15
void squeeze(char s1[], char s2[]);

int main(void)
{
	char s1[SLEN], s2[SLEN];

	puts("Enter first word (EOF to quit):");
	while (scanf("%s", s1) == 1)
	{
		puts("Enter second word:");
		scanf("%s", s2);
		printf("\n%s => ", s1);
		squeeze(s1,s2);
		puts(s1);
		puts("\nEnter another word(EOF to quit):");
	}
	puts("Done!");

	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				for (k = i; s1[k] != '\0'; k++)
					s1[k] = s1[k+1];
}				
