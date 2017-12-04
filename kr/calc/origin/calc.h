#ifndef __CALC_H__
#define __CALC_H__

#define NUMBER	'0'
#define MAXVAL	(100)

extern int getch(void);
extern void ungetch(int c);

extern void push_num(double c);
extern double pop_num(void);
extern double top_num(void);

extern void push_char(int c);
extern int pop_char(void);
extern int top_char(void);

#endif /* __CALC_H__ */
