// SPDX-License-Identifier: MIT
/*
 * Copyright © 2020 Intel Corporation
 */

#ifndef BPM_DMA_RESV_PRUNE_NOT_PRESENT
#include <linux/dma-resv.h>

#include "dma_resv_utils.h"

void dma_resv_prune(struct dma_resv *resv)
{
	if (dma_resv_trylock(resv)) {
		if (dma_resv_test_signaled(resv, true))
			dma_resv_add_excl_fence(resv, NULL);
		dma_resv_unlock(resv);
	}
}
#endif
