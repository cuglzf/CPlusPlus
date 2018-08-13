#include "other.h"

/*
判断机器的存储模式，大端返回0，小端返回1
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
memcpy函数实现
注意事项：
1、空指针，dest或src任意一个为空则结束
2、count为0，返回
3、内存不能重叠,如果dest和src内存重叠，什么意思？就是src在[dest,dest+count)内或者
dest在[src,src+count)内，这样就是一个大内存中的内容拷贝到小内存中，拷贝是不合要求的，
因此需要结束。
这里的count为什么不用size_t，因为size_t是unsigned int型，当传入一个-1时，将会是一个非常大
的数字
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

	//如果pDest和pSrc有重叠
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