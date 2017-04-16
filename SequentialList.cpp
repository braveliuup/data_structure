/************************************************************************/
/*���Ա��˳���ʵ��                                                                      
	�ص㣺
	��.������ͬ���ʵ�����Ԫ������
	��.����洢�ռ��ַ����
*/

/************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define INIT_SIZE 100
#define INCREMENT_SIZE 10

struct List
{
	int *elem;
	int length;
	int alloc_size;
};

void Init(List *l)
{
	l->elem = (int *)malloc(INIT_SIZE*sizeof(int));
	l->length = 0;
	l->alloc_size = INIT_SIZE*sizeof(int);
}

void Insert(List *l, int i, int e)
{
	printf("\nInsert List:\n");
	if(i<1 || i > l->length +1) return ; // ����λ�ò�����
	// �ж��Ƿ����
	if( sizeof(int)*l->length >= l->alloc_size)
	{
		//  ����list
		l->elem = (int *)realloc(l, l->alloc_size + sizeof(int)*INCREMENT_SIZE);
		l->alloc_size += sizeof(int) * INCREMENT_SIZE;
	}
	//������λ�õ�Ҫ�����λ�ã����κ���һλ
	for(int j = l->length-1; j >= i-1; j--){
		l->elem[j+1] = l->elem[j];
	}
	l->elem[i-1] = e;
	l->length++;
	printf("��%dλ����Ԫ��%d\n", i, e);
}

void Delete(List *l, int i, int &d)
{
	int len = l->length;
	if(i<1 || i>len)	return ;
	// ��ɾ��λ�õĺ�һλ��ʼ��ÿһ��Ԫ��ǰ��һλ
	d = l->elem[i-1];
	for(int j = i; j < len; j++)
	{
		l->elem[j-1] = l->elem[j];
	}
	printf("\nDelete :\n");
	printf("ɾ����%dλ��Ԫ��,ɾ��Ԫ����%d", i, d);

}

void Traverse(List *l){
	printf("\nTraverse List:\n");
	for(int i =0 ; i < l->length; i++)
	{
		printf("%d,", l->elem[i]);
	}
	printf("\n");
}

int Locate(List *l, int e)
{
	printf("\nLocate %d:\n", e);
	for(int i=0; i < l->length; i++)
	{
		if(l->elem[i] == e)
		{
			printf("��һ��%d��������:%d\n", e, i);
			return i;
		}
	}
	printf("Not Found\n");
	return -1;
}

int main()
{
	struct List *l;
	l = (List *)malloc(sizeof(struct List));
	Init(l);
	Insert(l, 1, 1);
	Insert(l, 1, 2);
	Traverse(l);
	int findIdx = -1;
	int delVal = 0;
	findIdx =Locate(l, 1);
	Delete(l, 1, delVal);
	getchar();
	return 0;
}