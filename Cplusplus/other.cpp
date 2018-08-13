#include "other.h"

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
memcpy����ʵ��
ע�����
1����ָ�룬dest��src����һ��Ϊ�������
2��countΪ0������
3���ڴ治���ص�,���dest��src�ڴ��ص���ʲô��˼������src��[dest,dest+count)�ڻ���
dest��[src,src+count)�ڣ���������һ�����ڴ��е����ݿ�����С�ڴ��У������ǲ���Ҫ��ģ�
�����Ҫ������
�����countΪʲô����size_t����Ϊsize_t��unsigned int�ͣ�������һ��-1ʱ��������һ���ǳ���
������
*/
void *MemoryCopy(void *dest, void *src, int count)
{
	if (dest == nullptr || src == nullptr || count <= 0)
	{
		return nullptr;
	}
	unsigned char *pDest = (unsigned char *)dest;
	const unsigned char *pSrc = (const unsigned char *)src;

	int flag1 = (pDest >= pSrc && pDest < pSrc + count);
	int flag2 = (pSrc >= pDest && pSrc < pDest + count);

	//���pDest��pSrc���ص�
	if (flag1 || flag2)
	{
		return nullptr;
	}

	while (count--)
	{
		*pDest++ = *pSrc++;
	}

	return pDest;
}