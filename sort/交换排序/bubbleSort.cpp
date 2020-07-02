#include <iostream>
using namespace std;
// 持续比较相邻元素，大的挪后面 
int main(){
	int a[] = {6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	int m = len - 1, flag = 1;
	while((m > 0) && (flag == 1)){
		// 全部有序 
		flag = 0;
		// 每次从头遍历，后边位置固定的就不再处理 
		for(int i = 1; i <= m; i++){
			// 与后一个比较，大则交换 
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
