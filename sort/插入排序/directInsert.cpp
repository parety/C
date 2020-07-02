#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //数组从第二位开始,第一位[0]为暂存单元，temp 
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		// 如果后一位小于前一位，则把后一位的数放进缓存，前一位的数后移一位 
		if(a[i] < a[i - 1]){
			a[0] = a[i];
			a[i] = a[i - 1];
			// 拿缓存中的数据继续往前比较，如果大于缓存中的数据，则后移，直到小于或等于缓存中的数据，则后一位即为缓存中的数据该存入的位置 
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
