#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;

/*
	从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
*/

//循环，与下一个重复则删除
//void deleteRepeatElementFromArrayList(ArrayList& list) {
//	if (list.data == NULL)
//	{
//		return;
//	}
//	int count = 0;
//	for (int i = 0; i < list.currentSize; i++)
//	{
//		if (list.data[i] == list.data[i+1])
//		{
//			for (int j = i; j < list.currentSize - 1; j++) {
//				list.data[j] = list.data[j + 1];
//			}
//			count++;
//		}
//	}
//	list.currentSize -= count;
//}
//上述方法未完成，用直接插入排序会更好，空间复杂度没限制
void deleteRepeatElementFromArrayList(ArrayList& list) {
	ArrayList list1;
	list1.data = (int*)malloc(sizeof(int) * list.currentSize);
	list1.totalLength = 0;
	list1.data[0] = list.data[0];
	list1.currentSize = 1;
	for (int i = 1; i < list.currentSize; i++)
	{
		if (list.data[i] != list1.data[list1.currentSize - 1])
		{
			list1.data[list1.currentSize] = list.data[i];
			list1.currentSize++;
		}
	}
	list = list1;
}


void main() {
	ArrayList list;
	list.data = (int*)malloc(sizeof(int) * InitSize);
	list.currentSize = InitSize;
	list.totalLength = InitSize;
	for (int i = 0; i < list.currentSize; i++)
	{
		list.data[i] = i / 2;
	}
	printf("before\n");
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
	printf("after\n");
	deleteRepeatElementFromArrayList(list);
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
}