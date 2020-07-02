#include <iostream>
using namespace std;
// ð�ݵĸĽ���
	// ͨ��һ�����򣬽��������е����ݷָ�������֣������С������С�Ҵ󣩣��ٰ��˷��������������ݷֱ���п��ţ��ݹ���� 
void quickSort(int list[], int low, int high)
{
	if(low < high){
		// ���������еĵ�һ��Ԫ����Ϊ��Ŧ 
		list[0] = list[low];
		int key = list[low];
		int left = low, right = high; 
		while(low < high){
			// �ӱ�����Ҳ����������������ҵ���һ��С�ڹؼ��ֵļ�¼�������Ƶ�low��
			while(low < high && list[high] >= key) high--;
			list[low] = list[high];
			// �ٴ�����������������һ�����ڹؼ��ֵļ�¼�������Ƶ���ʱ��high��
			while(low < high && list[low] <= key) low++;
			list[high] = list[low];
			// �ظ����ϣ�ֱ��low==high����ʱ ��λ�ü��ؼ��ֵ�����λ�ã�ԭ����Ϊ�����ӱ�
		}
		// �������ӱ�ݹ�ִ�����ϲ�����
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
