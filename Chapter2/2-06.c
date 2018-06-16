/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position
 * p set to the rightmost n bits of y, leaving the other bits unchanged.
 */
#include <stdio.h>
#include <limits.h>	// for CHAR_BIT, # of bits per char
char * itobs(int, char *);
void show_bstr(const char *);
int getbits(int x, int p, int n);
int setbits(int x, int p, int n, int y);

char bin_str[CHAR_BIT * sizeof (int) + 1];

int main(void)
{
	int number;
	int x, y;
	int p, n;

	puts("Enter the target number, bit position, bit field, and comparison number.\n"
             "q to quit\n");
	while (scanf("%d %d %d %d", &x, &p, &n, &y) == 4)
	{
		number = setbits(x,p,n,y);

		printf("\n%d with %d bits that begin at position %d set to\n"
		       "the rightmost %d bits of %d is %d\n\n", x, n, p, n, y, number);

		itobs(x, bin_str);
		printf("%5d: ", x);
		show_bstr(bin_str);
		putchar('\n');

		itobs(y, bin_str);
		printf("%5d: ", y);
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

int getbits(int x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

int setbits(int x, int p, int n, int y)
{
	int mask = ~(~0 << n);

	y &= mask;
	y <<= p+1-n;
	mask <<= p+1-n;

	return y | (x & ~mask);
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

