#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100
typedef struct
{
	int heap[MAX_ELEMENT];
	int heap_size;
} heaptype;

heaptype* createHeap()
{
	heaptype *h = (heaptype *)malloc(sizeof(heaptype));
	h->heap_size = 0;
	return h;
}

void insertHeap(heaptype *h, int item)
{
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item > h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int deleteHeap(heaptype *h) 
{
	int prnt, chld;
	int item, temp;
	prnt = 1;
	chld = 2;
	item = h->heap[1];	
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	prnt = chld;
	chld = chld * 2;

	while (chld <= h->heap_size)
	{
		if ((chld < h->heap[chld]) && (h->heap[chld] < h->heap[chld + 1]))
		{
			chld++;
		}
		if (temp >= h->heap[chld])
		{
			break;
		}
		else
		{
			h->heap[prnt] = h->heap[temp];
			prnt = chld;
			chld = chld * 2;
		}
	}
	h->heap[prnt] = temp;
	return item;
}

print(heaptype * h)
{
	for (int i = 1; i <= h->heap_size; i++)
	{
		printf("%d ", h->heap[i]);
	}
}

int main()
{
	int size, item;
	heaptype *heap = createHeap();
	insertHeap(heap, 20);
	insertHeap(heap, 10);
	insertHeap(heap, 30);
	insertHeap(heap, 50);
	insertHeap(heap, 40);
	insertHeap(heap, 30);
	insertHeap(heap, 30);


	print(heap);
	size = heap->heap_size;
	for (int i = 1; i <= size; i++)
	{
		item = deleteHeap(heap);
		
	}
	getchar();
}