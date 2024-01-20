#include<stdio.h>
#include"CircleList.h"
void myprint(void* data) {
	int value = *(int*)data;
	printf("%d\t", value);
}
int main(void) {
	int a[] = {1,2,3,4,5,6,7,8};
	CircleList* list= createCircleList();
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
		insertAtEnd(list,a+i);

	foreachCircleList(list, myprint);
	printf("list length=%d",list->length);
	printf("\n");

	int t = 888;
	insertAtIndex(list, &t, 1);
	foreachCircleList(list, myprint);
	printf("list length=%d", list->length);
	printf("\n");

	deleteAtBegin(list);
	foreachCircleList(list, myprint);
	printf("list length=%d", list->length);
	printf("\n");

	deleteAtEnd(list);
	foreachCircleList(list, myprint);
	printf("list length=%d", list->length);
	printf("\n");

	deleteAtIndex(list,1);
	foreachCircleList(list, myprint);
	printf("list length=%d", list->length);
	printf("\n");

	int v = 9999;
	*(int*)getNodeByIndex(list, list->length - 1)->data = v;
	foreachCircleList(list, myprint);
	printf("list length=%d", list->length);
	printf("\n");
}