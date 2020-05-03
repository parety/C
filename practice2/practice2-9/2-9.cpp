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
	����˳���������ʱ�䣬�ڱ��в���ֵΪx��Ԫ�أ����ҵ���������Ԫ��λ�ý��������Ҳ������������У���ʹ����Ԫ���Ե�������
*/

void findXToReplaceOrInsert(ArrayList& list, int x) {
	if (list.data == NULL)
	{
		return;
	}
	int tmp = 0;
	int count = 0;
	for (int i = 0; i < list.currentSize; i++)
	{
		if (list.data[i] == x) {
			tmp = list.data[i];
			list.data[i] = list.data[i + 1];
			list.data[i + 1] = tmp;
			printf("tmp = %d\n", tmp);
			printf("i = %d\n", i);
			count++;
			break;//�����break�������´α���ʱ����Ȼ�����
		}
	}
	if (count == 0)
	{
		printf("count == 0\n");
		list.currentSize += 1;
		list.data = (int*)malloc(sizeof(int) * list.currentSize);
		list.data[list.currentSize - 1] = x;
	}

}

void main() {
	ArrayList list;
	initArrayList(list);
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("init list.data[%d] = %d\n", i, list.data[i]);
	}

	findXToReplaceOrInsert(list, 3);
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}

}