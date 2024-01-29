#include "CircleList.h"
#include<stdio.h>
CircleList* createCircleList()
{
	CircleList* list = (CircleList*)malloc(sizeof(CircleList));
	if (list == NULL)
		return NULL;
	list->head = list->tail = NULL;
	list->length = 0;
	return  list;
}

Node* createCircleNode(void* data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	if (n == NULL)
		return NULL;
	n->data = data;
	n->next = NULL;
	return n;
}

bool insertAtBegin(CircleList* list,void*data)
{
	if (list == NULL)
		return false;
	Node* newNode = createCircleNode(data);
	newNode->next = list->head;
	list->head = newNode;
	if (list->tail)
		list->tail->next = list->head;
	else{
		list->tail = newNode;
		newNode->next = list->tail;
	}
		
	list->length++;
	return true;
}

bool insertAtIndex(CircleList* list, void *data,int index)
{
	if (list == NULL||list->length==0)
		return false;
	Node* newNode = createCircleNode(data);
	int curIndex = 0;
	Node* cur = list->head;
	Node* pre = cur;
	do {
		if (curIndex == index && index == 0 && list->length == 1) {
			list->tail->next = newNode;
			list->tail = newNode;
			newNode->next = list->head;
			list->length++;
			return true;
		}
		if (curIndex == index && index == 0) {
			newNode->next = list->head;
			list->head = newNode;
			list->tail->next = newNode;
			list->length++;
			return true;
		}
		if (curIndex == index) {
			newNode->next = cur;
			pre->next = newNode;
			list->length++;
			return true;
		}
		pre = cur;
		cur = cur->next;
		curIndex++;
	} while (cur!=list->head);

	return false;
}

bool insertAtEnd(CircleList* list,void*data)
{
	if (list == NULL)
		return false;
	Node* newNode = createCircleNode(data);
	if (list->tail) {
		list->tail->next = newNode;
		list->tail = newNode;
		list->tail->next = list->head;
	}
	else {
		list->head=list->tail = newNode;
		list->tail->next = list->head;
	}
		
	list->length++;
	return true;
}

bool deleteAtBegin(CircleList* list)
{
   return deleteAtIndex(list, 0);
}

bool deleteAtIndex(CircleList* list, int index)
{
	if (list == NULL||list->length==0)
		return false;
	int curIndex = 0;
	Node* cur = list->head;
	Node* pre = cur;
	do {
		if (curIndex == index&&index==0) {
			list->tail->next = list->head->next;
			list->head = list->head->next;
			free(cur);
			list->length--;
			return true;
		}
		if (curIndex == index && index == list->length-1) {
			pre->next = list->head;
			cur->next = NULL;
			free(cur);
			cur = NULL;
			list->length--;
			return true;
		}
		if (curIndex == index) {
			pre->next = cur->next;
			cur->next = NULL;
			free(cur);
			cur = NULL;
			list->length--;
			return true;
		}
		pre = cur;
		cur = cur->next;
		curIndex++;
	} while (cur!=list->head);
	return false;
}

bool deleteAtEnd(CircleList* list)
{
	return deleteAtIndex(list,list->length-1);
}

Node* getNodeByIndex(CircleList* list, int index)
{
	if (list == NULL||index<0||index>list->length-1)
		return NULL;
	int curIndex = 0;
	Node* cur = list->head;
	do {
		if (curIndex == index) {
			return cur;
		}
		cur = cur->next;
		curIndex++;
	} while (cur!=list->head);
	return NULL;
}

void foreachCircleList(CircleList* list, void(*printFunc)(void*))
{
	if (list == NULL||list->length==0)
		return;
	Node* p = list->head;
	do {
		printFunc(p->data);
		p = p->next;
	} while (p != list->head);
}
