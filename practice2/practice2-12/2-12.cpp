#include <stdio.h>
#include <stdlib.h>

#define InitSize 5

typedef struct {
	int data;
	int count;
}ArrayList;


/*
	��֪һ����������A=(a0,a1,...,an-1),����0<=ai<n(0<=i<n) ****��������****
	������ap1=ap2=...=apm=x �� m>n/2(0<=pk<n,1<=k<=m)�����xΪA����Ԫ��
	����A={0,5,5,3,5,7,5,5},��5Ϊ��Ԫ��
	����A={0,5,5,3,5,1,5,7}����A��û����Ԫ��
	����A�е�n��Ԫ�ر�����һ��һά�����У����ҳ�A����Ԫ��
	�����ڣ��������Ԫ�أ��������-1
	����ĳ�����������ظ�����ռ���鳤��һ����Ԫ�أ�
*/
//һ��ѭ������¼ÿ��Ԫ�س��ֵĴ���
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

//�������ϴ𰸣���ǰ����ɨ�����飬�ҳ�һ�����ܳ�Ϊ��Ԫ�ص�ֵ��Ȼ�����¼���
//		������arr[0]��ʼ��������Ϊ��ѡ��count=1�����arr[0]��ֵ�ٴγ�����count+1����������count-1����count==0���������ѡֵ
int standeredAnswer_11(int arr[] , int len) {
	//int len = sizeof(arr) / sizeof(int);//������Ϊ��������ʱ����ָ���������ʽ���ݣ����ݵ���������׵�ַ��Ӧ�ں�������ǰ���㳤�ȣ���������Ϊ��������
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
	//����Ƿ�Ϊ��Ԫ�أ���������򷵻�-1
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

//����ʹ�ö�ά���飬��������ȥ�غ��Ԫ�ص������±���Ϊһ��ά�ȣ��ٽ�������Ϊһ��ά��
int selectMainElementMethod_3(int arr[] , int len) {
	int twoDArr[len][len];
	for (int i = 0; i < len; i++)
	{

	}
}

//�ġ��������ٱ���

//�塢��ѧ���ѽ��ܵ�һ�ַ��������úܺã�дһ�¡�
//		ɸ������Ϊ�����и��������� 0<=ai<n(0<=i<n)�����Կ���ʹ�ø÷���
//			����һ��һά���飬ֵȫ����ʼ��Ϊ0������Ŀ�����飬����������±��ӦĿ�������ֵ��ͳ��ÿ��ֵ���ֵĴ���
//			��13�����ƣ��˴�����д��



void main() {
	int arr[] = { 0,5,5,3,5,7,5,5,7,8,9 };
	int len = sizeof(arr) / sizeof(int);
	int result =standeredAnswer_11(arr , len);
	printf("result = %d\n", result);

}