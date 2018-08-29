#include "Array.h"
#include <stdexcept>


/*
剑指offer面试题3：
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

/*
剑指offer面试题4
在一个从左到右从上到下都是递增的二维数组中，查找一个整数
思路：每次与最右上角元素比较，比最右上角元素大，则表示查找元素可能在
此列，如果比右上角元素小，则表示在其他列。查找结束的条件就是当比较到最后一行
或者一列仍然没有找到，则表示找不到了。
这个题目选取的比较元素可以从右上角或者左下角开始，但是左上和右下不能
还有一个思考，能不能每次选取中间的数字比较，这样的话相比这种方法，比较次数减少
一半
*/
bool FindInMatrix(int *matrix, int rows, int columns, int number)
{
	bool found = false;
	//矩阵是否存在
	if (matrix == nullptr || rows <= 0 || columns <= 0)
	{
		return found;
	}

	int row = 0;
	int column = columns - 1;
	while (row < rows && column >= 0)
	{
		if (matrix[row*rows + column] == number)
		{
			found = true;
			break;
		}
		else if (matrix[row*rows+column] > number)
		{
			--column;
		}
		else
		{
			++row;
		}
	}

	return found;
}

/*
剑指offer面试题11 旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的最末尾，找出该数组的最小值
思路：
因为旋转数组可以分为两部分，每一部分都是递增有序的，因此可以使用
二分法查找，取中间的元素和两端的比较，从而确定最小值在前面的子序列
还是在后面的子序列，但是如果中间的元素与前后两个元素一样，此时无法
判断最小值是在前子序列还是在后子序列，因此只能顺序查找了。整个查找
的结束条件是前面指针和后面指针相差1，也就是前面指针指向前序列的最后
一个元素（整个数组中的最大元素），后面指针指向后序列的第一个元素
（整个数组中的最小元素），因此返回后序列下标中的元素即可。
*/
int Min(int *numbers, int length)
{
	if (numbers == nullptr || length < 1)
		throw std::exception("invalid input");

	int i = 0;
	int j = length - 1;
	int mid = 0;

	//保证前指针始终在前面的序列，后指针始终在后面的序列
	//另外，如果整个数组是顺序排列的，此时直接返回了。
	while (numbers[i] >= numbers[j])
	{
		//判断是否该结束了
		if (j - i == 1)
		{
			mid = j;
			break;
		}
		mid = (i + j) / 2;

		//如果i,j,mid三个的值都相等，此时无法判断最小值在前面的序列
		//还是在后面的序列，只能顺序查找
		if (numbers[i] == numbers[mid] && numbers[i] == numbers[j])
			return MinInOrder(numbers, i, j);

		if (numbers[mid] >= numbers[i])
			i = mid;
		else
			j = mid;
	}
	return numbers[mid];
}

int MinInOrder(int *numbers, int i, int j)
{
	int result = numbers[i];
	for (int k = i+1; k <= j; k++)
	{
		if (result > numbers[k])
			result = numbers[k];
	}
	return result;
}

/*
剑指offer面试题12 矩阵中的路径
判断一个矩阵中是否存在一条包含某字符串所有字符的路径，路径可从矩阵任意一格开始，
每一步可以在矩阵中向上下左右移动一格，如果一条路径经过了矩阵的某一格，那么该路径
不能再次进入该格子。
图的路径搜索问题，典型的使用回溯法。其实仔细看回溯法，算法本身效率并不高，相当于
穷举，但是，简化了问题的求解思路。
本题思路：
从矩阵第一个元素开始遍历，看第一个元素是否是字符串中的第一个字符然后依次遍历，核心
算法就在于递归调用，每当检测完一个格子是否满足的时候，递归调用它周围4个方向的格子
是否有满足条件的，如果存在任何一个防线满足条件，则表示找到了一条路径。
在算法的具体细节需要注意以下几个问题
1、二维数组尽量使用一维表示
2、判断元素是否已经被遍历过，采用一个与原数组一样大小的标志数组，访问过设置为1，未访问过设置为0
3、递归算法的结束条件，当字符串数组已经遍历完成，这种情况是针对后序参与递归过程中的返回，还有
一个返回是算法要返回给最终的调用者。
4、一定记得在return的时候释放内存。
*/
bool HasPath(char *matrix, int rows, int columns, char *str)
{
	//边界检查
	if (matrix == nullptr || rows < 1 || columns < 1 || str == nullptr)
		return false;

	//申请一个数组用来装元素是否已经被遍历过
	bool *visited = new bool[rows*columns];
	memset(visited, 0, rows*columns);

	//记录已经匹配的字符个数
	int pathLength = 0;

	//从矩阵的第一个元素开始寻路
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (HasPathCore(matrix,rows,columns,i,j,str,pathLength,visited))
			{
				delete[] visited;
				return true;
			}
		}
	}

	delete[] visited;
	return false;
}

