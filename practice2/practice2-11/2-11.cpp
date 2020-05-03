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
	长度为L(L>=1)的升序序列S，处在[L/2]位置的数称为S的中位数
		若序列S1=(11,13,15,17,19)，则S1的中位数是15，
	两个序列的中位数是它们所有元素的升序序列的中位数
	现有两个等长升序序列A和B，找出两个序列A和B的中位数
*/