#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
typedef struct  {
	Node* head;
	Node* tail;
	unsigned int size;
}Queue;
_declspec(dllexport) Queue* creatQueue();
_declspec(dllexport) bool push_back(Queue* queue,int data);
_declspec(dllexport)  bool push_front(Queue* queue,int data);
_declspec(dllexport)  int pop_front(Queue* queue);
_declspec(dllexport) int pop_back(Queue* queue);
_declspec(dllexport)  void printQueue(Queue* queue);
