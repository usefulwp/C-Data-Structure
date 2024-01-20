#ifndef CIRCLELIST_H_
#define CIRCLELIST_H_
#include <stdlib.h>
#include<stdbool.h>
typedef struct Node {
	void* data;
	struct Node* next;
}Node;
typedef struct {
	Node* head;
	Node* tail;
	int length;
}CircleList;

CircleList* createCircleList();
Node* createCircleNode(void* data);
bool insertAtBegin(CircleList* list, void* data);
bool insertAtIndex(CircleList* list, void* data, int index);
bool insertAtEnd(CircleList* list, void* data);
bool deleteAtBegin(CircleList* list);
bool deleteAtIndex(CircleList* list, int index);
bool deleteAtEnd(CircleList* list);
Node* getNodeByIndex(CircleList* list, int index);
void foreachCircleList(CircleList* list, void(*printFunc)(void*));
#endif // CIRCLELIST_H_

