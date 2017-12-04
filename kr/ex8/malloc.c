#include <stdio.h>
#include <unistd.h>

typedef long long Align;

union header {
	struct {
		union header *ptr;	
		unsigned size;
	} s;
	Align x;
};

typedef union header Header;

unsigned TOTAL = 0;
unsigned FREE  = 0;
static Header base;
static Header *freep = NULL;

static Header *morecore(unsigned);
void my_free(void *ap);

void *my_malloc(unsigned nbytes)
{
	Header *p, *prevp;
	unsigned nunits;

	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) {
			if (p->s.size == nunits) {
				prevp->s.ptr = p->s.ptr;
			} else {
				p->s.size -= nunits;	
				p += p->s.size;
				p->s.size = nunits;
			}
			FREE -= p->s.size;
			freep = prevp;
			return (void *)(p + 1);
		}

		if (p == freep)
			if ((p = morecore(nunits)) == NULL)
				return NULL;
	}
}

#define NALLOC	1024

static Header *morecore(unsigned nu)
{
	char *cp;
	Header *up;

	if (nu < NALLOC)
		nu = NALLOC;

	cp = (char *)sbrk(nu * sizeof(Header));
	if (cp == (char *)-1)
		return NULL;

	up = (Header *)cp;
	up->s.size = nu;
	TOTAL += nu;
	my_free((void *)(up + 1));

	return freep;
}


void my_free(void *ap)
{
	Header *bp, *p;

	bp = (Header *)ap - 1;
	FREE += bp->s.size;

	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
			break;
		}

	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;	
		bp->s.ptr = p->s.ptr->s.ptr;
	} else
		bp->s.ptr = p->s.ptr;

	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;	
		p->s.ptr = bp->s.ptr;
	} else
		p->s.ptr = bp;

	freep = p;
}

void dump()
{
	Header *p, *prevp;
	int idx = 0;
#if 0
	printf("\nStart       End         FreeAddr        Total         Free\n");
	printf("----------------------------------------------------------\n");

	printf("%-08x    %-08x    %-08x        %-10d    %-10d\n\n",
		(void *)base.s.ptr,
		(void *)base.s.ptr + base.s.ptr->s.size * sizeof(Header),
		freep->s.ptr,
		TOTAL,
		FREE);
#endif	

	printf("Free Table\n");
	printf("idx        Address        Size\n");
	printf("--------------------------------------------------\n");

	prevp = &base;
	for (p = prevp->s.ptr; p != &base; prevp = p, p = p->s.ptr) {
		printf("%-08d   %-08x       %-10d\n", idx++, p, p->s.size);			
	}
	printf("\n");
}


main()
{
	char *a, *b, *c, *d, *e;

	a = my_malloc(30 * sizeof(Header));
	b = my_malloc(20 * sizeof(Header));
	c = my_malloc(25 * sizeof(Header));
	d = my_malloc(50 * sizeof(Header));
	e = my_malloc(45 * sizeof(Header));

	dump();

	my_free(c);
	my_free(d);
	my_free(a);
	my_free(e);

	dump();
#if 0
	printf("my_free a\n");
	my_free(a);
	dump();
	printf("my_free b\n");
	my_free(b);
	dump();
	printf("my_free c\n");
	my_free(c);
	dump();
	printf("my_free d\n");
	my_free(d);
	dump();
#endif
	return;
}
