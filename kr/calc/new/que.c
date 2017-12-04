#include "que.h"

void msgq_init(msgq_t *q, char *name, int32_t offset, int32_t thd, void (*del)(void *msg))
{
	q->nr	  = 0;
	q->offset = offset;
	q->thd    = thd;
	q->del	  = del;

	INIT_LIST_HEAD(&q->head);

	return;
}

void msgq_fina(msgq_t *q)
{
	return;
}


void * msgq_enq(msgq_t *q, void *obj)
{
	void *drop = NULL;
        list_head_t *pos;

	if (q->thd && q->nr >= q->thd) {
		drop = msgq_first(q);
		list_del(q->head.next);
	} else {
		++q->nr;
	}

	pos = (list_head_t *)(obj + q->offset);
	list_add_tail(pos, &q->head);

	return drop;
}


void * msgq_deq(msgq_t *q)
{
	void *obj;

	if (list_empty(&q->head))
		return NULL;

	obj = msgq_first(q);
	list_del(q->head.next);
	--q->nr;

	return obj;
}
