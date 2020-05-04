#include <stdio.h>
#include <stdlib.h>

#define InitSize 5

typedef struct {
	int data;
	int count;
}ArrayList;


/*
	已知一个整数序列A=(a0,a1,...,an-1),其中0<=ai<n(0<=i<n) ****隐蔽条件****
	若存在ap1=ap2=...=apm=x 且 m>n/2(0<=pk<n,1<=k<=m)，则称x为A的主元素
	例如A={0,5,5,3,5,7,5,5},则5为主元素
	又如A={0,5,5,3,5,1,5,7}，则A中没有主元素
	假设A中的n个元素保存在一个一维数组中，请找出A的主元素
	若存在，则输出该元素，否则输出-1
	（即某个在数组中重复次数占数组长度一半多的元素）
*/
//一、循环，记录每个元素出现的次数
//int selectMainElementInArrMethod_1(int arr[] , int len) {

//	for (int i = 0; i < len; i++)
//	{
//		ArrayList arrayList;
//		arrayList.data = (int)malloc(sizeof(int));
//		arrayList.count = 0;
//	}
//
//	return 0;
//}

//二、书上答案：从前往后扫描数组，找出一个可能成为主元素的值，然后重新计数
//		即：从arr[0]开始，将其作为候选，count=1，如果arr[0]的值再次出现则count+1，不出现则count-1，若count==0，则更换候选值
int standeredAnswer_11(int arr[] , int len) {
	//int len = sizeof(arr) / sizeof(int);//数组作为参数传递时，以指针变量的形式传递，传递的是数组的首地址，应在函数调用前计算长度，将长度作为参数传递
	printf("len = %d\n", len);
	int candidate = arr[0];
	int count = 1;
	for (int i = 0; i < len; i++)
	{
		printf("candidate = %d\n", candidate);
		if (arr[i] == candidate)
		{
			count++;
		}
		else {
			count--;
		}
		if (count == 0)
		{
			candidate = arr[i];
			count = 1;
		}
	}
	//检查是否为主元素，如果不是则返回-1
	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (candidate == arr[i])
		{
			count++;
		}
	}
	if (count >= len / 2)
	{
		return candidate;
	}
	else {
		return -1;
	}
}

//三、使用二维数组，遍历，将去重后的元素的数组下标作为一个维度，再将次数作为一个维度
int selectMainElementMethod_3(int arr[] , int len) {
	int twoDArr[len][len];
	for (int i = 0; i < len; i++)
	{

	}
}

//四、先排序，再遍历

//五、大学室友介绍的一种方法，觉得很好，写一下。
//		筛法：因为此题有个隐蔽条件 0<=ai<n(0<=i<n)，所以可以使用该法。
//			构造一个一维数组，值全部初始化为0。遍历目标数组，以新数组的下标对应目标数组的值，统计每个值出现的次数
//			与13题类似，此处不再写了



void main() {
	int arr[] = { 0,5,5,3,5,7,5,5,7,8,9 };
	int len = sizeof(arr) / sizeof(int);
	int result =standeredAnswer_11(arr , len);
	printf("result = %d\n", result);

}