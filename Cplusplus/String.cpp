#include "String.h"


/*
��ָoffer������5
��һ���ַ����еĿո�ȫ���滻��%20
string�����Ҫ�滻���ַ����������㹻����length����ĳ��ȣ������ַ����ĳ��ȣ�
˼·������㷨Ҫ���ǲ���������ڴ棬��˱���ԭ�����㹻��
1������ͳ���ж��ٸ��ո�Ȼ�������滻���ַ������ȣ�����\0��
2�����ַ����Ľ�β��ʼ��ǰ�����������ո���滻��%20���������
�ո���ֱ�Ӹ���
*/
void ReplaceBlack(char string[], int length)
{
	//��ȫ���
	if (string == nullptr || length <= 0)
		return;
	//ͳ�ƿո����
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
	
	//�����newLen������������
	int newLen = originLen + 2 * numberOfBlack;
	//��ȫ���
	if (newLen > length)
		return;
	//�ƶ�
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