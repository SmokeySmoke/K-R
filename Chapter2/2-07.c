/* Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed to 0 and vice versa)
 * leaving the others unchanged.
 */

#include <stdio.h>
#include <limits.h>	// for CHAR_BIT, # of bits per char
char * itobs(int, char *);
void show_bstr(const char *);
int invert(int x, int p, int n);

char bin_str[CHAR_BIT * sizeof (int) + 1];

int main(void)
{
	int number;
	int x, p, n;

	puts("Enter the target number to invert, bit position, and bit field.\n"
             "q to quit\n");
	while (scanf("%d %d %d", &x, &p, &n) == 3)
	{
		number = invert(x,p,n);

		printf("\n%d with %d bits that begin at position %d inverted: %d\n", x, n, p, number);

		itobs(x, bin_str);
		printf("%5d: ", x);
		show_bstr(bin_str);
		putchar('\n');

		itobs(number, bin_str);
		printf("%5d: ", number);
		show_bstr(bin_str);
		putchar('\n');

		puts("\nEnter another set of numbers (q to quit):");
	}
	puts("Bye!");

	return 0;
}

int invert(int x, int p, int n)
{
	int mask = ~(~0 << n) << p+1-n;

	return (x&~mask) | ~(x&mask) & mask;
}

char * itobs(int n, char * ps)
{
	int i;
	static const int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';	// assume ASCII or similar
	ps[size] = '\0';

	return ps;
}

/* show binary string in blocks of 4 */
void show_bstr(const char * str)
{
	int i = 0;

	while (str[i])	// not the null charachter
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}

