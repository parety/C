#include <stdio.h>
#define MaxSize 10 //�궨����û�зֺ�
/*
	sizeof(ElemType) ��ȡһ������Ԫ�صĴ�С
		sizeof(int) = 48
*/
//˳���̬����

typedef struct {
	int data[MaxSize];
	int length;
}SqList;
//��ʼ��һ��˳���
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
	˳���̬����
*/
typedef struct {
	int* data; //ָ��ָ��˳����еĵ�һ��Ԫ��
	int size; //�������
	int currentLength; //��ǰ����
}ArrayList;

// L.data = (ElemType*)malloc(sizeof(ElemType) * initsize);

void main() {
	SqList * l = new SqList;
	initSqList2(l);
	printf("data[0] = %d", l->data[0]);
	//initSqList(l);

}