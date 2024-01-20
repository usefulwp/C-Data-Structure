#include "SingleList.h"
#include<stdio.h>
SingleList* createSingleList() 
{
	SingleList* list = (SingleList*)malloc(sizeof(SingleList));
	if (list == NULL) 
		exit(EXIT_FAILURE);
	list->head = NULL;
	list->length = 0;
	return list;
}
bool insertAtBeginning(SingleList* list, void* data) 
{
	if (list == NULL)
		return false;
	Node* n = (Node*)malloc(sizeof(Node));
	if (n == NULL)
		return false;
	n->data = data;
	n->next = list->head;
	list->head = n;
	list->length++;
	return true;
}
bool insertIndex(SingleList* list, void* data, int index) 
{
	if (list == NULL)return false;
	if (list->head == NULL) {
		return insertAtBeginning(list,data);
	}
	if (index > list->length-1) {
		return false;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return false;
	p->data = data;
	p->next = NULL;
	int currentIndex = 0;
	Node* cur = list->head;
	Node* pre = cur;
	do {
		if (currentIndex == index&&currentIndex==0) {
			p->next = cur;
			list->head = p;
			list->length++;
			return true;
		}
		if (currentIndex == index) {
			p->next = pre->next;
			pre->next = p;
			list->length++;
			return true;
		}
		pre = cur;
		cur = cur->next;
		currentIndex++;
	} while (cur);
	return false;
}
bool deleteAtEnding(SingleList* list) 
{
	if (list == NULL)
		return false;
	if (list->length == 0)
		return false;
	Node* p = list->head;
	Node* pre = p;
	while (p->next) {
		pre = p;
		p = p->next;
	}
	pre->next = NULL;
	free(p);
	p = NULL;
	list->length--;
	if (list->length == 0)
		list->head = NULL;
	return true;
}

bool deleteIndex(SingleList* list, int index) 
{
	if (list == NULL)
		return false;
	if (index > list->length-1) {
		return false;
	}
	if (list->length == 1)
		return deleteAtEnding(list);
	int currentIndex = 0;
	Node* cur = list->head;
	Node* pre = cur;
	do {
		if (currentIndex == index && currentIndex == 0) {
			list->head = cur->next;
			free(cur);
			cur = NULL;
			list->length--;
			return true;
		}
		if (currentIndex == index) {
			pre->next= cur->next;
			free(cur);
			cur = NULL;
			list->length--;
			return true;
		}
		pre = cur;
		cur = cur->next;
		currentIndex++;
	} while (cur);
	return false;
}

int getLength(SingleList* list)
{
	if (list == NULL)
		return 0;
	return list->length;
}
Node* getNodeByIndex(SingleList* list, int index)
{
	if (list == NULL)
		return NULL;
	Node* p = list->head;
	int curIndex = 0;
	do {
		if (index == curIndex) {
			return p;
		}
		p = p->next;
		curIndex++;
	} while (p);
	return NULL;
}
void freeSingleList(SingleList* list) 
{
	if (list == NULL)
		return;
	Node* cur = list->head;
	Node* nextNode = cur;
	while (cur) {
		nextNode = cur->next;
		free(cur);
		cur = nextNode;
	}
	list->head = NULL;
	list->length = 0;
	free(list);
	list = NULL;
}
void foreach(SingleList* list, void (*printFunc)(void*)) 
{
	if (list == NULL || list->length == 0)return;
	Node* p = list->head;
	while (p != NULL) {
		printFunc(p->data);
		p= p->next;
	}
}