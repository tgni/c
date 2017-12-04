#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#include "que.h"
#include "calc.h"

#define MAXOP	100

typedef struct {
	list_head_t head;
	char type;
	double n;
} token;

msgq_t token_que;
stack_t *double_stack;

token *get_tok(char type, double n)
{
	token *t;
	
	t = malloc(sizeof(token));
	if (!t) return NULL;

	t->type = type;
	t->n    = n;
	return t;
}

void put_tok(token *t)
{
	free(t);
}

static inline void push_token(char type, double n)
{
	token *t = get_tok(type, n);
	if (!t) {
		printf("get token fail\n");	
		return;
	}
	msgq_enq(&token_que, t);
}

/**
 * islesseq - if a is less than or equal to b
 * @a:
 * @b:
 */
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

#define push_d(s, n)	do { double tmp = n; push(s, (void *)&tmp); } while (0)
#define pop_d(s)	(top(s) ? *((double *)pop(s)) : 0.0)

double calc()
{
	char type;
	token *tok;
	stack_t *ds = double_stack;
	double op2;
	int i;

	printf(">>");
	while ((tok = (token *)msgq_deq(&token_que))) {
		if (tok->type == NUMBER) {
			printf("%g", tok->n);	
		} else {
			printf("%c", tok->type);
		}
		switch (tok->type) {
		case NUMBER:
			push_d(ds, tok->n);
			break;
		case '+':
			push_d(ds, pop_d(ds) + pop_d(ds));
			break;
		case '-':
			op2 = pop_d(ds);
			push_d(ds, pop_d(ds) - op2);
			break;
		case '*':
			push_d(ds, pop_d(ds) * pop_d(ds));
			break;
		case '/':
			op2 = pop_d(ds);
			if (op2 != 0.0)
				push_d(ds, pop_d(ds) / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop_d(ds);
			if (op2 != 0.0)
				push_d(ds, fmod(pop_d(ds), op2));
			else
				printf("error: zero divisor\n");
			break;
		default:
			printf("unknown type: %c\n", type);
			break;
		}
		put_tok(tok);
	}
	printf("\n\t%.8g\n", (op2 = pop_d(ds)));

	return op2;
}


#define push_c(s, n)	do { char tmp = n; push(s, (void *)&tmp); } while (0)
#define pop_c(s)	(top(s) ? *((char *)pop(s)) : EOF)
#define top_c(s)	(top(s) ? *((char *)top(s)) : EOF)

main()
{
	stack_t *cs;
	int type;
	double opd;
	char c;
	char s[MAXOP];

	cs = create_stack(sizeof(int), MAXVAL);
	if (!cs) {
		printf("create char stack fail\n");
		return -1;
	}
	double_stack = create_stack(sizeof(double), MAXVAL);
	if (!double_stack) {
		printf("create double stack fail\n");	
		return -1;
	}
	msgq_init(&token_que, "token que", 0, MAXVAL, NULL);

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push_token(NUMBER, atof(s));
			break;
		case '+': case '-': case '/': case '*': case '%':
			while (((c = top_c(cs)) != EOF) && islesseq(type, c))
				push_token(pop_c(cs),  -1);
			push_c(cs, type);
			break;
		case '(':
			push_c(cs, type);
			break;
		case ')':
			while (((c = pop_c(cs)) != EOF) && c != '(')
				push_token(c, -1); 
			break;
		case '\n':
			while ((c = pop_c(cs)) != EOF)
				push_token(c, -1);
			//TODO, save result to support continue calculate
			opd = calc();
			break;
		case 'q':
			return;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	dispose_stack(cs);
	dispose_stack(double_stack);

	return 0;
}
