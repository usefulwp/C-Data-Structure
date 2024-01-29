#include<stdbool.h>
#include<stdio.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
typedef struct   {
	Node* top;
	unsigned int length;
}Stack;
Stack* createStack();
bool push(Stack* stack,int data);
int pop(Stack* stack);
void freeStack(Stack* stack);
void printStack(Stack* stack);
