#include <stdio.h>
#include <stdlib.h>

/*
	对长度为n的顺序表，编写一个时间复杂度为O(n)，空间复杂度为O(1)的算法，删除顺序表中所有的值为x的数据元素
*/
#define InitSize 10
typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;

//从前往后遍历，统计X出现的个数
void deleteX(ArrayList& list , int x) {
	if (list.data == NULL)
	{
		return;
	}
	int number = 0;
	for (int i = 0; i < list.currentSize; i++)
	{
		if (list.data[i] != x)
		{
			list.data[number] = list.data[i];
			number++;
		}
	}
	list.currentSize = number;
}

//方法二：遍历统计x出现次数，将不等于x的元素向前移动number
void deleteX2(ArrayList& list, int x) {
	if (list.data == NULL)
	{
		return;
	}
	int number = 0;
	for (int i = 0; i < list.currentSize; i++)
	{
		if (list.data[i] != x) {
			list.data[i - number] = list.data[i];
		}
		else {
			number++;
		}
	}
	list.currentSize = list.currentSize - number;
}


void main() {
	ArrayList list;
	list.data = (int*)malloc(sizeof(int) * InitSize);
	list.currentSize = InitSize;
	list.totalLength = InitSize;
	for (int i = 0; i < InitSize; i++)
	{
		list.data[i] = i / 2;
	}
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
	printf("list.currentSize = %d\n", list.currentSize);

	//printf("deleteX\n");
	//deleteX(list, 3);
	//for (int i = 0; i < list.currentSize; i++)
	//{
	//	printf("list.data[%d] = %d\n", i, list.data[i]);
	//}
	//printf("list.currentSize = %d\n", list.currentSize);

	printf("deleteX2\n");
	deleteX2(list, 3);
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
	printf("list.currentSize = %d\n", list.currentSize);
}