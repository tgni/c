/*
 * File: main.c
 * Description:
 *	Reverse Polish Calculator
 *      The main algorithm is convert an infix notation into a postfix
 *      notation (which is always called reverse Polish notation), then
 *      calculate.
 * History:
 *	Jan 14, 2016	Daniel Ni	Create
 */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include <math.h>

#define MAXOP	100

typedef struct {
	char type;
	double n;
} token;

static token tok[MAXVAL];
static int sp = 0;

void push_token(char type, double n)
{
	if (sp < MAXVAL) {
		tok[sp].type = type;
		tok[sp++].n  = n;
	} else {
		printf("error: token stack full\n");
	}
}

/* a is less than or equal to b */
int islesseq(char a, char b)
{
	if (((a == '+' || a == '-') && (b == '+' || b == '-'))
		|| ((a == '/' || a == '*' || a == '%') && (b == '/' || b == '*' || b == '%')))
		return 1;
	else if ((a == '+' || a == '-') && (b == '/' || b == '*' || b == '%'))
		return 1;
	else if ((a == '/' || a == '*' || a == '%') && (b == '+' || b == '-'))
		return 0;
	else if (b == '(')
		return 0;
	else
		printf("error: invalid args: a:%c b:%c\n", a, b);

	return ~0;
}

void calc()
{
	char type;
	double op2, op1;
	int i;

	printf(">>");
	for (i = 0; i < sp; ++i) {
		if (tok[i].type == NUMBER) {
			printf("%g", tok[i].n);	
		} else {
			printf("%c", tok[i].type);
		}
		switch (tok[i].type) {
		case NUMBER:
			push_num(tok[i].n);
			break;
		case '+':
			push_num(pop_num() + pop_num());
			break;
		case '-':
			op2 = pop_num();
			push_num(pop_num() - op2);
			break;
		case '*':
			push_num(pop_num() * pop_num());
			break;
		case '/':
			op2 = pop_num();
			if (op2 != 0.0)
				push_num(pop_num() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop_num();
			if (op2 != 0.0)
				push_num(fmod(pop_num(), op2));
			else
				printf("error: zero divisor\n");
			break;
		default:
			printf("unknown type: %c\n", type);
			break;
		}
	}
	printf("\n\t%.8g\n", pop_num());
	sp = 0;
}

main()
{
	int type;
	double op2;
	char c;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push_token(NUMBER, atof(s));
			break;
		case '+': case '-': case '/': case '*': case '%':
			while (((c = top_char()) != EOF) && islesseq(type, c))
				push_token(pop_char(),  -1);
			push_char(type);
			break;
		case '(':
			push_char(type);
			break;
		case ')':
			while (((c = pop_char()) != EOF) && c != '(')
				push_token(c, -1); 
			break;
		case '\n':
			while ((c = pop_char()) != EOF)
				push_token(c, -1);
			calc();
			break;
		case 'q':
			return;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
}
