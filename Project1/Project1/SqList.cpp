#include <stdio.h>
#define MaxSize 10 //宏定义后边没有分号
/*
	sizeof(ElemType) 获取一个数据元素的大小
		sizeof(int) = 48
*/
//顺序表静态分配

typedef struct {
	int data[MaxSize];
	int length;
}SqList;
//初始化一个顺序表
void initSqList(SqList &list) {
	for (int i = 0; i < MaxSize; i++)
	{
		list.data[i] = 0;
	}
	list.length = 0;
}
void initSqList2(SqList * list) {
	for (int i = 0; i < MaxSize; i++)
	{
		list->data[i] = 0;
	}
	list->length = 0;
}

/*
	顺序表动态分配
*/
typedef struct {
	int* data; //指针指向顺序表中的第一个元素
	int size; //最大容量
	int currentLength; //当前长度
}ArrayList;

// L.data = (ElemType*)malloc(sizeof(ElemType) * initsize);

void main() {
	SqList * l = new SqList;
	initSqList2(l);
	printf("data[0] = %d", l->data[0]);
	//initSqList(l);

}