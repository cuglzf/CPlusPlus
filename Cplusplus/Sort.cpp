#include "Sort.h"

/*
快速排序：
稳定性：不稳定
时间复杂度：O(nlogn) O(nlogn) O(n2)
空间复杂度：O(nlogn)~O(n)
思路：
选取一个比较元素，一遍排序后，这个元素左边的都比它小，右边的都比它大，
然后左右又可以分别排序
步骤：
1、选取第一个元素x作为比较元素
2、先从后往前比较，如果大于x，j--，否则将元素移到前面
3、在从前往后比较，如果小于x，i++，否则将元素移到后面
4、最终i==j，将x放入进来，返回下标
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
	//选取第一个作为比较元素
	int x = data[low];
	int i = low;
	int j = high;
	while (i < j)
	{
		//如果比j所指元素大，j--
		while (data[j] >= x && i < j)
			j--;
		data[i] = data[j];

		//如果比i所指元素小，i++
		while (data[i] <= x && i < j)
			i++;
		data[j] = data[i];
	}
	//将比较元素最后放置到位置上
	data[i] = x;
	return i;
}