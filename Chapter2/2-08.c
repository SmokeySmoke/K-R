/* Write a function rightrot(x, n) that returns the value of integer x rotated to the right by n positions */
#include <stdio.h>
#include <limits.h>		// for CHAR_BIT, # of bits per char
#define HIBIT 0x80000000	// high order bit of unsigned int on my machine
#define LOBIT 0x01		// low order bit

unsigned rightrot(unsigned x, unsigned n);
char * itobs(unsigned, char *);
void show_bstr(const char *);

char bin_str[CHAR_BIT * sizeof (unsigned int) + 1];

int main(void)
{
	unsigned x, n, number;

	puts("Enter the target number, and the number of times to rotate number to right.\n"
             "q to quit\n");
	while (scanf("%d %d", &x, &n) == 2)
	{
		number = rightrot(x,n);

		printf("\n%d rotated %d times to the right is %d\n",
			       	x, n, number);

		itobs(x, bin_str);
		printf("%12d: ", x);
		show_bstr(bin_str);
		putchar('\n');

		itobs(number, bin_str);
		printf("%12d: ", number);
		show_bstr(bin_str);
		putchar('\n');

		puts("\nEnter another set of numbers (q to quit):");
	}
	puts("Bye!");

	return 0;
}

unsigned rightrot(unsigned x, unsigned n)
{
	_Bool shift = 0;
	unsigned temp = x;
	unsigned count = 0;

	while (n-- > 0)
	{
		puts("x:");
		puts(itobs(x, bin_str));

		if (x & LOBIT == LOBIT)
			shift = 1;
		x >>= 1;
		if (shift == 1)
			x |= HIBIT;
		shift = 0;
	}

	return x;
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

