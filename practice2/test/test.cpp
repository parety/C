#include <stdio.h>


#define N	8

int func(int arr[], int n)
{
	int temp_arr[N];

	/* ��ʼ�� */
	for (int i = 0; i < n; ++i)
	{
		temp_arr[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		++temp_arr[arr[i]];
		printf("temp_arr[%d] = %d\n", i, temp_arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		if (temp_arr[i] > n / 2)
			return i;
	}

	return -1;
}

/*
//���򵥵�д��
int func(int arr[], int n)
{
	int temp_arr[n];

	//��ʼ��
	for(int i=0; i<n; ++i)
	{
		temp_arr[i] = 0;
	}

	for(int i=0; i<n; ++i)
	{
		++temp_arr[arr[i]];

		if(temp_arr[i] > n/2)
			return i;
	}

	return -1;
}

*/

int main()
{
	int A[N] = { 0, 5, 5, 3, 5, 7, 5, 5 };

	/* ���� */

	printf("result: %d\n", func(A, N));

	return 0;
}
