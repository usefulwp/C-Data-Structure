#include "Queue.h"
#include<errno.h>
Queue* creatQueue()
{
	Queue * queue = (Queue*)malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
	return ;
}

bool push_back(Queue* queue,int data)
{
	if (queue == NULL)
		return false;
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next = NULL;
	if (!queue->head) {
		queue->head = queue->tail = newNode;
	}
	else {
		queue->tail->next= newNode;
		queue->tail = newNode;
	}
	queue->size++;
	return true;
}

bool push_front(Queue* queue,int data)
{
	if (queue == NULL)
		return false;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (!queue->head) {
		queue->head = queue->tail = newNode;
	}
	else {
		newNode->next = queue->head;
		queue->head = newNode;
	}
	queue->size++;
	return true;
}

int pop_front(Queue* queue)
{
	if (queue == NULL || queue->size == 0) {
		perror("pop_front Error");
		printf("Error code: %d\n", errno);
	}
	Node* head = queue->head;
	int value = head->data;
	queue->head = head->next;
	queue->size--;
	free(head);
	head = NULL;
	return value;
}

int pop_back(Queue* queue)
{
	if (queue == NULL || queue->size == 0) {
		perror("pop_front Error");
		printf("Error code: %d\n", errno);
	}
	Node* tail = queue->tail;
	int value = tail->data;
	Node* cur = queue->head;
	while (cur->next!=tail) {
		cur=cur->next;
	}
	free(tail);
	tail = NULL;
	queue->tail = cur;
	queue->tail->next = NULL;
	queue->size--;
	return value;
}

void printQueue(Queue* queue)
{
	if (queue == NULL || queue->size == 0)
		return;
	Node* cur = queue->head;
	while (cur) {
		printf("%d\t", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
