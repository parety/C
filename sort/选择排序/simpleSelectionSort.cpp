#include <iostream>
using namespace std;
// ÿһ�˴Ӵ���������ѡ���ؼ�����С��Ԫ�أ���˳������������е����ֱ������ 
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7};  //Ϊ�˺ͽ̲�һ�£�����ӵ�1λ��ʼ
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 1; i < len; i++){   
		int k = i;
		for(int j = i + 1; j < len; j++){
			if(a[j] < a[k]) k = j;
		}
		if(k != i){
			int temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
