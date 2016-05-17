#include <stdio.h>
#include <stdlib.h>

struct Element {
	int value;
	struct Element *next;
};

typedef struct {
	struct Element *head;
} LinkedList;

LinkedList *LinkedListCreate() {
	LinkedList *a =  malloc(sizeof(LinkedList));
	a->head = NULL;
	return a;
}

void LinkedListAdd(LinkedList *a, int item) {
	struct Element *it = malloc(sizeof(struct Element));
	it->value = item;
	it->next = NULL;
	if(a->head == NULL) {
		a->head = it;
	} else {
		struct Element *b = a->head;
		while(b->next != NULL) {
			b = b->next;
		}
		b->next = it;
	}
}

int LinkedListGet(LinkedList *a, int index) {
	struct Element *b = a->head;
	for(int i = 0; i < index; i++) {
		b = b->next;
	}
	return b->value;
}

void LinkedListNodeDestroy(struct Element *b) {
	if(b->next != NULL) {
		LinkedListNodeDestroy(b->next);
	}
	free(b);
}

void LinkedListDestroy(LinkedList *a) {
	LinkedListNodeDestroy(a->head);	
	free(a);
}

int main() {
	LinkedList *a = LinkedListCreate();
	LinkedListAdd(a, 5);
	LinkedListAdd(a, 9);
	printf("%i\n", LinkedListGet(a, 0));
	printf("%i\n", LinkedListGet(a, 1));
	LinkedListDestroy(a);
	return 0;
}
