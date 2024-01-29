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

_declspec(dllexport)  CircleList* createCircleList();
_declspec(dllexport) Node* createCircleNode(void* data);
_declspec(dllexport) bool insertAtBegin(CircleList* list, void* data);
_declspec(dllexport) bool insertAtIndex(CircleList* list, void* data, int index);
_declspec(dllexport) bool insertAtEnd(CircleList* list, void* data);
_declspec(dllexport) bool deleteAtBegin(CircleList* list);
_declspec(dllexport) bool deleteAtIndex(CircleList* list, int index);
_declspec(dllexport) bool deleteAtEnd(CircleList* list);
_declspec(dllexport) Node* getNodeByIndex(CircleList* list, int index);
_declspec(dllexport) void foreachCircleList(CircleList* list, void(*printFunc)(void*));
#endif // CIRCLELIST_H_