bool HasPathCore(char *matrix, int rows, int columns, int row, int column, const char *str, int &pathLength, bool *visited)
{
	//结束条件是字符串已经遍历完
	if (str[pathLength] == '\0')
		return true;
	//标记第(row,column)格能否在
	bool hasPath = false;

	//如果第（row,column）格是字符串第pathLength-1个字符
	if (row > 0 && row < rows && column > 0 && column < columns 
		&& matrix[columns*row+column] == str[pathLength] && !visited[columns*row+column])
	{
		//继续找下一个字符，并把当前格子标记为已访问
		++pathLength;
		visited[columns*row + column] = true;
		//分别再寻找上下左右格子，有任意一个格子满足即可
		hasPath = HasPathCore(matrix, rows, columns, row - 1, column, str, pathLength, visited) ||
			HasPathCore(matrix, rows, columns, row + 1, column, str, pathLength, visited) ||
			HasPathCore(matrix, rows, columns, row, column - 1, str, pathLength, visited) ||
			HasPathCore(matrix, rows, columns, row, column + 1, str, pathLength, visited);

		//如果没有找到
		if (!hasPath)
		{
			//回退到当前字符，并将格子置为未访问
			--pathLength;
			visited[columns*row + column] = false;
		}
	}

	return hasPath;
}

/*
给定一个数组，求这个数组的最大子序列和
思路：
设a[i]为和最大序列的起点，则如果a[i]是负的，那么它不可能代表最优序列的起点，
因为任何包含a[i]作为起点的子序列都可以通过a[i+1]作起点而得到改进。
*/
int MaxSubSum(int *numbers, int length)
{
	if (numbers == nullptr || length < 1)
	{
		return 0;
	}

	int sum = 0;
	int maxSum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += numbers[i];
		if (sum > maxSum)
		{
			maxSum = sum;
		}
		else if (sum < 0)
		{
			sum = 0;
		}
	}
	return maxSum;
}

/*
剑指offer面试题13：机器人的运动范围
题目：地上有一个m行n列的方格。一个机器人从坐标（0,0）的格子开始移动，它每次
可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子。
例如：当k为18时，机器人能够进入方格（35,37），因为3+5+3+7=18<=18，但不能
进入方格（35,38），因为3+5+3+8=19>18，问该机器人能够到达多少个格子？
思路：
	这个题与第12题类似，当机器人进入（i，j）格子时候判断数位之和是否满足要求，
如果可以进入（i，j）格子，在判断此格子相邻的上下左右四个格子。
*/
int MovingCount(int k, int rows, int columns)
{
	if (k < 0 || rows < 1 || columns < 1)
		return 0;

	bool *visited = new bool[rows*columns];
	for (int i = 0; i < rows*columns; i++)
	{
		visited[i] = false;
	}

	int count = MovingCountCore(k, rows, columns,0,0,visited);

	delete[] visited;
	return count;
}

int MovingCountCore(int k, int rows, int columns,int row,int column,bool *visited)
{
	int count = 0;
	if (Check(k,rows,columns,row,column,visited))
	{
		visited[row*columns + column] = true;
		count = MovingCountCore(k, rows, columns, row - 1, column, visited) +
			MovingCountCore(k, rows, columns, row + 1, column, visited) +
			MovingCountCore(k, rows, columns, row, column - 1, visited) +
			MovingCountCore(k, rows, columns, row, column + 1, visited);

	}
	return count;
}

//注意判断此时（row，column）是否在格子内，没有被访问过且位数之和<=k
bool Check(int k, int rows, int columns, int row, int column, bool *visited)
{
	if (row >= 0 && row < rows && column >= 0 && column < columns
		&& GetDigitSum(row) + GetDigitSum(column) <= k
		&& !visited[row*columns + column])
	{
		return true;
	}
	return false;
}

int GetDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

/*
剑指offer面试题15：二进制中1的个数
常规解法：
定义一个无符号的1，每次让1与n做与运算，接着把1左移一位得到2继续与n做
与运算，这样反复左移。
利用位运算：
一个数n&(n-1)等于把它最后边的一个1变成0，那它有多少个1就做多少次这样
的运算。
*/
int NumberOf1_normal(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_bit(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}