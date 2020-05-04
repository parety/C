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
// ʹ�������飬������������±��Ŀ�������ֵ��Ӧ���������ֵͳ��Ŀ�������Ӧֵ���ֵĴ���
#define len 5
int selectMinPositiveInteger(int arr[]) {
	int arrNew[len + 1];
	for (int i = 0; i <= len; i++)
	{
		arrNew[i] = 0; 
	}
	for (int i = 1; i <= len; i++)
	{
		if (arr[i - 1] > len || arr[i - 1] <= 0)
		{
			continue;
		}
		if (arr[i -1] > 0)
		{
			arrNew[arr[i - 1]]++;
		}
	}
	for (int i = 1; i <= len; i++)
	{
		if (arrNew[i] == 0)
		{
			return i;
		}
	}
	return -1;
}

void main() {
	int arr[] = { -1,-4,2,6,9 };
	int result = selectMinPositiveInteger(arr);
	printf("result = %d\n", result);
}