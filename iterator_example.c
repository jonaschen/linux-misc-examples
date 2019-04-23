#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct iterator {
	int (*has_next)(void *);
	void (*next)(void *, void *);
};

/* addr offsets */
struct dma_param {
	int src;
	int dst;
};

struct dma_param_iterator {
	struct iterator itr;
	struct dma_param addr;
};

int dma_params_has_next(void *itr)
{
	struct dma_param_iterator *ditr = (struct dma_param_iterator *) itr;
	struct dma_param *addr = &ditr->addr;

	if (addr->src < 0 || addr->dst < 0)
		return 0;

	if (addr->src <= 7 && addr->dst <= 7)
		return 1;

	return 0;
}

void dma_params_next(void *itr, void *obj)
{
	struct dma_param_iterator *ditr = (struct dma_param_iterator *) itr;
	struct dma_param *addr = (struct dma_param *) &ditr->addr;
	struct dma_param *ret = (struct dma_param *) obj;

	ret->src = addr->src;
	ret->dst = addr->dst;

	if (addr->dst == 7) {
		addr->dst = 0;
		addr->src += 1;
	} else {
		addr->dst += 1;
	}

	return;
}

struct dma_param_iterator dma_itr =
{
	.itr = 
	{
		.has_next = dma_params_has_next,
		.next = dma_params_next,
	},
	.addr =
	{
		.src = 0,
		.dst = 0,
	},
};

int main(int argc, char *argv[])
{
	struct dma_param configs;

	while (dma_itr.itr.has_next(&dma_itr)) {
		dma_itr.itr.next(&dma_itr, &configs);
		printf("(src, dst) offset: (%d, %d)\n", configs.src, configs.dst);
	}
	return 0;
}
