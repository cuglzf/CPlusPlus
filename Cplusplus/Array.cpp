#include "Array.h"
#include <stdexcept>


/*
��ָoffer������3��
��һ������Ϊn���������������ֶ���0~n-1֮�䣬��Щ�������ظ��ģ�����������һ���ظ�������
˼·��
1������������Ȼ���ͷ�������ɣ�ʱ�临�Ӷ�O(n)
2�����ù�ϣ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
3����Ϊÿ�����ֶ���0~n-1�����û���ظ������������±�һһ��Ӧ�����˼·���ǽ����ֻ�ԭ����Ӧ
���±��У���ô������ظ�����ԭ��ʱ��ᷢ���Ѿ������±��Ӧ��Ԫ���ˣ���������־��ظ���
*/
/*
���裺
1���ж������Ƿ����
2����������е�Ԫ���Ƿ���ȷ
3�����±�Ϊindex=0��ʼ��λ��������,
3.1 ���number[index]������index���������Ҫ��λ�����ж�����λ��λ���Ƿ��Ѿ�������ȷ������
�����λ��λ���Ѿ�������ȷ�����֣�������ظ�������
3.2 ���number[index]����index����index+1������һλ��ʼ
4������false�����ظ�
*/
//ͨ��deplication�����ظ������֣����������Ƿ����ظ�������
bool duplicate(int numbers[], int length, int *deplication)
{
	//1�������ж������Ƿ����
	if (length < 1 || numbers == nullptr)
		return false;

	//2���ж������Ƿ�Ϸ�
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	//3����numbers[0]��ʼ��λ��������
	int index = 0;
	while (index < length)
	{
		int currentNumber = numbers[index];
		//��������±������������ֲ�ͬ
		if (currentNumber != index)
		{
			//�������������ж���Ҫ�������ĵط��Ƿ��Ѿ�������ȷ�������ˣ�
			//������ڣ���ô������־����ظ��ģ��˳�
			if (numbers[currentNumber] == currentNumber)
			{
				*deplication = numbers[currentNumber];
				return true;
			}
			//���򣬵�����������
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
��ָoffer������4
��һ�������Ҵ��ϵ��¶��ǵ����Ķ�ά�����У�����һ������
˼·��ÿ���������Ͻ�Ԫ�رȽϣ��������Ͻ�Ԫ�ش����ʾ����Ԫ�ؿ�����
���У���������Ͻ�Ԫ��С�����ʾ�������С����ҽ������������ǵ��Ƚϵ����һ��
����һ����Ȼû���ҵ������ʾ�Ҳ����ˡ�
�����Ŀѡȡ�ıȽ�Ԫ�ؿ��Դ����Ͻǻ������½ǿ�ʼ���������Ϻ����²���
����һ��˼�����ܲ���ÿ��ѡȡ�м�����ֱȽϣ������Ļ�������ַ������Ƚϴ�������
һ��
*/
bool FindInMatrix(int *matrix, int rows, int columns, int number)
{
	bool found = false;
	//�����Ƿ����
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
��ָoffer������11 ��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�������ĩβ���ҳ����������Сֵ
˼·��
��Ϊ��ת������Է�Ϊ�����֣�ÿһ���ֶ��ǵ�������ģ���˿���ʹ��
���ַ����ң�ȡ�м��Ԫ�غ����˵ıȽϣ��Ӷ�ȷ����Сֵ��ǰ���������
�����ں���������У���������м��Ԫ����ǰ������Ԫ��һ������ʱ�޷�
�ж���Сֵ����ǰ�����л����ں������У����ֻ��˳������ˡ���������
�Ľ���������ǰ��ָ��ͺ���ָ�����1��Ҳ����ǰ��ָ��ָ��ǰ���е����
һ��Ԫ�أ����������е����Ԫ�أ�������ָ��ָ������еĵ�һ��Ԫ��
�����������е���СԪ�أ�����˷��غ������±��е�Ԫ�ؼ��ɡ�
*/
int Min(int *numbers, int length)
{
	if (numbers == nullptr || length < 1)
		throw std::exception("invalid input");

	int i = 0;
	int j = length - 1;
	int mid = 0;

	//��֤ǰָ��ʼ����ǰ������У���ָ��ʼ���ں��������
	//���⣬�������������˳�����еģ���ʱֱ�ӷ����ˡ�
	while (numbers[i] >= numbers[j])
	{
		//�ж��Ƿ�ý�����
		if (j - i == 1)
		{
			mid = j;
			break;
		}
		mid = (i + j) / 2;

		//���i,j,mid������ֵ����ȣ���ʱ�޷��ж���Сֵ��ǰ�������
		//�����ں�������У�ֻ��˳�����
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
��ָoffer������12 �����е�·��
�ж�һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·���ɴӾ�������һ��ʼ��
ÿһ�������ھ����������������ƶ�һ�����һ��·�������˾����ĳһ����ô��·��
�����ٴν���ø��ӡ�
ͼ��·���������⣬���͵�ʹ�û��ݷ�����ʵ��ϸ�����ݷ����㷨����Ч�ʲ����ߣ��൱��
��٣����ǣ�������������˼·��
����˼·��
�Ӿ����һ��Ԫ�ؿ�ʼ����������һ��Ԫ���Ƿ����ַ����еĵ�һ���ַ�Ȼ�����α���������
�㷨�����ڵݹ���ã�ÿ�������һ�������Ƿ������ʱ�򣬵ݹ��������Χ4������ĸ���
�Ƿ������������ģ���������κ�һ�������������������ʾ�ҵ���һ��·����
���㷨�ľ���ϸ����Ҫע�����¼�������
1����ά���龡��ʹ��һά��ʾ
2���ж�Ԫ���Ƿ��Ѿ���������������һ����ԭ����һ����С�ı�־���飬���ʹ�����Ϊ1��δ���ʹ�����Ϊ0
3���ݹ��㷨�Ľ������������ַ��������Ѿ�������ɣ������������Ժ������ݹ�����еķ��أ�����
һ���������㷨Ҫ���ظ����յĵ����ߡ�
4��һ���ǵ���return��ʱ���ͷ��ڴ档
*/
bool HasPath(char *matrix, int rows, int columns, char *str)
{
	//�߽���
	if (matrix == nullptr || rows < 1 || columns < 1 || str == nullptr)
		return false;

	//����һ����������װԪ���Ƿ��Ѿ���������
	bool *visited = new bool[rows*columns];
	memset(visited, 0, rows*columns);

	//��¼�Ѿ�ƥ����ַ�����
	int pathLength = 0;

	//�Ӿ���ĵ�һ��Ԫ�ؿ�ʼѰ·
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
	//�����������ַ����Ѿ�������
	if (str[pathLength] == '\0')
		return true;
	//��ǵ�(row,column)���ܷ���
	bool hasPath = false;

	//����ڣ�row,column�������ַ�����pathLength-1���ַ�
	if (row > 0 && row < rows && column > 0 && column < columns 
		&& matrix[columns*row+column] == str[pathLength] && !visited[columns*row+column])
	{
		//��������һ���ַ������ѵ�ǰ���ӱ��Ϊ�ѷ���
		++pathLength;
		visited[columns*row + column] = true;
		//�ֱ���Ѱ���������Ҹ��ӣ�������һ���������㼴��
		hasPath = HasPathCore(matrix, rows, columns, row - 1, column, str, pathLength, visited) ||
			HasPathCore(matrix, rows, columns, row + 1, column, str, pathLength, visited) ||
			HasPathCore(matrix, rows, columns, row, column - 1, str, pathLength, visited) ||
			HasPathCore(matrix, rows, columns, row, column + 1, str, pathLength, visited);

		//���û���ҵ�
		if (!hasPath)
		{
			//���˵���ǰ�ַ�������������Ϊδ����
			--pathLength;
			visited[columns*row + column] = false;
		}
	}

	return hasPath;
}