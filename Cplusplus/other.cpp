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

/*
C语言库函数之strcmp
这个是字符串比较函数，如果s1==s2，返回0；如果s1>s2返回正数；如果s1<s2返回负数
重点在while循环中，除了计算src和dest值的差值，另外要判断其中一个是否结束
*/
int Strcmp(const char *src, const char *dest)
{
	if (src == dest)
		return 0;

	int ret = 0;

	//这里一定要判断src或dest中是否有一个为\0
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dest) && *dest)
	{
		++src;
		++dest;
	}

	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;

	return ret;
}

/*
C语言库函数之memset
这个将一块内存全部设置为指定值
memset使用注意事项：
1、int型数组除了初始化为0和-1外，其他的值都不行，为什么？看下面的实现，memset是一个字节
一个字节赋值的，如果初始化为除了0和-1以外的其它值，拿1来说，当把1转为char时，取低8位，也就是
0x01，然后将0x01赋值给4个字节（int型这里占用4个字节），赋值完成后就是0x01010101，因此会出现
16843009。为什么0和1赋值可以，0就不用说了吧，0的反码、补码、原码都是其自身，而-1转换成补码取
低8位是0x11，存入一个字节内存中就是0x11，然后读出来发现是负数，因此变成补码形式就是-1，所以没变
2、用memset来初始化结构体是最快捷的方法。
*/
void *Memset(void *dst, int ch, int count)
{
	if (dst == nullptr || count <= 0)
		return nullptr;

	char *pDst = (char *)dst;
	while (count--)
		*pDst++ = (char)ch;

	return dst;
}

/*
C语言库函数之atoi
这个函数是将字符串转换成整数
这个函数能跳过开头的空格，遇到一个非要计算的字符就结束
改进后的atoi可以计算十进制和十六进制，可计算正负
存在问题：如果字符串过长，转换后的数字超过int范围，这个需要检测
*/
int Atoi(const char *nptr)
{
	if (nptr == nullptr)
		return 0;

	//跳过空格
	while (*nptr == ' ')
	{
		++nptr;
	}

	//正负标记
	int flag = 1;
	int ret = 0;
	if (*nptr == '-')
	{
		flag = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		flag = 1;
		nptr++;
	}

	//判断是否是16进制
	if (*nptr == '0' && *(nptr+1) == 'x' )
	{
		++++nptr;
		while (*nptr != '\0')
		{
			if (*nptr >= '0' && *nptr <= '9')
			{
				ret = ret * 16 + (*nptr - '0');
			}
			else if (*nptr >= 'a' && *nptr <= 'f')
			{
				ret = ret * 16 + 10 + (*nptr - 'a');
			}
			else
			{
				return ret*flag;
			}
			++nptr;
		}
	}

	//计算
	while (*nptr != '\0')
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			//这里一定不能忘记nptr++，不然死循环
			ret = ret * 10 + (*nptr++ - '0');
		}
		else
		{
			return ret*flag;
		}
	}
	return ret == 0 ? 0 : ret*flag;
}

/*
C语言库函数之atof
此函数将字符串转成浮点型
*/

double Atof(const char *nptr)
{
	double ret = 0.0;
	int flag = 1;
	if (nptr == nullptr)
		return ret;

	//跳过前面的所有空格
	while (*nptr == ' ')
		++nptr;

	if (*nptr == '-')
	{
		flag = -1;
		++nptr;
	}
	else if (*nptr == '+')
	{
		flag = 1;
		++nptr;
	}

	while (*nptr != '\0')
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			ret = ret * 10 + (*nptr - '0');
		}
		else
			break;
		++nptr;
	}

	//如果有小数点
	if (*nptr != '\0' && *nptr == '.')
	{
		int pow = 1;
		++nptr;
		while (*nptr != '\0')
		{
			if (*nptr >= '0' && *nptr <= '9')
			{
				ret = ret * 10 + (*nptr - '0');
				pow *= 10;
			}
			else
				break;
			++nptr;
		}
		ret = ret / pow;
	}

	return ret == 0 ? 0 : ret*flag;
}