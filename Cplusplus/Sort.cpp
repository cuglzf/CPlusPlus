#include "Sort.h"

/*
��������
�ȶ��ԣ����ȶ�
ʱ�临�Ӷȣ�O(nlogn) O(nlogn) O(n2)
�ռ临�Ӷȣ�O(nlogn)~O(n)
˼·��
ѡȡһ���Ƚ�Ԫ�أ�һ����������Ԫ����ߵĶ�����С���ұߵĶ�������
Ȼ�������ֿ��Էֱ�����
���裺
1��ѡȡ��һ��Ԫ��x��Ϊ�Ƚ�Ԫ��
2���ȴӺ���ǰ�Ƚϣ��������x��j--������Ԫ���Ƶ�ǰ��
3���ڴ�ǰ����Ƚϣ����С��x��i++������Ԫ���Ƶ�����
4������i==j����x��������������±�
*/
void QuickSort(int data[], int low, int high)
{
	if (data == nullptr || low == high)
		return;
	int index = Partition(data, low, high);
	if (index > low)
		QuickSort(data, low, index - 1);
	if (index < high)
		QuickSort(data, index + 1, high);
}

int Partition(int data[], int low, int high)
{
	//ѡȡ��һ����Ϊ�Ƚ�Ԫ��
	int x = data[low];
	int i = low;
	int j = high;
	while (i < j)
	{
		//�����j��ָԪ�ش�j--
		while (data[j] >= x && i < j)
			j--;
		data[i] = data[j];

		//�����i��ָԪ��С��i++
		while (data[i] <= x && i < j)
			i++;
		data[j] = data[i];
	}
	//���Ƚ�Ԫ�������õ�λ����
	data[i] = x;
	return i;
}