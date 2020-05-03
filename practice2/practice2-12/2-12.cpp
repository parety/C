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
	��֪һ����������A=(a0,a1,...,an-1),����0<=ai<n(0<=i<n)
	������ap1=ap2=...=apm=x �� m>n/2(0<=pk<n,1<=k<=m)�����xΪA����Ԫ��
	����A={0,5,5,3,5,7,5,5},��5Ϊ��Ԫ��
	����A={0,5,5,3,5,1,5,7}����A��û����Ԫ��
	����A�е�n��Ԫ�ر�����һ��һά�����У����ҳ�A����Ԫ��
	�����ڣ��������Ԫ�أ��������-1
	����ĳ�����������ظ�����ռ���鳤��һ����Ԫ�أ�
*/