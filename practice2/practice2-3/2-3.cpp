#include <stdio.h>
#include <stdlib.h>

/*
	�Գ���Ϊn��˳�����дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨��ɾ��˳��������е�ֵΪx������Ԫ��
*/
#define InitSize 10
typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;

//��ǰ���������ͳ��X���ֵĸ���
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

//������������ͳ��x���ִ�������������x��Ԫ����ǰ�ƶ�number
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