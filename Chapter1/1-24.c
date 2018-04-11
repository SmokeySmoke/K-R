/* Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets, and braces. Don't forget about quotes, 
 * both single and double, escape sequences, and comments.
 */
#include <stdio.h>
#define IN 1
#define OUT 0

int main(void)
{
	char ch;
	int parLayer, bracketLayer, braceLayer, sqLayer, dqLayer, escLayer, comLayer, error = 0;
	int in_sqLayer, in_dqLayer, in_comLayer;

	parLayer = bracketLayer = braceLayer = sqLayer = dqLayer = escLayer = comLayer = 0;
	in_sqLayer = in_dqLayer = in_comLayer= OUT;

	while ((ch = getchar()) != EOF)
	{
		if (ch == '(')			// parentheses
			++parLayer;
		else if (ch == ')')
			--parLayer;
		else if (ch == '[')		// brackets
			++bracketLayer;
		else if (ch == ']')
			--bracketLayer;
		else if (ch == '{')		// braces
			++braceLayer;
		else if (ch == '}')
			--braceLayer;
		else if (ch == '\'')		// single quotes
		{
			if (in_sqLayer == OUT)
			{
				++sqLayer;
				in_sqLayer = IN;
			} else if (in_sqLayer == IN)
			{
				--sqLayer;
				in_sqLayer = OUT;
			}
		} else if (ch == '"')		// double quotes
		{
			if (in_dqLayer == OUT)
			{
				++dqLayer;
				in_dqLayer = IN;
			} else if (in_dqLayer == IN)
			{
				--dqLayer;
				in_dqLayer = OUT;
			}
		} else if (ch == '\\')	// escape sequences
		{
			if ((ch = getchar()) != 'n' && ch != 't' && ch != '\'' && ch != '"' && ch != '\\')
				escLayer++;
		} else if (ch == '/')		// comments
		{
		       	if ((ch = getchar()) == '*')
				++comLayer;
		} else if (ch == '*')
		{
			if ((ch = getchar()) == '/')
				--comLayer;
		}
	}

	if (parLayer != 0)
	{
		printf("Parentheses syntax errors found!\n");
		++error;
	} 
	if (bracketLayer != 0)
	{
		printf("Bracket syntax errors found!\n");
		++error;
	}
	if (braceLayer != 0)
	{
		printf("Brace syntax errors found!\n");
		++error;
	}
	if (sqLayer != 0)
	{
		printf("Single quote syntax errors found!\n");
		++error;
	}
	if (dqLayer != 0)
	{
		printf("Double quote syntax errors found!\n");
		++error;
	}
	if (escLayer != 0)
	{
		printf("Escape sequence syntax errors found!\n");
		++error;
	}
	if (comLayer != 0)
	{
		printf("Comment syntax errors found!\n");
		++error;
	}

	if (error == 0)
		printf("No errors found!\n");
	else
		printf("%d errors found!\n", error);

	return 0;
}
