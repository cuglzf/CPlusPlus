#define OTHER_H


int checkSystem();

//�������linux�µ�ʵ��
static union
{
	char c[4];
	long l;
}dian_test = { { 'l', '?', '?', 'b' } };

#define ENDINESS ((char)dian_test.l)

void *MemoryCopy(void *dest, void *src, int count);