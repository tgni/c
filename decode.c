#include "types.h"
#include  <stdio.h>

typedef struct ds_phr_s {
#define NW_FT_DATA	0
#define NW_FT_ACK	1
#define NR_NW_FT	2
	uint16_t ft			:1;	/* frame type */
#define ST_GW_TO_IOT	0
#define ST_IOT_TO_GW	1
#define ST_GW_TO_GW	2
	uint16_t st			:2;	/* send type */
	uint16_t rs			:1;	/* rs code */
#define DSSS_RESV	0
#define DSSS_1_2	1	/* psdu sf = phr sf / 2 */
#define DSSS_1_4	2	/* psdu sf = phr sf / 4 */
#define DSSS_1_8	3	/* psdu sf = phr sf / 8 */
	uint16_t dsss			:2;	/* dsss mode */
	uint16_t fl			:9;	/* frame length */
	uint16_t ack			:1;
	union {
		struct {
			uint32_t snid	:4;
			uint32_t stei	:12;
			uint32_t dtei	:12;
			uint32_t	:4;
		};
		uint32_t addr;			/* iot device address */
	};
	uint16_t crc;
} __PACKED ds_phr_t;
typedef struct ds_phr_s lrf_phr_t;


int main()
{
	uint32_t frame[] = {0xe2b63029, 0xc28b82b3};
	uint8_t phr[8];

	split_write_four((uint8_t *)phr, frame[0], 0);
	split_write_four((uint8_t *)(phr+4), frame[1], 0);

	ds_phr_t *ds = (ds_phr_t *)phr;

	printf("ft %d st %d rs %d dsss %d fl %d ack %d\n", ds->ft, ds->st, ds->rs, ds->dsss, ds->fl, ds->ack);

	return 0;
}
