#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;

/*
	将两个有序的顺序表，合并为一个新的有序顺序表，并由函数返回结果顺序表
*/
//使用p1和p2，指向两个顺序表的下标，依次遍历。当某个表满时，只添加另一个表即可
ArrayList integrateTwoOrderedSqList(ArrayList& list1 , ArrayList &list2) {
	ArrayList result;
	result.currentSize = 0;
	int a = list1.currentSize + list2.currentSize;
	result.totalLength = a;
	result.data = (int*)malloc(sizeof(int*) * a);
	if (list1.data == NULL)
	{
		return list2;
	}
	if (list2.data == NULL)
	{
		return list1;
	}
	int p1 = 0;
	int p2 = 0;
	int lastOne = 0;
	for (int i = 0; i < list1.currentSize + list2.currentSize; i++)
	{
		if (p1 >= list1.currentSize)
		{
			result.data[i] = list2.data[p2];
			p2++;
			continue;
		}
		if (p2 >= list2.currentSize)
		{
			result.data[i] = list1.data[p1];
			p1++;
			continue;
		}
		if (list1.data[p1] <= list2.data[p2]) {
			result.data[i] = list1.data[p1];
			p1++;
		}
		else
		{
			result.data[i] = list2.data[p2];
			p2++;
		}
	}
	result.currentSize = list1.currentSize + list2.currentSize;
	return result;
}

void main() {
	ArrayList list;
	list.currentSize = 3;
	list.totalLength = 3;
	list.data = (int*)malloc(sizeof(int) * list.totalLength);
	for (int i = 0; i < list.currentSize; i++)
	{
		list.data[i] = i + 1;//1 2 3
	}
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
	ArrayList list2;
	list2.currentSize = 3;
	list2.totalLength = 3;
	list2.data = (int*)malloc(sizeof(int) * list2.totalLength);
	for (int i = 0; i < list2.currentSize; i++)
	{
		list2.data[i] = i * 2; //0 2 4
	}
	for (int i = 0; i < list2.currentSize; i++)
	{
		printf("list2.data[%d] = %d\n", i, list2.data[i]);
	}
	ArrayList resultList = integrateTwoOrderedSqList(list, list2);
	for (int i = 0; i < resultList.currentSize; i++)
	{
		printf("result.data[%d] = %d\n", i, resultList.data[i]);
	}

}