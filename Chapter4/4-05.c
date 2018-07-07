/* Add access to library functions to library functions like sin, exp, and pow.
 * see <math.h> in Appendix B, Section 4.
 */
#include <stdio.h>
#include <stdlib.h>	// for atof()
#include <math.h>	// add access to sin(), exp(), pow() etc.
#define MAXOP	100	// max size of operand or operator
#define NUMBER 	'0'	// signal that a number was found

int getop(char []);
void push(double);
double pop(void);
double copy_top(void);
void disp_top(void);
void swap_top(void);
void clear_stack(void);

/* reverse Polish calculator */
int main(void)
{
	int type;
	double op1, op2, temp;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+' :
				push(pop() + pop());
				break;
			case '*' : 
				push(pop() * pop());
				break;
			case '-' : 
				op2 = pop();
				push(pop() - op2);
				break;
			case '/' : 
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%' :
				op2 = pop();
				op1 = pop();
				if (op2 >= 0.0 && op1 >= 0.0)
					push((int) op1 % (int) op2);
				else
					printf("error: zero or negative invalid in modulus\n");
				break;
			case 'd' : 
				disp_top();
				break;
			case 'c' : 
				temp = copy_top();
				printf("temp = %.2f\n", temp);
				break;
			case 's' : 
				swap_top();
				disp_top();	
				break;
			case 'e' :
				clear_stack();
				disp_top();
				break;
			case 'm' : 
				op2 = pop();
				op1 = pop();
				printf("sin(%.2lf) = %.2lf\n", op2, sin(op2));
				printf("exp(%.2lf) = %.2lf\n", op2, exp(op2));
				printf("pow(%.2lf, %.2lf) = %.2lf\n", op1, op2, pow(op1, op2));
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
		disp_top();
	}
	swap_top();
	disp_top();

	return 0;
}

#define MAXVAL 100	// maximum depth of val stack

int sp = 0;		// next free stack position
double val[MAXVAL];	// value stack

/* push:	push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop:		pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

double copy_top(void)
{
	return val[sp-1];
}

void disp_top(void)
{
	printf("Top element of stack: %f\n", val[sp-1]);
}

void swap_top(void)
{
	double temp = pop();
	double temp2 = pop();
	push(temp);
	push(temp2);
}

void clear_stack(void)
{
	while (sp >= 0)
		val[sp--] = 0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop:	get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	// not a number
	i = 0;
	if (isdigit(c))		// collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		// collect fraction part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf

int getch(void)		// get a (possibly pushed back) character
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	// push character back on input
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
