/* File: float.c */
#include <stdio.h>
int main(void)
{
        float percent;

        percent = (float) ((100 - 10) / 100);
        //percent = 0.1;
        printf("%f\n", percent);

        return 0;
}
