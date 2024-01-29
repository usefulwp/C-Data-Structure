#include"Stack.h"

int main(void ){
	Stack* stack=createStack();
	for(int i=0;i<10;i++)
		push(stack,i);
	printf("%d\n",pop(stack));
	printStack(stack);
	printf("%d",stack->length);
}