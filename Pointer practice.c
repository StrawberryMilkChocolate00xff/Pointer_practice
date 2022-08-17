#include <stdio.h>

static unsigned char msg[16] = "Hello world";

//指向一个引用指针的指针是本身
void __pointer__P1(void)
{
	printf("P1:\n");
	unsigned char *p;

	p = msg;

	printf("%s\n", *&p);

	printf("\n");
	return;
}

//无类型指针的不同类型转换
void __pointer__P2(void)
{
	printf("P2:\n");

	void *p;

	p = msg;

	printf("%s\n", (unsigned char*)p);

	int n = 0;
	for (n; n < 4; ++n)
	{
		//把unsigned int 换成 unsigned char 会使每次只读一个字节
		printf("%x ", *(unsigned int*)p);
		p = (unsigned int*)p + 1;
	}

	printf("\n");

	printf("\n");
	return;
}

//多级间接寻址
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
		//将 ((unsigned char*)p) 整体当成一个地址
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