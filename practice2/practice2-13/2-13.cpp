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
	给定一个含n(n>=1)个整数的数组，设计一个在时间上尽可能高效的算法
	找出数组中未出现的最小正整数
	例如：数组{-5,3,2,3}中未出现的最小正整数是1
		  数组{1,2,3}中未出现的最小正整数是4
*/