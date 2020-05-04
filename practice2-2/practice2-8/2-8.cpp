#include <stdio.h>
#include <stdlib.h>

#define InitSize 2

typedef struct{
	int* data;
	int currentSize;
	int totalLength;
}ArrayList;

void initArrayList(ArrayList &list) {
	list.data = (int*)malloc(sizeof(int) * InitSize);
	list.currentSize = InitSize;
	list.totalLength = InitSize;
}

/*
	一个一维数组中依次保存了两个顺序表，将两个顺序表的位置互换，即将(b1,b2,b3...)放在(a1,a2,a3...)前边
*/
void reverseArrayList(int arr[] ,  ArrayList& list1, ArrayList& list2) {
	int sumLength = list1.currentSize + list2.currentSize;
	for (int i = 0; i < sumLength; i++)
	{
		if (i < list2.currentSize)
		{
			arr[i] = list2.data[i];
		}
		else
		{
			arr[i] = list1.data[i - list2.currentSize];
		}
	}
}

void main() {
	int arr[4] = { 1,2,5,6 };
	ArrayList list1;
	initArrayList(list1);
	list1.data[0] = 1;
	list1.data[1] = 2;
	ArrayList list2;
	initArrayList(list2);
	list2.data[0] = 5;
	list2.data[1] = 6;
	reverseArrayList(arr, list1, list2);
	for (int i = 0; i < list1.currentSize + list2.currentSize; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

}