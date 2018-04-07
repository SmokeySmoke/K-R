// Verify that the expression getchar() != EOF is 0 or 1
#include <stdio.h>

int main(void)
{
	char ch;

	printf("Enter a character or EOF to test value of getchar() != EOF: ");
	ch = getchar();
	printf("\ngetchar() != EOF == %d\n", ch != EOF);

	return 0;
}
