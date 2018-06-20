/* Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */
#include <stdio.h>
#include <string.h>
#define SLEN 128
void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);

int main(void)
{
	char s[SLEN], t[SLEN], ch;
	unsigned ch_count = 0;

	puts("Enter a string less than 128 characters in length: ");
	while ((ch = getchar()) != EOF && ch_count < SLEN-1)
		t[ch_count++] = ch;
	t[ch_count] = '\0';

	puts("\nORIGINAL:");
	puts(t);
	escape(s,t);
	puts("\nAFTER escape():");
	puts(s);

	unescape(s,t);
	puts("\nAFTER unescape():");
	puts(s);
	puts("\nDone!");

	return 0;
}

void escape(char s[], const char t[])
{
	unsigned i, j;
	i = j = 0;

	while (t[i] != '\0' && j < SLEN-1)
	{
		switch (t[i])
		{

			case '\a' : s[j++] = '\\';
				    s[j++] = 'a';	break;
			case '\b' : s[j++] = '\\';
				    s[j++] = 'b';	break;
			case '\f' : s[j++] = '\\';
				    s[j++] = 'f';	break;
			case '\n' : s[j++] = '\\';
				    s[j++] = 'n';	break;
			case '\r' : s[j++] = '\\';
				    s[j++] = 'r';	break;
			case '\t' : s[j++] = '\\';
				    s[j++] = 't';	break;
			case '\v' : s[j++] = '\\';
				    s[j++] = 'v';	break;
			case '\\' : s[j++] = '\\';
				    s[j++] = '\\';	break;
			case '\'' : s[j++] = '\\';
				    s[j++] = '\'';	break;
			case '\"' : s[j++] = '\\';
				    s[j++] = '\"';	break;
			default : s[j++] = t[i];
		}
		++i;
	}
}

void unescape(char s[], const char t[])
{
	unsigned i, j;
	i = j = 0;

	while (t[i] != '\0' && j < SLEN-1)
	{
		if (t[i] == '\\')
			switch (t[++i])
			{
				case 'a' : s[j++] = '\a';	break;
				case 'b' : s[j++] = '\b';	break;
				case 'f' : s[j++] = '\f';	break;
				case 'n' : s[j++] = '\n';	break;
				case 'r' : s[j++] = '\r';	break;
				case 't' : s[j++] = '\t';	break;
				case 'v' : s[j++] = '\v';	break;
				case '\\' : s[j++] = '\\';	break;
				case '\'' : s[j++] = '\'';	break;
				case '\"' : s[j++] = '\"';	break;
				default : s[j++] = t[i-1];
			}
		s[j++] = t[i++];
	}
	s[j] = '\0';
}
