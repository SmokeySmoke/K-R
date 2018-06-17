/* Rewrite the function lower, which converts uppercase letters to lower case,
 * with a conditional statement instead of if-else.
 */
#include <stdio.h>
int lower(char c);

int main (void)
{
	char ch;

	printf("Enter letters (EOF to quit): ");
	while ((ch = getchar()) != EOF)
	{
		printf("%c -> %c\n", ch, lower(ch));
		while (getchar() != '\n')
			continue;
	}
	puts("Bye!");

	return 0;
}

int lower(char c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
