#include <iostream>
using namespace std;
// 冒泡的改进：
	// 通过一趟排序，将待排序列的数据分割成两部分，左大右小（或左小右大），再按此方法对两部分数据分别进行快排，递归进行 
void quickSort(int list[], int low, int high)
{
	if(low < high){
		// 待排序列中的第一个元素作为枢纽 
		list[0] = list[low];
		int key = list[low];
		int left = low, right = high; 
		while(low < high){
			// 从表的最右侧依次向左搜索，找到第一个小于关键字的记录，将其移到low处
			while(low < high && list[high] >= key) high--;
			list[low] = list[high];
			// 再从左向右依次搜索第一个大于关键字的记录，将其移到此时的high处
			while(low < high && list[low] <= key) low++;
			list[high] = list[low];
			// 重复以上，直到low==high，此时 此位置即关键字的最终位置，原表被分为两个子表。
		}
		// 对左右子表递归执行以上操作。
		list[low] = list[0];
		quickSort(list,left,low-1);
		quickSort(list, low+1, right);
	}
}
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	quickSort(a, 1, len - 1);
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
