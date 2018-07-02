/* Extend atof to handle scientific notation of the form
 *
 * 	123.45e-6
 *
 * where a floating-point number may be followed by e or E
 * and an optionally signed exponent.
 */
#include <stdio.h>
#include <ctype.h>
#define SLEN 64

/* atof:	convert string s to double */
double atof(char s[]);

int main(void)
{
	char string[SLEN];

	puts("Enter strings to test atof() (EOF to quit):");
	while (scanf("%s", string) == 1)
		printf("%s -> %lf\n\n", string, atof(string));
	puts("Done!");

	return 0;
}

double atof(char s[])
{
	double val, power, eval, retval;
	int i, sign, esign;

	for (i = 0; isspace(s[i]); i++)	// skip white space
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
/* my extension begins */	
	retval = sign * val / power; 
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	esign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (eval = 0.0; isdigit(s[i]); i++)
		eval = 10.0 * eval + (s[i] - '0');
	if (esign < 0)
		while (eval-- > 0)
			retval /= 10;
	else
		while (eval-- > 0)
			retval *= 10;
	return retval;
}
