#include"SingleList.h"
#include<stdio.h>
void myprint(void* data) {
	int value = *(int*)data;
	printf("%d\t",value); 
}
int main(void) {
	SingleList* list = createSingleList();
	int a[] = { 1,2,3,4,5,6,7 };
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
		insertAtBeginning(list,&a[i]);

	int insertValue = 9;
	insertIndex(list, &insertValue, 2);
	printf("list length： %d\n", list->length);
	foreach(list,myprint);
	printf("\n");

	deleteIndex(list, 2);
	printf("list length： %d\n", list->length);
	foreach(list, myprint);
	printf("\n");

	insertAtBeginning(list, &insertValue);
	printf("在头部插入9\n");
	foreach(list, myprint);
	printf("\n");

	deleteAtEnding(list);
	printf("删除链表最后一个\n");
	foreach(list, myprint);

	freeSingleList(list);
	return ;
}