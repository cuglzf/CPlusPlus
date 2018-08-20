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
	if (data == nullptr || low >= high)
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
		while (i < j && data[j] >= x )
			j--;
		if (i < j)
			data[i++] = data[j];

		//�����i��ָԪ��С��i++
		while (i < j && data[i] <= x)
			i++;
		if (i < j)
			data[j--] = data[i];
	}
	//���Ƚ�Ԫ�������õ�λ����
	data[i] = x;
	return i;
}

/*
������
�ȶ��ԣ����ȶ�
ʱ�临�Ӷȣ�O(nlogn) O(nlogn) O(nlogn)
�ռ临�Ӷȣ�O(nlogn)~O(n)
˼·��
������������������Ϊ��
1����ʼ���ѣ�������a[1...n]�����һ������
2���������ݣ���a[1]��a[n]��������ʱa[n]��a[1...n]�е����ֵ��Ȼ��a[1...n-1]���µ���Ϊ���ѡ�
���Ž�a[1]��a[n-1]������a[n-1]��a[1...n-1]�е����ֵ���Դ����ƣ�ֱ���������ж�������ġ�
��μ���ڵ�i�����ӡ��Һ��Ӻ͸��ڵ㣬��������Ϊi�Ľڵ�
���ӣ���2*i+1��
�Һ��ӣ���2*i+2��
���ڵ㣺��i-1��/2����ȡ��
*/
void HaepSort(int data[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		MaxHeapDown(data, i, n - 1);
}


/*
���ѵ����µ����㷨
����˵����
data�������������
start�����µ��ڵ����ʼλ��
end����ֹ��Χ
*/
void MaxHeapDown(int data[], int start, int end)
{

}