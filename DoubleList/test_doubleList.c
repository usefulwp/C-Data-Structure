#include"DoubleList.h"
#include<stdio.h>
void myprint(void* data) {
	int value = *(int*)data;
	printf("%d\t",value); 
}
int main(void) {
	DoubleList* list = createDoubleList();
	int a[] = {1,2,3,4,5,6,7,8};
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		insertAtEnd(list, &a[i]);
	foreach(list, myprint);
	printf("list length =%d", list->length);
	printf("\n");

	int t = 9;
	deleteAtEnd(list);
	foreach(list, myprint);
	printf("list length =%d", list->length);
	printf("\n");


	insertAtIndex(list, &t, 2);
	foreach(list, myprint);
	printf("list length =%d", list->length);
	printf("\n");

	*(int*)getNodeByIndex(list, list->length - 1)->data = 100;
	foreach(list, myprint);
	printf("list length =%d", list->length);
	printf("\n");

	freeDoubleList(list);
}