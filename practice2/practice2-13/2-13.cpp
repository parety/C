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
	给定一个含n(n>=1)个整数的数组，设计一个在时间上尽可能高效的算法
	找出数组中未出现的最小正整数
	例如：数组{-5,3,2,3}中未出现的最小正整数是1
		  数组{1,2,3}中未出现的最小正整数是4
*/
// 使用新数组，新数组的数组下标和目标数组的值对应，新数组的值统计目标数组对应值出现的次数
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