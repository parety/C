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
	已知一个整数序列A=(a0,a1,...,an-1),其中0<=ai<n(0<=i<n)
	若存在ap1=ap2=...=apm=x 且 m>n/2(0<=pk<n,1<=k<=m)，则称x为A的主元素
	例如A={0,5,5,3,5,7,5,5},则5为主元素
	又如A={0,5,5,3,5,1,5,7}，则A中没有主元素
	假设A中的n个元素保存在一个一维数组中，请找出A的主元素
	若存在，则输出该元素，否则输出-1
	（即某个在数组中重复次数占数组长度一半多的元素）
*/