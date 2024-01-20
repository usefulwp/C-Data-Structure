#ifndef DOUBLELIST_H_
#define DOUBLELIST_H_ 

#include <stdlib.h>
#include<stdbool.h>
typedef struct Node {
	void* data;
	struct Node* pre;
	struct Node* next;
} Node;
typedef struct {
	Node* head;
	Node* tail;
	int length;
}DoubleList;

DoubleList* createDoubleList();
bool insertAtBeginning(DoubleList* list, void* data);
bool insertAtEnd(DoubleList* list, void* data);
bool insertAtIndex(DoubleList* list, void* data,int index);
bool deleteAtBeginning(DoubleList* list);
bool deleteAtEnd(DoubleList* list);
bool deleteAtIndex(DoubleList* list, int index);
void freeDoubleList(DoubleList* list);
Node* getNodeByIndex(DoubleList* list,int index);
void foreach(DoubleList* list, void(*printFunc)(void* data));
static Node* creatNode(void* data);
#endif