#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //����ӵڶ�λ��ʼ,��һλ[0]Ϊ�ݴ浥Ԫ��temp 
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		// �����һλС��ǰһλ����Ѻ�һλ�����Ž����棬ǰһλ��������һλ 
		if(a[i] < a[i - 1]){
			a[0] = a[i];
			a[i] = a[i - 1];
			// �û����е����ݼ�����ǰ�Ƚϣ�������ڻ����е����ݣ�����ƣ�ֱ��С�ڻ���ڻ����е����ݣ����һλ��Ϊ�����е����ݸô����λ�� 
			int j = i - 2;
			while(a[0] < a[j]){
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1 ] = a[0];
		}
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
