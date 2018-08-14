#include "other.h"
#include <iostream>

using namespace std;

/*
�жϻ����Ĵ洢ģʽ����˷���0��С�˷���1
*/
int checkSystem()
{
	union check
	{
		int i;
		char ch;
	}c;
	c.i = 1;
	return (c.ch == 1);
}

/*
C���Կ⺯��֮memcpy����ʵ��
ע�����
1����ָ�룬dest��src����һ��Ϊ�������
2��countΪ0������
3���ڴ��ص�ʱ,������ǲ��ô�ǰ����ķ�������һ�������������⣬���ǵ�dest��[src,src+count����
�����ʱ��Ȼ��ǰ�����ƣ���ôһ������ָ��Ʋ����û���Ҫ�ģ���ʱӦ�ò��ôӺ���ǰ���ơ�
�����countΪʲô����size_t����Ϊsize_t��unsigned int�ͣ�������һ��-1ʱ��������һ���ǳ���
������
C���Կ⺯������û�п����ڴ��ص���������ģ�memmove�ǿ����˵ģ�����������MemoryCopy��������
memcpy��memmove
*/
void *MemoryCopy(void *dest, void *src, int count)
{
	if (dest == nullptr || src == nullptr || count <= 0)
	{
		return nullptr;
	}
	unsigned char *pDest = (unsigned char *)dest;
	const unsigned char *pSrc = (const unsigned char *)src;

	int flag = (pDest >= pSrc && pDest < pSrc + count);

	//���pDest��[pSrc,pSrc+count-1}֮�䣬��Ҫ�Ӻ���ǰ����
	if (flag)
	{
		pDest = (unsigned char*)dest + count - 1;
		pSrc = (const unsigned char *)src + count - 1;
		while (count--)
			*pDest-- = *pSrc--;
	}
	else
	{
		while (count--)
		{
			*pDest++ = *pSrc++;
		}
	}

	return pDest;
}

/*
C���Կ⺯��֮strcpy
������ַ�������������Ҫ���ǵ��ڴ��ص��������˺�memecpy���
*/

char *Strcpy(char *dest, const char *src)
{
	if (dest == nullptr || src == nullptr || dest == src)
		return dest;

	char *pDest = dest;

	//û�п��ǵ�ַ�ص�
	while (*src != '\0')
		*dest++ = *src++;

	//�ǵ�ĩβһ����Ϊ\0
	dest = '\0';

	//����һ������ֱ�ӷ���dest����Ϊdest���ָ���ַ�����β
	//���ص���\0
	return pDest;
}