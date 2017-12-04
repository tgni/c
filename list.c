#include "types.h"
#include "list.h"

typedef struct node_s {
	list_head_t link;
	int32_t id;
} node_t;


int32_t main(void)
{
	node_t nd;

	INIT_LIST_HEAD(&nd.link);
	if (!list_empty(&nd.link))
		list_del(&nd.link);

	return 0;
}
