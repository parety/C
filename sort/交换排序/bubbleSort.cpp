#include <iostream>
using namespace std;
// �����Ƚ�����Ԫ�أ����Ų���� 
int main(){
	int a[] = {6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	int m = len - 1, flag = 1;
	while((m > 0) && (flag == 1)){
		// ȫ������ 
		flag = 0;
		// ÿ�δ�ͷ���������λ�ù̶��ľͲ��ٴ��� 
		for(int i = 1; i <= m; i++){
			// ���һ���Ƚϣ����򽻻� 
			if(a[i - 1] > a[i]){
				flag = 1;
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
		}
		m--;
	}
	for(int i = 0; i < len; i++)
		cout << a[i];
	return 0;
}
