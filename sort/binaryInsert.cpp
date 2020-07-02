#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //数组从第二位开始, 第一位[0]为暂存单元
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		// 要比较的数放入缓存 
		a[0] = a[i];
		// 找到有序序列中的中位数，与缓存中的数比较 
		int low = 1, high = i - 1;
		while(low <= high){
			int mid = (low + high) / 2;
			// 如果有序序列中要比较的数据，大于缓存中的数据，则重新定位有序序列的中位数 
			if(a[0] < a[mid]) high = mid - 1; 
			else low = mid + 1;
		}
		// 上边找到了数据要放入的区间
		// 将有序序列中的数据从后往前后移一位 
		for(int j = i - 1; j >= high + 1; j--)
			a[j + 1] = a[j];
		// 每次循环确定一个位置 
		a[high + 1] = a[0];
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
