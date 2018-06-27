/* Write a version of itoa that accepts three arguments instead of two. The third argument is a
 * minimum field width; the converted number must be padded with blanks on the left if necessary
 * to make it wide enough.
 */
#include <stdio.h>
#include <string.h>	// needed in reverse()
#define SLEN 25
void itoa(int n, char s[], int fw);
void myitoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
	char s[SLEN];
	int n, fw;

	printf("Enter a number and a field width to convert to a string (EOF to quit):\n");
	while (scanf("%d %d", &n, &fw) == 2)
	{
		itoa(n,s,fw);
		puts(s);
		printf("Enter another number: ");
	}
	puts("Done!");	

	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int fw)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do 
	{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	while (i < fw)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
