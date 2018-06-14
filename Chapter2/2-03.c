/* Write a function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into
 * its equivalent integer value. The allowable digits are 0 
 * through 9, a through f, and A through F
 */
#include <stdio.h>
#include <ctype.h>

#define SLEN 10

#define HEX_A 10
#define HEX_B 11
#define HEX_C 12
#define HEX_D 13
#define HEX_E 14
#define HEX_F 15
int htoi(char s[]);

int main(void)
{
	char hex[SLEN];
	int n;

	printf("Enter a hexadecimal number (EOF to quit):\n");
	while (scanf("%s", hex) == 1)
	{
		n = htoi(hex);
		if (n > 0)
			printf("\n%s = %d\n\n", hex, n);
		printf("Enter another hexadecimal number(EOF to quit):\n");
	}
	printf("Done!\n");

	return 0;
}

int htoi(char s[])
{
	int n, i, val;
	
	for (n = i = 0; s[i] != '\0'; i++)
	{	
		if (isdigit(s[i]))
			val = s[i] - '0';
		else
		{
			s[i] = toupper(s[i]);
			if (s[i] == 'A')
				val = HEX_A;
			else if (s[i] == 'B')
				val = HEX_B;
			else if (s[i] == 'C')
				val = HEX_C;
			else if (s[i] == 'D')
				val = HEX_D;
			else if (s[i] == 'E')
				val = HEX_E;
			else if (s[i] == 'F')
				val = HEX_F;
			else if (s[i] == 'X')
			{
				s[i] = 'x';
				n = val = 0;
			}
			else
			{
				printf("Not a Hexadecimal number!\n");
				return -1;
			}
		}
		n = 16 * n + val;
	}
	return n;
}
