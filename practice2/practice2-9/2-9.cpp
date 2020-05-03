#include <stdio.h>
#include <stdlib.h>

#define InitSize 5

typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;

void initArrayList(ArrayList& list) {
	list.data = (int*)malloc(sizeof(int) * InitSize);
	list.currentSize = InitSize;
	list.totalLength = InitSize;
	for (int i = 0; i < InitSize; i++)
	{
		list.data[i] = i;
	}
}
/*
	递增顺序表，用最少时间，在表中查找值为x的元素，若找到则将其与后继元素位置交换，若找不到则将其插入表中，并使表中元素仍递增有序
*/

void findXToReplaceOrInsert(ArrayList& list, int x) {
	if (list.data == NULL)
	{
		return;
	}
	int tmp = 0;
	int count = 0;
	for (int i = 0; i < list.currentSize; i++)
	{
		if (list.data[i] == x) {
			tmp = list.data[i];
			list.data[i] = list.data[i + 1];
			list.data[i + 1] = tmp;
			printf("tmp = %d\n", tmp);
			printf("i = %d\n", i);
			count++;
			break;//如果不break，则在下次遍历时，依然会相等
		}
	}
	if (count == 0)
	{
		printf("count == 0\n");
		list.currentSize += 1;
		list.data = (int*)malloc(sizeof(int) * list.currentSize);
		list.data[list.currentSize - 1] = x;
	}

}

void main() {
	ArrayList list;
	initArrayList(list);
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("init list.data[%d] = %d\n", i, list.data[i]);
	}

	findXToReplaceOrInsert(list, 3);
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}

}