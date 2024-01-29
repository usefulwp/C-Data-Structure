#include"Queue.h"

int main() {
	Queue* queue=creatQueue();
	for (int i = 0; i < 10; i++) {
		push_back(queue, i);
	}
	push_front(queue, 999);
	pop_back(queue);
	pop_front(queue);
	printQueue(queue);
	return 0;
}