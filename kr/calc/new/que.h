/*
 * Copyright: (c) 2006-2007, 2008 Triductor Technology, Inc.
 * All Rights Reserved.
 *
 * File:	que.h
 * Purpose:	Message queue manipulation structures.
 * History:
 *	Jul 15, 2007	jetmotor	create
 */

#ifndef _QUE_H
#define _QUE_H

#include "types.h"
#include "list.h"

/* msgq_t - 1) Message queue that acts as a data pipe between tasks
 *      Scenario 1, data from task to task
 *          2) Messge queue that acts among task(s) and isr(s).
 *      Scenario 1, data from isr(s) to task(s)
 *      Scenario 2, data from task(s) to isr(s) or data sources crossed
 * @nr:
 * @offset:
 * @thd: threshold
 * @head:
 * @del:
 */
typedef struct msgq_s {
	int32_t nr;
	int32_t offset;
	int32_t thd;
	struct list_head head;

	void (*del)(void *obj);
} msgq_t;

#define msgq_first(q)	        (void *)((char *)(q)->head.next - (q)->offset)

extern void msgq_init(msgq_t *q, char *name, int32_t offset, int32_t thd, void (*del)(void *msg));
extern void msgq_fina(msgq_t *q);

/* msgq_enq - Enque a message into q's tail. If q is preempted by another thread, the
 *	calling thread will be blocked until that thread release q.
 * @q:		the queue
 * @obj:	the message
 * @return:	the dropped one if there it is
 */
extern void * msgq_enq(msgq_t *q, void *obj);

/* msgq_deq - Deque a message from q's head. If q is preempted by another thread, the
 *	calling thread will be blocked until that thread release q. And if there is
 *	no message any more, the calling thread will be blocked until some thread enque
 *	a message into q.
 * @q:		the queue
 * @return:	the message
 */
extern void * msgq_deq(msgq_t *q);


static __inline__ int32_t msgq_is_empty(msgq_t *q)
{
	return list_empty(&q->head);
}

static __inline__ void *msgq_next(msgq_t *q, void *obj)
{
	list_head_t *pos;

	pos = (list_head_t *)(obj + q->offset);
	return pos->next != &q->head ? ((void *)pos->next - q->offset) : NULL;
}

static __inline__ void msgq_del(msgq_t *q, void *obj)
{
	list_head_t *pos;

	pos = (list_head_t *)(obj + q->offset);
	list_del_init(pos);
	--q->nr;
	return;
}

#endif	/* end of _QUE_H */
