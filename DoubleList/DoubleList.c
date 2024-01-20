#include"DoubleList.h"
DoubleList* createDoubleList() 
{
	DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
	if (list == NULL)
		return NULL;
	list->head=list->tail = NULL;
	list->length = 0;
	return list;
}
static Node* creatNode(void* data) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return NULL;
	p->data = data;
	p->next = NULL;
	p->pre = NULL;
}
bool insertAtBeginning(DoubleList* list, void* data)
{
	if (list == NULL)
		return false;
	Node* newNode=creatNode(data);
	if (newNode == NULL)
		return false;
	list->tail = list->head;
	newNode->next = list->head;
	newNode->pre = NULL;
	list->head = newNode;
	list->length++;
	return true;
}
bool insertAtEnd(DoubleList* list, void* data) 
{
	if (list == NULL)
		return false;
	Node* newNode = creatNode(data);
	if (newNode == NULL)
		return false;
	if (list->length == 0) {
		list->head=list->tail = newNode;
		list->length++;
	}
	else {
		list->tail->next = newNode;
		newNode->pre = list->tail;
		list->tail = newNode;
		list->length++;
	}
	return true;
}
bool insertAtIndex(DoubleList* list, void* data, int index) 
{
	if (list == NULL||list->length==0)
		return false;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
		return false;
	newNode->pre = NULL;
	newNode->next = NULL;
	newNode->data = data;
	int currentIndex = 0;
	Node* cur = list->head;
	do {
		if (currentIndex == index && index == 0) {
			newNode->pre = NULL;
			newNode->next = list->head;
			list->head = newNode;
			list->length++;
			return true;
		}
	    if (currentIndex == index && list->length == 1) {
			cur->next = newNode;
			newNode->pre = cur;
			newNode->next = NULL;
			list->length++;
			return true;
		}
	    if (currentIndex == index) { 
			newNode->pre = cur->pre;
			newNode->next = cur;
			cur->pre->next = newNode;
			cur->pre = newNode;
			list->length++;
			return true;
		}
		cur = cur->next;
		currentIndex++;
	} while (cur);
	return false;
}
bool deleteAtBeginning(DoubleList* list) 
{
	return deleteAtIndex(list,0);
}
bool deleteAtEnd(DoubleList* list) 
{
	return deleteAtIndex(list,list->length-1);
}
bool deleteAtIndex(DoubleList* list, int index) 
{
	if (list == NULL)
		return false;
	int currentIndex = 0;
	Node* cur = list->head;
	do {
		if (currentIndex == index && index == 0) {
			list->head = cur->next;
			list->head->pre = NULL;
			free(cur);
			cur = NULL;
			list->length--;
			return true;
		}
		if (currentIndex == index && index == list->length-1) {
			list->tail = list->tail->pre;
			free(list->tail->next);
			list->tail->next = NULL;
			list->length--;
			return true;
		}
		if (currentIndex == index) {
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
			cur->pre = NULL;
			cur->next = NULL;
			free(cur);
			cur = NULL;
			list->length--;
			return true;
		}
		cur = cur->next;
		currentIndex++;
	} while (cur);
	return false;
}
void freeDoubleList(DoubleList* list)
{
	if (list == NULL)
		return;
	Node* next, * cur;
	next=cur= list->head;
	while (cur) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(list);
	list = NULL;
}
Node* getNodeByIndex(DoubleList* list, int index)
{
	if (list == NULL || index > list->length - 1)
		return NULL;
	int dt = list->length - index + 1;
	if (dt > index + 1) {
		Node* p = list->head;
		int curIndex = 0;
		do {
			if (curIndex == index) {
				return p;
			}
			p = p->next;
			curIndex++;
		} while (p);
	}
	else {
		Node* p = list->tail;
		int curIndex = list->length - 1;
		do {
			if (curIndex == index) {
				return p;
			}
			p = p->pre;
			curIndex--;
		} while (p);
	}
	return NULL;
}
void foreach(DoubleList* list, void(*printFunc)(void* data)) 
{
	if (list == NULL)
		return;
	Node* cur = list->head;
	while (cur) {
		printFunc(cur->data);
		cur = cur->next;
	}
}