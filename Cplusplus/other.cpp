#include "other.h"
#include <iostream>

using namespace std;

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
C语言库函数之memcpy函数实现
注意事项：
1、空指针，dest或src任意一个为空则结束
2、count为0，返回
3、内存重叠时,如果还是采用从前往后的方法，有一种情况会出现问题，就是当dest在[src,src+count）内
如果此时仍然从前往后复制，那么一定会出现复制不是用户想要的，此时应该采用从后往前复制。
这里的count为什么不用size_t，因为size_t是unsigned int型，当传入一个-1时，将会是一个非常大
的数字
C语言库函数中是没有考虑内存重叠那种情况的，memmove是考虑了的，因此下面这个MemoryCopy可以用作
memcpy和memmove
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

	//如果pDest在[pSrc,pSrc+count-1}之间，需要从后往前复制
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
C语言库函数之strcpy
这个是字符串拷贝函数，要考虑到内存重叠情况，因此和memecpy差不多
*/

char *Strcpy(char *dest, const char *src)
{
	if (dest == nullptr || src == nullptr || dest == src)
		return dest;

	char *pDest = dest;

	//没有考虑地址重叠
	while (*src != '\0')
		*dest++ = *src++;

	//记得末尾一定置为\0
	dest = '\0';

	//这里一定不能直接返回dest，因为dest最后指向字符串的尾
	//返回的是\0
	return pDest;
}