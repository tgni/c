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
	/*���屣�溯�������Ľṹ*/
	va_list argp;
	int argno = 0;
	char *para;
	/*argpָ����ĵ�һ����ѡ������msg�����һ��ȷ���Ĳ���*/
	va_start(argp, msg);
	while (1) {
		para = va_arg(argp, char*);
		if (strcmp(para, "") == 0)
			break;
		printf("Parameter #%d is: %s\n", argno, para);
		argno++;
	}
	va_end(argp);
	/*��argp��ΪNULL*/
	return 0;
}

void main( void )
{
   demo("DEMO", "This", "is", "a", "demo!", "");
}
