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
//一、暴力循环可做:将p到n-1的元素放到新表，再将0到p-1的放到新表，性能不高
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