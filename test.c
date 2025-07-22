#include <stdio.h>
#include "types.h"

#define NR_DT 8
#define NR_PB_SIZE 4
typedef struct {
	struct {
		uint32_t tx_frame[NR_DT + 1];
		uint32_t tx_pb[NR_PB_SIZE];
		uint32_t tx_dma_err;
		uint32_t tx_ival_para;
		uint32_t tx_hold;
		uint32_t tx_suspend;
		uint32_t tx_late;
		uint32_t tx_frame_fail;
		uint32_t set_tx_time_late;

		uint32_t rx_frame[NR_DT + 1];
		uint32_t rx_pb[NR_PB_SIZE];
		uint32_t rx_pb_err[NR_PB_SIZE];
		uint32_t rx_dma_err;
		uint32_t rx_ival_para;
		uint32_t rx_hold;
		uint32_t rx_suspend;
		uint32_t rx_hdr_err;
		uint32_t rx_ival_state;
		uint32_t rx_hdr_fail;
		uint32_t rx_payload_fail;
		uint32_t rx_end_too_late;
		uint32_t rx_end_tmot;
		uint32_t socs_late;
		uint32_t set_rx_time_late;
		uint32_t set_rx_tmot_late;
		uint32_t set_rx_pl_err;
		uint32_t rx_pld_too_large;

		uint32_t sche_ctd_ival_para;
		uint32_t sche_ctd_suspend;
		uint32_t sche_ctd_tx_immd;
		uint32_t sche_ctd_tx_late;
		uint32_t sche_ctd_rx_late;
		uint32_t set_ctd_tmot_late;

		uint32_t vm_alloc_fail;
		uint32_t pb_bufpo_empty;
		uint32_t pd_smp_mw_full;
		uint32_t hdr_smp_mw_full;
		uint32_t pl_smp_mw_full;
		uint32_t wait_tx_end_tmot;
		uint32_t wait_rx_end_tmot;
		uint32_t sample_mem_reading;
		uint32_t map_dma_err;

		uint32_t time_pd_cont;
		uint32_t time_hdr_cont;
	} statis;
} phy_t;

void main(void)
{
#if 0
	uint32_t time = 0;
	int32_t diff = -1;
	time = time - diff;
	printf("%d %x\n", time, time);
	float a = 0.5;
	float b = 1.5;
	float c = -12.5;
	float d = -8.25;

	unsigned int *pa = NULL;
	pa = (unsigned int *)&a;
	
	unsigned int *pb = NULL;
	pb = (unsigned int *)&b;

	unsigned int *pc = NULL;
	pc = (unsigned int *)&c;

	unsigned int *pd = NULL;
	pd = (unsigned int *)&d;

	printf("a: %08x b: %08x c: %08x d: %08x\n", *pa, *pb, *pc, *pd);
	printf("sizeof(phy_t): %d\n", sizeof(phy_t));
#endif
	uint32_t x = 1;
	x = x >> 32;
	x = x ^ 1;
	printf("x: %x\n", x);
	printf("xor: %d\n", x);

	return;
}
