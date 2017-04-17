/************************************************************************/
/*线性表的顺序表实现                                                                      
	特点：
	１.具有相同性质的有限元素序列
	２.物理存储空间地址连续
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
	if(i<1 || i > l->length +1) return ; // 插入位置不合理
	// 判断是否溢出
	if( sizeof(int)*l->length >= l->alloc_size)
	{
		//  扩充list
		l->elem = (int *)realloc(l, l->alloc_size + sizeof(int)*INCREMENT_SIZE);
		l->alloc_size += sizeof(int) * INCREMENT_SIZE;
	}
	//从最后的位置到要插入的位置，依次后移一位
	for(int j = l->length-1; j >= i-1; j--){
		l->elem[j+1] = l->elem[j];
	}
	l->elem[i-1] = e;
	l->length++;
	printf("第%d位插入元素%d\n", i, e);
}

void Delete(List *l, int i, int &d)
{
	int len = l->length;
	if(i<1 || i>len)	return ;
	// 从删除位置的后一位开始，每一个元素前移一位
	d = l->elem[i-1];
	for(int j = i; j < len; j++)
	{
		l->elem[j-1] = l->elem[j];
	}
	printf("\nDelete :\n");
	printf("删除第%d位的元素,删除元素是%d", i, d);

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
			printf("第一个%d的索引是:%d\n", e, i);
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