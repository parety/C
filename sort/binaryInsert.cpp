#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //����ӵڶ�λ��ʼ, ��һλ[0]Ϊ�ݴ浥Ԫ
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		// Ҫ�Ƚϵ������뻺�� 
		a[0] = a[i];
		// �ҵ����������е���λ�����뻺���е����Ƚ� 
		int low = 1, high = i - 1;
		while(low <= high){
			int mid = (low + high) / 2;
			// �������������Ҫ�Ƚϵ����ݣ����ڻ����е����ݣ������¶�λ�������е���λ�� 
			if(a[0] < a[mid]) high = mid - 1; 
			else low = mid + 1;
		}
		// �ϱ��ҵ�������Ҫ���������
		// �����������е����ݴӺ���ǰ����һλ 
		for(int j = i - 1; j >= high + 1; j--)
			a[j + 1] = a[j];
		// ÿ��ѭ��ȷ��һ��λ�� 
		a[high + 1] = a[0];
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
