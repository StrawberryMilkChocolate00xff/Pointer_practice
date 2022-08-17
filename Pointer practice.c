#include <stdio.h>

static unsigned char msg[16] = "Hello world";

//ָ��һ������ָ���ָ���Ǳ���
void __pointer__P1(void)
{
	printf("P1:\n");
	unsigned char *p;

	p = msg;

	printf("%s\n", *&p);

	printf("\n");
	return;
}

//������ָ��Ĳ�ͬ����ת��
void __pointer__P2(void)
{
	printf("P2:\n");

	void *p;

	p = msg;

	printf("%s\n", (unsigned char*)p);

	int n = 0;
	for (n; n < 4; ++n)
	{
		//��unsigned int ���� unsigned char ��ʹÿ��ֻ��һ���ֽ�
		printf("%x ", *(unsigned int*)p);
		p = (unsigned int*)p + 1;
	}

	printf("\n");

	printf("\n");
	return;
}

//�༶���Ѱַ
void __pointer__P3(void)
{
	printf("P3:\n");
	unsigned int var = 0x000000FF;

	void *p1 = &var;
	void **p2 = &p1;
	void ***p3 = &p2;
	void ****p4 = &p3;

	void *****p5 = &p4;

	printf("%x", *****(unsigned int*****)p5);

	printf("\n");
	return;
}

void __pointer__P4(void)
{
	printf("P4:\n");

	void *p;

	p = msg;

	unsigned char a = 0;
	int n = 0;
	for (n; n < 13;++n)
	{
		//�� ((unsigned char*)p) ���嵱��һ����ַ
		a = ((unsigned char*)p)[n];
		printf("%c", a);
	}
	printf("\n");

	printf("\n");
	return;
}

int main(void)
{
	__pointer__P1();
	__pointer__P2();
	__pointer__P3();
	__pointer__P4();
}