#ifndef _LIST_H
#define _LIST_H


#include <stdio.h>


/**
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

struct list_head {
	struct list_head *next, *prev;
};

typedef struct list_head list_head_t;

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

#define INIT_LIST_HEAD(ptr) do { \
	(ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)


/**
 * Insert a new entry between two known consecutive entries. 
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
#if 1
static __inline__ void __list_add(struct list_head * _new,
	struct list_head * _prev,
	struct list_head * _next)
{
	_next->prev = _new;
	_new->next = _next;
	_new->prev = _prev;
	_prev->next = _new;
}
#else
#define __list_add(_new, _prev, _next) do { \
	struct list_head *__new = _new; \
	struct list_head *__prev = _prev; \
	struct list_head *__next = _next; \
\
	(__next)->prev = (__new); \
	(__new)->next = (__next); \
	(__new)->prev = (__prev); \
	(__prev)->next = (__new); \
} while (0)
#endif


/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
#if 1
static __inline__ void list_add(struct list_head *_new, struct list_head *_head)
{
	__list_add(_new, _head, _head->next);
}
#else
#define list_add(_new, _head) do { \
	__list_add(_new, _head, (_head)->next); \
} while (0)
#endif


/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
#if 1
static __inline__ void list_add_tail(struct list_head *_new, struct list_head *_head)
{
	__list_add(_new, _head->prev, _head);
}
#else
#define list_add_tail(_new, _head) do { \
	__list_add(_new, (_head)->prev, _head); \
} while (0)
#endif


/**
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
#if 1
static __inline__ void __list_del(struct list_head * _prev,
				  struct list_head * _next)
{
	_next->prev = _prev;
	_prev->next = _next;
}
#else
#define __list_del(_prev, _next) do { \
	struct list_head *__prev = _prev; \
	struct list_head *__next = _next; \
\
	(__next)->prev = (__prev); \
	(__prev)->next = (__next); \
} while (0)
#endif


/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty on entry does not return true after this, the entry is in an undefined state.
 */
#if 1
static __inline__ void list_del(struct list_head *_entry)
{
	__list_del(_entry->prev, _entry->next);
	_entry->next = _entry->prev = 0;
}
#else
#define list_del(_entry) do { \
	__list_del((_entry)->prev, (_entry)->next); \
	(_entry)->next = (_entry)->prev = 0; \
} while (0)
#endif


/**
 * list_del_init - deletes entry from list and reinitialize it.
 * @entry: the element to delete from the list.
 */
#if 1
static __inline__ void list_del_init(struct list_head *_entry)
{
	__list_del(_entry->prev, _entry->next);
	INIT_LIST_HEAD(_entry);
}
#else
#define list_del_init(_entry) do { \
	__list_del((_entry)->prev, (_entry)->next); \
	INIT_LIST_HEAD(_entry); \
} while (0)
#endif


/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
#if 1
static __inline__ int list_empty(struct list_head *_head)
{
	return _head->next == _head;
}
#else
#define list_empty(_head) \
	( (_head)->next == (_head) )
#endif


static __inline__ int list_empty_one(struct list_head *_head)
{
	return _head->next == _head->prev && _head->next != _head && 
		_head->next->next == _head && _head->next->prev == _head;
}


/**
 * list_splice - join two lists
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 */
static __inline__ void list_splice(struct list_head *list, struct list_head *head)
{
	struct list_head *first = list->next;

	if (first != list) {
		struct list_head *last = list->prev;
		struct list_head *at = head->next;

		first->prev = head;
		head->next = first;

		last->next = at;
		at->prev = last;
	}
}

#define offset_of(TYPE, MEMBER) ((unsigned long) &((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) \
        ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
        container_of(ptr, type, member)


/**
 * list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop counter.
 * @head:	the head for your list.
 */
#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); \
        	pos = pos->next)

#define list_for_each_reverse(pos, head) \
	for (pos = (head)->prev; pos != (head); \
		pos = pos->prev)

        	
/**
 * list_for_each_safe	-	iterate over a list safe against removal of list entry
 * @pos:	the &struct list_head to use as a loop counter.
 * @n:		another &struct list_head to use as temporary storage
 * @head:	the head for your list.
 */
#define list_for_each_safe(pos, n, head) \
	for (pos = (head)->next, n = pos->next; pos != (head); \
		pos = n, n = pos->next)

#define list_for_each_safe_reverse(pos, n, head) \
	for (pos = (head)->prev, n = pos->prev; pos != (head); \
		pos = n, n = pos->prev)


/*
 * Double linked lists with a single pointer list head.
 * Mostly useful for hash tables where the two pointer list head is
 * too wasteful.
 * You lose the ability to access the tail in O(1).
 */

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

#define HLIST_HEAD_INIT { .first = NULL }
#define HLIST_HEAD(name) struct hlist_head name = {  .first = NULL }
#define INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)
static inline void INIT_HLIST_NODE(struct hlist_node *h)
{
	h->next = NULL;
	h->pprev = NULL;
}

static inline int hlist_unhashed(const struct hlist_node *h)
{
	return !h->pprev;
}

static inline int hlist_empty(const struct hlist_head *h)
{
	return !h->first;
}

static inline void __hlist_del(struct hlist_node *n)
{
	struct hlist_node *next = n->next;
	struct hlist_node **pprev = n->pprev;
	*pprev = next;
	if (next)
		next->pprev = pprev;
}

static inline void hlist_del(struct hlist_node *n)
{
	__hlist_del(n);
        n->next  = 0;
        n->pprev = 0;
}

static inline void hlist_del_init(struct hlist_node *n)
{
	if (!hlist_unhashed(n)) {
		__hlist_del(n);
		INIT_HLIST_NODE(n);
	}
}

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h)
{
	struct hlist_node *first = h->first;
	n->next = first;
	if (first)
		first->pprev = &n->next;
	h->first = n;
	n->pprev = &h->first;
}

/* next must be != NULL */
static inline void hlist_add_before(struct hlist_node *n,
					struct hlist_node *next)
{
	n->pprev = next->pprev;
	n->next = next;
	next->pprev = &n->next;
	*(n->pprev) = n;
}

static inline void hlist_add_after(struct hlist_node *n,
					struct hlist_node *next)
{
	next->next = n->next;
	n->next = next;
	next->pprev = &n->next;

	if(next->next)
		next->next->pprev  = &next->next;
}

/*
 * Move a list from one list head to another. Fixup the pprev
 * reference of the first entry if it exists.
 */
static inline void hlist_move_list(struct hlist_head *old,
				   struct hlist_head *new)
{
	new->first = old->first;
	if (new->first)
		new->first->pprev = &new->first;
	old->first = NULL;
}

#define hlist_entry(ptr, type, member) \
        container_of(ptr, type, member)

#define hlist_for_each(pos, head) \
	for (pos = (head)->first; pos ; pos = pos->next)

#define hlist_for_each_safe(pos, n, head) \
	for (pos = (head)->first; pos && ({ n = pos->next; 1; }); \
	     pos = n)

#endif	/* end of _LIST_H */
