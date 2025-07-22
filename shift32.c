#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t num = 0x8000FFFF;  // ʾ����32λ���������滻Ϊ����ֵ
    int32_t low_16_bits = (int16_t)(num & 0xFFFF);  // ȡ����16λ��ת��Ϊ����������
    int32_t high_16_bits = (int16_t)(num >> 16);  // ȡ����16λ��ת��Ϊ����������

    printf("low: %d\n", low_16_bits);
    printf("high: %d\n", high_16_bits);

    return 0;
}
