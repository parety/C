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
	����һ����n(n>=1)�����������飬���һ����ʱ���Ͼ����ܸ�Ч���㷨
	�ҳ�������δ���ֵ���С������
	���磺����{-5,3,2,3}��δ���ֵ���С��������1
		  ����{1,2,3}��δ���ֵ���С��������4
*/