#if 0
#include <stdio.h>
#include "types.h"
#include "list.h"

typedef struct sack_ctrl_s {
	uint32_t dt		:3;
	uint32_t access		:5;
	uint32_t snid		:24;

	uint32_t result		:4;
	uint32_t state		:4;
	uint32_t stei		:12;
	uint32_t dtei		:12;

	uint32_t pbc		:3;
	uint32_t		:5;
	uint32_t snr		:8;
	uint32_t load		:8;
#if defined(EXT_FUNC_AH_MIN)
	uint32_t rx_clt		:1;
	uint32_t		:7;
#else
	uint32_t		:8;
#endif

	uint8_t	ext_dt		:4;	/* 0 is sack otherwise reserver */
	uint8_t std		:4;

	uint8_t fccs[3];
} __PACKED sack_ctrl_t;

int main()
{
	printf("sizeof(sack_ctrl_t): %d\n", sizeof(sack_ctrl_t));
	printf("offset of dt %d\n", offset_of(sack_ctrl_t, dt));
	printf("offset of access %d\n", offset_of(sack_ctrl_t, access));
	printf("offset of snid %d\n", offset_of(sack_ctrl_t, snid));

	return 0;
}
#endif

#include <stddef.h>
#include <stdio.h>

struct BitExample {
    unsigned int flag : 1;   // �ֽ�0, λ0
    unsigned int mode : 3;    // �ֽ�0, λ1-3
    unsigned int value : 12; // ��Խ�ֽ�0��λ4-7�����ֽ�1��λ0-3��
    char padding;            // ���뵽�ֽ�2
};

int main() {
    // ����value���ֽ�ƫ�ƺ�λƫ��
    size_t byte_offset = offsetof(struct BitExample, value) / 8; // 0���ֽ�0��
    size_t bit_offset = offsetof(struct BitExample, value) % 8;   // 4��λ4��ʼ��

    printf("�ֽ�ƫ��: %zu, λƫ��: %zu\n", byte_offset, bit_offset);
    return 0;
}
