#ifndef SINGLELIST_H_
#define SINGLELIST_H_ 

#include <stdlib.h>
#include<stdbool.h>
typedef struct Node {
	void* data;
	struct Node* next;
} Node;
typedef struct {
	Node* head;
	int length;
}SingleList;
SingleList* createSingleList();
bool insertAtBeginning(SingleList* list, void* data);
bool insertIndex(SingleList* list, void* data, int index);
bool deleteAtEnding(SingleList* list); 
bool deleteIndex(SingleList* list, int index);
int getLength(SingleList* list);
void freeSingleList(SingleList* list);
void foreach(SingleList* list, void (*printFunc)(void*));
#endif // !SINGLELIST_H_

