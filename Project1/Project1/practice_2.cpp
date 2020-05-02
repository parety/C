#include <stdio.h>
#include <stdlib.h>

#define InitSize 5

typedef struct {
	int* data;
	int size; //当前长
	int length;//总长
}ArrayList;

void practice2InitArrayList(ArrayList& list) {
	list.data = (int*)malloc(sizeof(int*) * InitSize);
	for (int i = 0; i < InitSize; i++)
	{
		list.data[i] = i;
	}
	list.length = InitSize;
	list.size = InitSize;
}

//2.1删除最小元素,并返回被删元素的值，空位由最后一位补上，若顺序表为空，则显示出错信息并退出
int practice2DeleteMinElemArrayList(ArrayList& list) {
	if (list.size == 0)
	{
		return -1;
	}
	//遍历找出最小元素
	int min = list.data[0];
	int position = -1;
	for (int i = 0; i < list.size; i++)
	{
		if (list.data[i] <= min)
		{
			min = list.data[i];
			position = i;
		}
	}
	list.data[position] = list.data[list.size - 1];
	list.size--;
	return min;
}


void main() {
	ArrayList list;

	practice2InitArrayList(list);
	printf("data = %d\n",  list.size);
	for (int i = 0; i < list.size; i++)
	{
		printf("data[%d] = %d\n", i, list.data[i]);
	}
	printf("*************************");
	practice2DeleteMinElemArrayList(list);
	for (int i = 0; i < list.size; i++)
	{
		printf("data[%d] = %d\n", i, list.data[i]);
	}
}

