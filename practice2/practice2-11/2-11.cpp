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
	����ΪL(L>=1)����������S������[L/2]λ�õ�����ΪS����λ��
		������S1=(11,13,15,17,19)����S1����λ����15��
	�������е���λ������������Ԫ�ص��������е���λ��
	���������ȳ���������A��B���ҳ���������A��B����λ��
*/