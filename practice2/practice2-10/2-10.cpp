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
	��һά�����е�n(n>1)��Ԫ�أ�ѭ������pλ(0<p<n)������(X0,X1,X2...)�任Ϊ(Xp,Xp+1,Xp+2...)
	ԭ��	X0,X1,X1,...Xp-1,	(Xp,Xp+1,Xp+2...Xn-1)
	�ƶ���(Xp,Xp+1,Xp+2...Xn-2,Xn-1)	,X0,X1...Xp-1
		0:p;	1:p+1;	2:p+2;	...
*/
//һ������ѭ������:��p��n-1��Ԫ�طŵ��±��ٽ�0��p-1�ķŵ��±����ܲ���
//�������ϴ𰸣��ֱ���������С��������������
void movePInArrayList(ArrayList& list ,int start ,  int end) {
	printf("functionStart\n");
	if (list.data == NULL)
	{
		printf("list.data == NULL\n");
		return;
	}
	if (end > list.currentSize - 1)
	{
		printf("end is too long!\n");
		return;
	}
	if (start < 0)
	{
		printf("start is not proper!\n");
		return;
	}
	int tmp = 0;
	for (int i = start; i < (end - start)/2; i++) //start , start + 1, start +2 ...end
	{
		printf("i = %d\n", i);
		tmp = list.data[i];
		list.data[i] = list.data[end - i];
		list.data[end - i] = tmp;
	}
	printf("functionEnd\n");
}

void main() {
	ArrayList list;
	initArrayList(list);
	printf("before\n");
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
	//movePInArrayList(list, 2);//01234->23401

	//movePInArrayList(list ,0, 2);
	//movePInArrayList(list, 2, list.currentSize);
	movePInArrayList(list, 0, list.currentSize - 1);
	printf("after\n");
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}

}