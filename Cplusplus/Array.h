
/*
剑指offer第三题：
在一个长度为n的数组里所有数字都在0~n-1之间，有些数字是重复的，请找事任意一个重复的数字
思路：
1、将数组排序，然后从头遍历即可，时间复杂度O(n)
2、利用哈希表，时间复杂度O(n)，空间复杂度O(n)
3、因为每个数字都在0~n-1与如果没有重复，则与数组下标一一对应，因此思路就是将数字还原到对应
的下标中，那么如果有重复，则还原的时候会发现已经有与下标对应的元素了，则这个数字就重复了
*/
/*
步骤：
1、判断数组是否存在
2、检查数组中的元素是否正确
3、从下标为index=0开始归位各个数字,
  3.1 如果number[index]不等于index，则此数字要归位，需判断它归位的位置是否已经存在正确的数字
      如果归位的位置已经存在正确的数字，则存在重复的数字
  3.2 如果number[index]等于index，则index+1，从下一位开始
4、返回false，无重复
*/
//通过deplication返回重复的数字，函数返回是否有重复的数字
bool duplicate(int numbers[], int length, int *deplication)
{
	//1、首先判断数组是否存在
	if (length < 1 || numbers == nullptr)
		return false;

	//2、判断数组是否合法
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	//3、从numbers[0]开始归位各个数字
	int index = 0;
	while (index < length)
	{
		int currentNumber = numbers[index];
		//如果数组下标与数组中数字不同
		if (currentNumber != index)
		{
			//被调换的数字判断它要被调换的地方是否已经存在正确的数字了，
			//如果存在，那么这个数字就是重复的，退出
			if (numbers[currentNumber] == currentNumber)
			{
				*deplication = numbers[currentNumber];
				return true;
			}
			//否则，调换两个数字
			int temp = numbers[currentNumber];
			numbers[currentNumber] = currentNumber;
			numbers[index] = temp;
		}
		else
			++index;
	}

	return false;
}