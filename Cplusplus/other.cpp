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

/*
C���Կ⺯��֮strcmp
������ַ����ȽϺ��������s1==s2������0�����s1>s2�������������s1<s2���ظ���
�ص���whileѭ���У����˼���src��destֵ�Ĳ�ֵ������Ҫ�ж�����һ���Ƿ����
*/
int Strcmp(const char *src, const char *dest)
{
	if (src == dest)
		return 0;

	int ret = 0;

	//����һ��Ҫ�ж�src��dest���Ƿ���һ��Ϊ\0
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
C���Կ⺯��֮memset
�����һ���ڴ�ȫ������Ϊָ��ֵ
memsetʹ��ע�����
1��int��������˳�ʼ��Ϊ0��-1�⣬������ֵ�����У�Ϊʲô���������ʵ�֣�memset��һ���ֽ�
һ���ֽڸ�ֵ�ģ������ʼ��Ϊ����0��-1���������ֵ����1��˵������1תΪcharʱ��ȡ��8λ��Ҳ����
0x01��Ȼ��0x01��ֵ��4���ֽڣ�int������ռ��4���ֽڣ�����ֵ��ɺ����0x01010101����˻����
16843009��Ϊʲô0��1��ֵ���ԣ�0�Ͳ���˵�˰ɣ�0�ķ��롢���롢ԭ�붼����������-1ת���ɲ���ȡ
��8λ��0x11������һ���ֽ��ڴ��о���0x11��Ȼ������������Ǹ�������˱�ɲ�����ʽ����-1������û��
2����memset����ʼ���ṹ�������ݵķ�����
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
C���Կ⺯��֮atoi
��������ǽ��ַ���ת��������
���������������ͷ�Ŀո�����һ����Ҫ������ַ��ͽ���
�Ľ����atoi���Լ���ʮ���ƺ�ʮ�����ƣ��ɼ�������
�������⣺����ַ���������ת��������ֳ���int��Χ�������Ҫ���
*/
int Atoi(const char *nptr)
{
	if (nptr == nullptr)
		return 0;

	//�����ո�
	while (*nptr == ' ')
	{
		++nptr;
	}

	//�������
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

	//�ж��Ƿ���16����
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

	//����
	while (*nptr != '\0')
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			//����һ����������nptr++����Ȼ��ѭ��
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
C���Կ⺯��֮atof
�˺������ַ���ת�ɸ�����
*/

double Atof(const char *nptr)
{
	double ret = 0.0;
	int flag = 1;
	if (nptr == nullptr)
		return ret;

	//����ǰ������пո�
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

	//�����С����
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