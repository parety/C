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
	将一维数组中的n(n>1)个元素，循环左移p位(0<p<n)，即将(X0,X1,X2...)变换为(Xp,Xp+1,Xp+2...)
	原：	X0,X1,X1,...Xp-1,	(Xp,Xp+1,Xp+2...Xn-1)
	移动后：(Xp,Xp+1,Xp+2...Xn-2,Xn-1)	,X0,X1...Xp-1
		0:p;	1:p+1;	2:p+2;	...
*/
//一、暴力循环可做:
		//将操作拆解为单次移动，再循环，移动n次，时间复杂度高
//二、书上答案：分别逆置两个小表，再整个的逆置
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

//p为要移动的位数
void movePInArrayListMethod2(ArrayList& list, int p) {
	for (int i = 0; i < p; i++)
	{
		//执行单次移动:把list.data[0]放到list.data[list.currentSize-1]，其他元素坐标整体-1
		int tmp = list.data[0];
		for (int j = 0; j < list.currentSize-1; j++)
		{
			list.data[j] = list.data[j + 1];
		}
		list.data[list.currentSize - 1] = tmp;
	}
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

	//先反转两个子表，再反转整个
	//movePInArrayList(list ,0, 2);
	//movePInArrayList(list, 2, list.currentSize-1);
	//movePInArrayList(list, 0, list.currentSize - 1);
	//printf("method1:\n");
	//for (int i = 0; i < list.currentSize; i++)
	//{
	//	printf("list.data[%d] = %d\n", i, list.data[i]);
	//}
	movePInArrayListMethod2(list, 2);
	printf("method2:\n");
	for (int i = 0; i < list.currentSize; i++)
	{
		printf("list.data[%d] = %d\n", i, list.data[i]);
	}
}

