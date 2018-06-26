/* In a two's complement number representation, our version of itoa does not handle the
 * largest negative number, that is, the value of n equal to -(2^wordsize-1). Explain why not.
 * Modify it to print that value correctly, regardless of the machine on which it runs.
 */
#include <stdio.h>
#include <string.h>	// needed in reverse()
#define SLEN 25
void itoa(int n, char s[]);
void myitoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
	char s[SLEN];
	int n;

	printf("Enter a number to convert to a string (EOF to quit):\n");
	while (scanf("%d", &n) == 1)
	{
		itoa(n,s);
		printf("  itoa: %s\n", s);
		myitoa(n,s);
		printf("myitoa: %s\n", s);
		printf("Enter another number: ");
	}
	puts("Done!");	

	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
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
	s[i] = '\0';
	reverse(s);
}

void myitoa(int n, char s[])
{
	int i, sign = n;
	_Bool isMin = 0;

	if (n < 0)
	{
		if (-n < 0)
		{
			++n;
			isMin = 1;
		}
		n = -n;
	}

	i = 0;
	do 
	{
		s[i] = n % 10 + '0';
		if (isMin)
		{
			s[i]++;
			isMin = 0;
		}
		i++;
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
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
