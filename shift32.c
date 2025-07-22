#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t num = 0x8000FFFF;  // 示例的32位整数，可替换为任意值
    int32_t low_16_bits = (int16_t)(num & 0xFFFF);  // 取出低16位并转换为带符号整数
    int32_t high_16_bits = (int16_t)(num >> 16);  // 取出高16位并转换为带符号整数

    printf("low: %d\n", low_16_bits);
    printf("high: %d\n", high_16_bits);

    return 0;
}
