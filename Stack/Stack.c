#include "Stack.h"
#include<stdlib.h>
Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("栈的内存分配失败");
        return NULL;
    }
    stack->top = NULL;
    stack->length = 0;
    return  stack;
}

bool push(Stack* stack, int data)
{
    if (stack == NULL)
        return false;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("创建新结点，分配内存失败");
        return false;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->length++;
    return true;
}

int pop(Stack* stack)
{
    if (stack==NULL||stack->length == 0)
        return NULL;
    Node* top = stack->top;
    int value = top->data;
    stack->top=stack->top->next;
    stack->length--;
    free(top);
    top = NULL;
    return value;
}

void freeStack(Stack* stack)
{
    if (stack == NULL)
        return;
    Node* cur = stack->top;
    Node* next = cur;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = NULL;
        cur = next;
    }
    free(stack);
    stack = NULL;
}


void printStack(Stack* stack)
{
    if (stack == NULL|| stack->length == 0)
        return;
    Node* cur = stack->top;
    while (cur) {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
