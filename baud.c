/* File: baud.c */
#include "types.h"
#include <stdio.h>
#if 0

                if (L[i] > C)
                        error = (L[i] - C) * 20 / (float)C;
                else
                        error = (C - L[i]) * 20 / (float)C;

                if (error < 1)
                        return L[i];
#endif

/*according clk, calculate best baud */
uint32_t cal_baud(uint32_t uart_clk)
{
        uint32_t divisor, C, L[6] = {115200, 57600, 38400, 19200, 14400, 9600}; //ClientBR, LocalBR
        float div, left, right;
        uint8_t i;
        
        for (i = 0; i < 6; i++) {
                div = uart_clk / L[i] / 16.0;
                divisor = (uint32_t)div;
                if ((div - (float)divisor) >= 0.5)
                        ++divisor;
                if (!divisor)
                        return 0;
                C = uart_clk / divisor / 16.0;
                if (L[i] > C) {
                        left  = ((1/(float)C) - (1/(float)L[i])) * 10.0;
                } else {
                        left = ((1/(float)L[i]) - (1/(float)C)) * 10.0;
                }
                right = (1/2.0) * (1/(float)L[i]);
                printf("baudrate: %d left: %f right:%f\n", L[i], left, right);
#if 0
                if (left < right)
                        return L[i];
#endif
        }

        return 0; 
}

int main(void)
{
        uint32_t uart_clk, ahb_clk;
        uint32_t baudrate;
        uint8_t i, j;
#if 0
        for (i = 1; i < 16; i++) {
                for (j = 0; j < 16; j++) {
                        ahb_clk  = 50000000 / (i + 1);
                        uart_clk = 50000000 / (i + 1) / (j + 1);
                        baudrate = cal_baud(uart_clk);
                        printf("ahbdiv:%d apb2div:%d ahbclk:%fMHz uartclk:%fMHz baudrate:%d\n", i, j, ahb_clk/1000000.0, uart_clk/1000000.0, baudrate);
                }
        }
#endif
        baudrate = cal_baud(25000000);

        return 0;
}
