/*
 * Copyright: (c) 2016-2020, 2016 Triductor Technology, Inc.
 * All Rights Reserved.
 *
 * File:        sorting_list.c
 * Purpose: 	This file is for implementing insertion sort and bubble sort of
 *		double list. Both of two methods of sorting cost time O(n^2).
 *		Pay attention to every line of code, you can taste different art
 *		of list operation. ;)
 * History:	Sep 9, 2016	Tgni	Create
 */

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "list.h"

typedef struct {
	list_head_t list;
	int32_t     number;
} number_t;

list_head_t number_list;

/* O(n) */ 
int32_t sorting_insert(number_t *new, list_head_t *list)
{
	list_head_t *pos;
	number_t *ent;

	list_for_each(pos, list) {
		ent = list_entry(pos, number_t, list);
		if (new->number <= ent->number)
			break;
	}
	list_add_tail(&new->list, pos);

	return;
}

/* O(n^2) */
void insertion_sort(list_head_t *list)
{
	number_t *ent;
	list_head_t head, *pos, *n;

	INIT_LIST_HEAD(&head);

	list_for_each_safe(pos, n, list) {
		ent = list_entry(pos, number_t, list);
		list_del(pos);
		sorting_insert(ent, &head);
	}

	INIT_LIST_HEAD(list);
	list_splice(&head, list);

	return;
}

void swap(list_head_t *a, list_head_t *b)
{
	list_head_t *prev = a->prev;

	list_del(a);
	list_add(a, b);
	list_del(b);
	list_add(b, a->prev);
}

/* O(n^2) */
void bubble_sort(list_head_t *list)
{
	number_t *a, *b;
	list_head_t *pos, *pos2, *n;

	list_for_each_safe(pos, n, list) {
		pos2 = pos->next;
		while (pos2 != list) {
			a = list_entry(pos2->prev, number_t, list);				
			b = list_entry(pos2, number_t, list);
			if (a->number > b->number)
				swap(pos2->prev, pos2);
			else
				pos2 = pos2->next;
		}
	}

	return;
}


void print_list(list_head_t *list)
{
	list_head_t *pos;
	number_t *n;

	list_for_each(pos, list) {
		n = list_entry(pos, number_t, list);
		printf("%d ", n->number);
	}
	printf("\n");
}

int main()
{
	int32_t i;
	number_t *ent;
	list_head_t *pos, *n;

	srand(time(NULL));

	INIT_LIST_HEAD(&number_list);

	for (i = 0; i < 100; ++i) {
		if (!(ent = (number_t *)malloc(sizeof(number_t)))) {
			printf("malloc fail\n");
			return -1;
		}
		ent->number = rand() % 100; 
		//list_add_tail(&ent->list, &number_list);
		sorting_insert(ent, &number_list);
	}

	print_list(&number_list);
	ent = list_entry(number_list.next, number_t, list);
	printf("delete : %d\n", ent->number);
	list_del(&ent->list);
	printf("insert : %d\n", ent->number);
	sorting_insert(ent, &number_list);
	printf("after insert\n");
	print_list(&number_list);

	//insertion_sort(&number_list);
	//bubble_sort(&number_list);

	list_for_each_safe(pos, n, &number_list) {
		ent = list_entry(pos, number_t, list);
		list_del(pos);
		free(ent);
	}

	return 0;
}
