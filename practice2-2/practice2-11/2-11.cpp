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

ArrayList functionDirectInsertOrder(ArrayList &list1 , ArrayList &list2) {
	if (list1.data == NULL && list2.data != NULL)
	{
		return list2;
	}
	if (list1.data != NULL && list2.data == NULL)
	{
		return list1;
	}
	ArrayList result;
	initArrayList(result);
	int sumLength = list1.currentSize + list2.currentSize;
	result.data = (int*)malloc(sizeof(int) * sumLength);
	result.currentSize = sumLength;
	result.totalLength = sumLength;
	int p1 = 0;
	int p2 = 0;
	for (int i = 0; i < sumLength; i++)
	{
		if (p1 >= list1.currentSize)
		{
			result.data[p1 + p2] = list2.data[p2];
			p2++;
			continue;
		}
		if (p2 >= list2.currentSize)
		{
			result.data[p1 + p2] = list1.data[p1];
			p1++;
			continue;
		}
		if (list1.data[p1] <= list2.data[p2]) {
			result.data[p1 + p2] = list1.data[p1];
			p1++;
		}
		else
		{
			result.data[p1 + p2] = list2.data[p2];
			p2++;
		}
	}
	return result;
}

void main() {
	ArrayList list1;
	initArrayList(list1);//01234
	ArrayList list2;
	initArrayList(list2);//01234
	for (int i = 0; i < list2.currentSize; i++)
	{
		list2.data[i] = i + 2;//23456
	}
	ArrayList result = functionDirectInsertOrder(list1, list2);//0122 3 34456
	for (int i = 0; i < result.currentSize; i++)
	{
		printf("result.data[%d] = %d\n", i, result.data[i]);
	}
	printf("��λ��Ϊ:%d", result.data[result.currentSize / 2]);

}