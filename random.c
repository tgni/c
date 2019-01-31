/* File: random.c */
#include <stdlib.h>
#include <stdio.h>

static unsigned long next = 1;

/*RAND_MAX assumed to be 32767*/
int myrand(void)
{
        next = next * 1103515245 + 12345;
        return ((unsigned)(next/65536) % 32768);
}

void mysrand(unsigned seed)
{
        next = seed;
}

int main(void)
{
        int tmp,i;
        float tmpp;

        srand(time(NULL));
        for (i = 0; i < 100; i++) {
                if ((i % 10) == 0)
                        printf("\n");
                tmp = 1 + (int) (10 * (rand() / (RAND_MAX + 1.0)));
                printf("%d ", tmp);
        }

        return 0;
}
