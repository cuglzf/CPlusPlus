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
	//选取第一个作为比较元素
	int x = data[low];
	int i = low;
	int j = high;
	while (i < j)
	{
		//如果比j所指元素大，j--
		while (i < j && data[j] >= x )
			j--;
		if (i < j)
			data[i++] = data[j];

		//如果比i所指元素小，i++
		while (i < j && data[i] <= x)
			i++;
		if (i < j)
			data[j--] = data[i];
	}
	//将比较元素最后放置到位置上
	data[i] = x;
	return i;
}

/*
堆排序：
稳定性：不稳定
时间复杂度：O(nlogn) O(nlogn) O(nlogn)
空间复杂度：O(nlogn)~O(n)
思路：
这里以最大堆升序排序为例
1）初始化堆：将数组a[1...n]构造成一个最大堆
2）交换数据：将a[1]和a[n]交换，此时a[n]是a[1...n]中的最大值；然后将a[1...n-1]重新调整为最大堆。
接着将a[1]和a[n-1]交换，a[n-1]是a[1...n-1]中的最大值，以此类推，直到整个数列都是有序的。
如何计算节点i的左孩子、右孩子和父节点，例如索引为i的节点
左孩子：（2*i+1）
右孩子：（2*i+2）
父节点：（i-1）/2向下取整
*/
void HaepSort(int data[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		MaxHeapDown(data, i, n - 1);
}


/*
最大堆的向下调整算法
参数说明：
data：待排序的数据
start：被下调节点的起始位置
end：截止范围
*/
void MaxHeapDown(int data[], int start, int end)
{

}