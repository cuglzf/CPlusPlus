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

char *Strcpy(char *dest, const char *src);

int Strcmp(const char *src, const char *dest);

void *Memset(void *dst, int ch, int count);