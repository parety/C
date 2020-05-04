#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;


/*
	设计一个高效算法，将顺序表的所有元素逆置，要求空间复杂度为O(1)
*/

//扫描前半部分，与坐标互补的后半部分交换
void reverse(ArrayList& list) {
	if (list.data == NULL)
	{
		return;
	}
	int tmp = 0;
	for (int i = 0; i < list.currentSize / 2; i++)
	{
		tmp = list.data[i];
		list.data[i] = list.data[list.currentSize - i - 1];
		list.data[list.currentSize - i - 1] = tmp;
	}
}


void main() {
	ArrayList list;
	list.data = (int*)malloc(sizeof(int) * InitSize);
	for (int i = 0; i < InitSize; i++)
	{
		list.data[i] = i;
	}
	list.currentSize = InitSize;
	list.totalLength = InitSize;
	for (int i = 0; i < InitSize; i++)
	{
		printf("list.data[%d] = %d\n", i , list.data[i]);
	}

	reverse(list);
	for (int i = 0; i < InitSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}

}