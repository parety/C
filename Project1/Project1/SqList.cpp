#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc free , ��malloc ����free
#define MaxSize 10 //�궨����û�зֺ�
#define InitSize 20
/*
	sizeof(ElemType) ��ȡһ������Ԫ�صĴ�С
		sizeof(int) = 48
	 L.data = (ElemType*)malloc(sizeof(ElemType) * initsize);
		malloc��������һƬ�������ڴ�ռ����ʼ��ַ
*/
//˳���̬����
typedef struct {
	int data[MaxSize];
	int length;
}SqList;
//��ʼ��
void initSqList(SqList &list) {
	for (int i = 0; i < MaxSize; i++)
	{
		list.data[i] = i;
	}
	list.length = MaxSize;
}
//����
void addElementSqList(SqList& list,int i ,  int e) {
	if (i > MaxSize || i < 0)
	{
		return;
	}
	//��i֮���Ԫ�غ���һλ
	for (int j = list.length; j > i; j--)
	{
		list.data[j] = list.data[j - 1];
	}
	list.data[i - 1] = e;
	list.length ++;
}

/*
	˳���̬����
*/
typedef struct {
	int* data; //ָ��ָ��˳����еĵ�һ��Ԫ��
	int size; //�������
	int currentLength; //��ǰ����
}ArrayList;
//��ʼ��
void initArrayList(ArrayList& list) {
	list.data = (int*)malloc(sizeof(int) * InitSize);
	list.currentLength = 0;
	list.size = MaxSize;
}
//����
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

//�������
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