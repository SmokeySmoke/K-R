/* Write the function itob(n,s,b) that converts the integer n 
 * into a base b character representation in the string s. In
 * particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 */
#include <stdio.h>
#include <string.h>	// needed in reverse()
#define SLEN 25
void itob(int n, char s[], int b);
void myitoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
	char s[SLEN];
	int n, b;

	printf("Enter a decimal number and a base to convert to requested base string (EOF to quit):\n");
	while (scanf("%d %d", &n, &b) == 2)
	{
		itob(n,s,b);
		printf("  itob: %s\n", s);
		printf("Enter another set of numbers: ");
	}
	puts("Done!");	

	return 0;
}

void itob(int n, char s[], int b)
{
	int i, sign, temp;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do 
	{
		temp = n % b;
		if (temp < 10)
			s[i] = temp + '0';
		else
			s[i] = (temp-10) + 'A';
		i++;
	} while ((n /= b) > 0);
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
