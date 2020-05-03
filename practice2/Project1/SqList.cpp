#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc free , 有malloc 就有free
#define MaxSize 10 //宏定义后边没有分号
#define InitSize 20
/*
	sizeof(ElemType) 获取一个数据元素的大小
		sizeof(int) = 48
	 L.data = (ElemType*)malloc(sizeof(ElemType) * initsize);
		malloc函数返回一片连续的内存空间的起始地址
*/
//顺序表静态分配
typedef struct {
	int data[MaxSize];
	int length;
}SqList;
//初始化
void initSqList(SqList &list) {
	for (int i = 0; i < MaxSize; i++)
	{
		list.data[i] = i;
	}
	list.length = MaxSize;
}
//插入
void addElementSqList(SqList& list,int i ,  int e) {
	if (i > MaxSize || i < 0)
	{
		return;
	}
	//将i之后的元素后移一位
	for (int j = list.length; j > i; j--)
	{
		list.data[j] = list.data[j - 1];
	}
	list.data[i - 1] = e;
	list.length ++;
}

/*
	顺序表动态分配
*/
typedef struct {
	int* data; //指针指向顺序表中的第一个元素
	int size; //最大容量
	int currentLength; //当前长度
}ArrayList;
//初始化
void initArrayList(ArrayList& list) {
	list.data = (int*)malloc(sizeof(int) * InitSize);
	list.currentLength = 0;
	list.size = MaxSize;
}
//扩容
void increaseArrayList(ArrayList& list, int length) {
	int *p = list.data;
	//list.data = (int *)malloc(sizeof(int) * (MaxSize + length));
	for (int i = 0; i < list.currentLength; i++)
	{
		list.data[i] = p[i];
	}
	list.size = MaxSize + length;
	free(p);
}

//插入操作
void addElementArrayList(ArrayList& list, int e) {

}

//void main() {
//	//sqlist
//	SqList l;
//	initSqList(l);
//	printf("l.data[0] = %d\n", l.data[0]);
//	addElementSqList(l, 2, 10);
//	printf("l.length = %d\n", l.length);
//	for (int i = 0; i < MaxSize; i++)
//	{
//		printf("data[i] = %d\n", l.data[i]);
//	}
//	printf("l.length = %d\n", l.length);
//
//
//	//arraylist
//	ArrayList list;
//	initArrayList(list);
//	printf("arrayList.size = %d\n", list.size);
//	increaseArrayList(list, 10);
//	printf("arrayList.size = %d", list.size);
//
//}