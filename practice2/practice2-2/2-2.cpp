#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct {
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;


/*
	���һ����Ч�㷨����˳��������Ԫ�����ã�Ҫ��ռ临�Ӷ�ΪO(1)
*/

//ɨ��ǰ�벿�֣������껥���ĺ�벿�ֽ���
void reverse(ArrayList& list) {
	if (list.data == NULL)
	{
		return;
	}
	int tmp = 0;
	for (int i = 0; i < list.currentSize / 2; i++)
	{
		tmp = list.data[i];
		list.data[i] = list.data[list.currentSize - i - 1];
		list.data[list.currentSize - i - 1] = tmp;
	}
}


void main() {
	ArrayList list;
	list.data = (int*)malloc(sizeof(int) * InitSize);
	for (int i = 0; i < InitSize; i++)
	{
		list.data[i] = i;
	}
	list.currentSize = InitSize;
	list.totalLength = InitSize;
	for (int i = 0; i < InitSize; i++)
	{
		printf("list.data[%d] = %d\n", i , list.data[i]);
	}

	reverse(list);
	for (int i = 0; i < InitSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}

}