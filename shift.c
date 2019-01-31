#include <stdio.h>
#include "types.h"

int32_t get_size_a(uint16_t wp, uint16_t rp)
{
	return (wp - rp) & 0x1fff;
}

int32_t get_size_b(uint16_t wp, uint16_t rp)
{
	int16_t _wp, _rp;
	int32_t size;

	_wp = (int16_t)wp;
	_rp = (int16_t)rp;
	size = _wp - _rp;
	size = (size >= 0) ? size : 8192 + size;

	return size;
}

int main(void)
{
	uint16_t rp, wp;
	int32_t i, sza, szb;

	for (rp = 0; rp < 8192; ++rp) {
		for (wp = 0; wp < 8192; ++wp) {
			sza = get_size_a(wp, rp);
			szb = get_size_b(wp ,rp);
			if (sza != szb)
				printf("sza: %d, szb: %d, wp: %d rp: %d\n", sza, szb, wp, rp);
		}
	}

	return 0;

}
