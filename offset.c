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
    unsigned int flag : 1;   // 字节0, 位0
    unsigned int mode : 3;    // 字节0, 位1-3
    unsigned int value : 12; // 跨越字节0（位4-7）和字节1（位0-3）
    char padding;            // 对齐到字节2
};

int main() {
    // 计算value的字节偏移和位偏移
    size_t byte_offset = offsetof(struct BitExample, value) / 8; // 0（字节0）
    size_t bit_offset = offsetof(struct BitExample, value) % 8;   // 4（位4开始）

    printf("字节偏移: %zu, 位偏移: %zu\n", byte_offset, bit_offset);
    return 0;
}
