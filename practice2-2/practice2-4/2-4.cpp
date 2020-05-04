#include <stdio.h>
#include <stdlib.h>
#define InitSize 10

/*
	������˳����У�ɾ��������s��t֮�������ֵ(s<t)�����s/t���������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
*/

typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;

//���α����ҳ�s��t���±꣬��t��ʼ������size����Ԫ���ƶ�����ǰt-s+1��λ����
int deleteBetweenSAndT(ArrayList& list ,int s , int t) {
	printf("s = %d\n", s);
	printf("t = %d\n", t);
	if (list.data == NULL || s >= t)
	{
		printf("param s or t is not applicable");
		return -1;
	}
	int sIndex = 0;
	int tIndex = 0;
	for (int i = 0; i < list.currentSize; i++)
	{
		if (s <= list.data[i]) {
			sIndex = i;
			break;
		}
	}	
	for (int i = list.currentSize - 1; i > 0 ; i--)
	{
		if (t >= list.data[i])
		{
			printf("i = %d\n", i);
			tIndex = i;
			break;
		}
	}
	//printf("sIndex = %d\n", sIndex);
	//printf("tIndex = %d\n", tIndex);
	int tmp = 0;
	for (int i = tIndex; i < list.currentSize; i++)
	{
		//printf("tmp = %d\n", tmp);
		list.data[sIndex + tmp] = list.data[i+1];
		tmp++;
	}
	list.currentSize -= (tIndex - sIndex + 1);
	return list.currentSize;
}

void main() {
	ArrayList list;
	list.data = (int*)malloc(sizeof(int) * InitSize);
	for (int i = 0; i < InitSize; i++)
	{
		list.data[i] = i / 2;
	}
	list.currentSize = InitSize;
	list.totalLength = InitSize;
	int s = 1;
	int t = 2;
	printf("before\n");
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
	printf("after\n");
	deleteBetweenSAndT(list, s, t);
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
}