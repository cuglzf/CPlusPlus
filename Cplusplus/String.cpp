#include "String.h"


/*
剑指offer面试题5
将一个字符串中的空格全部替换成%20
string：存放要替换的字符串，数组足够长，length数组的长度（不是字符串的长度）
思路：这个算法要求是不申请额外内存，因此必须原数组足够大，
1、首先统计有多少个空格，然后计算出替换后字符串长度（包括\0）
2、从字符串的结尾开始往前遍历，遇到空格就替换成%20，如果不是
空格，则直接复制
*/
void ReplaceBlack(char string[], int length)
{
	//安全检查
	if (string == nullptr || length <= 0)
		return;
	//统计空格个数
	int originLen = 0;
	int numberOfBlack = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++originLen;
		if (string[i] == ' ')
			++numberOfBlack;
		++i;
	}
	
	//这里的newLen不包含结束符
	int newLen = originLen + 2 * numberOfBlack;
	//安全检查
	if (newLen > length)
		return;
	//移动
	int j = newLen;
	while (i >= 0 && j >= i)
	{
		if (string[i] == ' ')
		{
			string[j--] = '0';
			string[j--] = '2';
			string[j--] = '%';
		}
		else
		{
			string[j--] = string[i];
		}
		--i;
	}

}