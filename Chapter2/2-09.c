/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why. Use this observation to write a faster version of bitcount.
 */
#include <stdio.h>
#include <limits.h>
int bitcount(unsigned x);
int mybitcount(unsigned x);
char * itobs(unsigned, char *);
void show_bstr(const char *);

char bin_str[CHAR_BIT * sizeof (unsigned int) + 1];

int main(void)
{
	unsigned n;
	int product;

	puts("Enter the target number (q to quit):");
	while (scanf("%d", &n) == 1)
	{
		printf("%u in binary:\n", n);
		itobs(n, bin_str);
		printf("%u: ", n);
		show_bstr(bin_str);
		putchar('\n');

		product = bitcount(n);
		printf("Book bitcount: %d\n", product);
		putchar('\n');

		product = mybitcount(n);
		printf("My bitcount: %d\n", product);
		putchar('\n');


		puts("\nEnter another number (q to quit):");
	}

	return 0;
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

int mybitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; b++) 
		x &= (x-1);

	return b;
}

char * itobs(unsigned n, char * ps)
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

