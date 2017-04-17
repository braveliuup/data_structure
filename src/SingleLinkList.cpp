/************************************************************************/
/* 单链表，最简单的线性表链式存储的实现
	1.抽象节点结构体，保存数据和指向后继的指针
*/
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// 定义结构体
struct LinkNode {
	int data;
	struct LinkNode *next;
};
typedef struct LinkNode* LinkList;

void Create(LinkList &L)
{
	L = (LinkList)malloc(sizeof(struct LinkNode));
	L->next = NULL;
}

void Destroy(LinkList &L)
{
	LinkList q;
	while(L){
		q = L->next;
		free(L);
		L = q;
	}
}

void Insert(LinkList  &L, int i, int e)
{
	int j =0;
	LinkList p = L;
	while(p && j < i-1){
		p = p->next;
		j++;
	}
	if(!p || j > i-1) return;
	LinkList q = (LinkList)malloc(sizeof(struct LinkNode));
	q->data = e;
	q->next = p->next;
	p->next	 = q;
}

void Delete(LinkList &L, int i)
{
	int j =0;
	LinkList p = L;
	while(p->next && j < i-1)
	{
		p = p->next;
		j++;
	}
	if(!p->next || j > i-1) return; 
	LinkList q = p->next->next;
	free(p->next);
	p->next = q;
}

int Locate(LinkList &L, int e)
{
	LinkList p = L;
	int j = 0;
	while (p->next)
	{
		if(p->next->data == e)
		{
			return j;
		}
		p = p->next;
		j++;
	}
	return -1;
}

void Traverse(LinkList  &L)
{
	LinkList p = L;
	while(p && p->next)
	{
		printf("%d\n", p->next->data);
		p = p->next;
	}
}


int main()
{
	LinkList list;
	Create(list);
	Insert(list, 1, 1);
	Insert(list, 1, 2);
	Insert(list, 1, 3);
	printf("Tarverse Link List\n");
	Traverse(list);
	printf("Delete location 1\n");
	Delete(list, 1);
	Traverse(list);
	printf("Locate data 1\n");
	Locate(list, 1);
	Traverse(list);
	printf("Destroy Link List\n");
	Destroy(list);
	Traverse(list);
	
	getchar();
	return 0;
}
