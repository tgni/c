#include <stdio.h>
#include <string.h>
#include "types.h"

#define PBSZ_72		  0
#define PBSZ_136          1
#define PBSZ_264	  2
#define PBSZ_520          3
#define NR_PB_SIZE        4

enum {
	DT_BEACON	= 0,
	DT_SOF		= 1,
	DT_SACK		= 2,
	DT_COORD	= 3,
	DT_SOUND	= 4,
	DT_SILENT	= 7,
	NR_DT		= 8
};

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

phy_t PHY;

void phy_statis_show(void)
{

	printf("\n");

	printf( "rx beacon:                    %-8u tx beacon:                     %-8u\n", 
			   PHY.statis.rx_frame[DT_BEACON],	PHY.statis.tx_frame[DT_BEACON]);
	printf( "rx sof:                       %-8u tx sof:                        %-8u\n", 
			   PHY.statis.rx_frame[DT_SOF],	        PHY.statis.tx_frame[DT_SOF]);
	printf( "rx sack:                      %-8u tx sack:                       %-8u\n", 
			   PHY.statis.rx_frame[DT_SACK],	PHY.statis.tx_frame[DT_SACK]);
	printf( "rx sound:                     %-8u tx sound:                      %-8u\n", 
			   PHY.statis.rx_frame[DT_SOUND],	PHY.statis.tx_frame[DT_SOUND]);
	printf( "rx pb72:                      %-8u tx pb72:                       %-8u\n", 
			   PHY.statis.rx_pb[PBSZ_72],	        PHY.statis.tx_pb[PBSZ_72]);
	printf( "rx pb136:                     %-8u tx pb136:                      %-8u\n", 
			   PHY.statis.rx_pb[PBSZ_136],	        PHY.statis.tx_pb[PBSZ_136]);
	printf( "rx pb264:                     %-8u tx pb264:                      %-8u\n", 
			   PHY.statis.rx_pb[PBSZ_264],	        PHY.statis.tx_pb[PBSZ_264]);
	printf( "rx pb520:                     %-8u tx pb520:                      %-8u\n", 
			   PHY.statis.rx_pb[PBSZ_520],		PHY.statis.tx_pb[PBSZ_520]);
	printf( "rx pb72 crc err:              %-8u rx pb264 crc err:              %-8u\n", 
			   PHY.statis.rx_pb_err[PBSZ_72],	PHY.statis.rx_pb_err[PBSZ_264]);
	printf( "rx pb136 crc err:             %-8u rx pb520 crc err:              %-8u\n", 
			   PHY.statis.rx_pb_err[PBSZ_136],	PHY.statis.rx_pb_err[PBSZ_520]);
	printf( "rx dma err:                   %-8u tx dma err:                    %-8u\n", 
			   PHY.statis.rx_dma_err,		PHY.statis.tx_dma_err);
	printf( "rx ival para:                 %-8u tx ival para:                  %-8u\n", 
			   PHY.statis.rx_ival_para,		PHY.statis.tx_ival_para);
	printf( "rx hold:                      %-8u tx hold:                       %-8u\n", 
			   PHY.statis.rx_hold,			PHY.statis.tx_hold);
	printf( "rx hdr err:                   %-8u tx late:                       %-8u\n", 
			   PHY.statis.rx_hdr_err,		PHY.statis.tx_late);
	printf( "rx hdr fail:                  %-8u tx frame fail:                 %-8u\n", 
			   PHY.statis.rx_hdr_fail,		PHY.statis.tx_frame_fail);
	printf( "rx ival state:                %-8u sche ctd ival para:            %-8u\n", 
			   PHY.statis.rx_ival_state,		PHY.statis.sche_ctd_ival_para);
	printf( "rx payload fail:              %-8u sche ctd suspend:              %-8u\n", 
			   PHY.statis.rx_payload_fail,		PHY.statis.sche_ctd_suspend);
	printf( "rx end too late:              %-8u sche ctd tx immd:              %-8u\n", 
			   PHY.statis.rx_end_too_late,		PHY.statis.sche_ctd_tx_immd);
	printf( "rx socs late:                 %-8u sche ctd tx late:              %-8u\n", 
			   PHY.statis.socs_late,		PHY.statis.sche_ctd_tx_late);
	printf( "set tx time late:             %-8u set rx time late:              %-8u\n",
			   PHY.statis.set_tx_time_late,		PHY.statis.set_rx_time_late);
	printf( "set rx tmot late:             %-8u sche ctd rx late:              %-8u\n", 
			   PHY.statis.set_rx_tmot_late,		PHY.statis.sche_ctd_rx_late);
	printf( "set rx payload err:           %-8u set ctd tmot late:             %-8u\n", 
			   PHY.statis.set_rx_pl_err,		PHY.statis.set_ctd_tmot_late);
	printf( "pb bufpo empty:               %-8u vm alloc fail:                 %-8u\n", 
			   PHY.statis.pb_bufpo_empty,		PHY.statis.vm_alloc_fail);
	printf( "rx end timeout:               %-8u pd smp mw full:                %-8u\n", 
			   PHY.statis.rx_end_tmot,		PHY.statis.pd_smp_mw_full);
	printf( "hdr smp mw full:              %-8u pl smp mw full:                %-8u\n", 
			   PHY.statis.hdr_smp_mw_full,		PHY.statis.pl_smp_mw_full);
	printf( "wait rx end tmot:             %-8u wait tx end tmot:              %-8u\n", 
			   PHY.statis.wait_rx_end_tmot,	        PHY.statis.wait_tx_end_tmot);
	printf( "sample mem reading:           %-8u intl map dma err:              %-8u\n", 
			   PHY.statis.sample_mem_reading,	PHY.statis.map_dma_err);
	printf( "time pd cont:                 %-8u time hdr cont:                 %-8u\n", 
			   PHY.statis.time_pd_cont,             PHY.statis.time_hdr_cont);
	printf( "rx pld too large:             %-8u\n", 
			   PHY.statis.rx_pld_too_large);

	printf( "\n");
}


void main(void)
{
	memset(&PHY, 0, sizeof(PHY));
	printf("sizeof(phy_t): %d\n", sizeof(phy_t));
	phy_statis_show();

	return;
}
