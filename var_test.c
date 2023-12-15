/*
#include <stdio.h> 
void PrintInt(int cnt, ...) 
{ 
	int *temp = &cnt;
	
	temp++;
	for (int i = 0; i < cnt; ++i) { 
		printf("%d\n", *temp); 
		temp++; 
	} 
}

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	int g = 7;
	int h = 8;
	int i = 9;

	PrintInt(18, a, b, c, d, e, f, g, h, i);

	return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
int demo( char msg, ... )
{
	/*定义保存函数参数的结构*/
	va_list argp;
	int argno = 0;
	char *para;
	/*argp指向传入的第一个可选参数，msg是最后一个确定的参数*/
	va_start(argp, msg);
	while (1) {
		para = va_arg(argp, char*);
		if (strcmp(para, "") == 0)
			break;
		printf("Parameter #%d is: %s\n", argno, para);
		argno++;
	}
	va_end(argp);
	/*将argp置为NULL*/
	return 0;
}

void main( void )
{
   demo("DEMO", "This", "is", "a", "demo!", "");
}
