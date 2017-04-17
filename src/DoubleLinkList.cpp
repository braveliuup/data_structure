/************************************************************************/
/* 双向链表： 除了头结点和尾节点，其余节点均有一个前驱和一个后继
	1. 有了单链表，为什么还要实现双向链表？ 解决了什么问题
	已知节点可以快速查找其前驱和后继
	可以在元素位置上快速的插入删除元素，不用移动其他元素，可以双向遍历
*/
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct LinkNode
{
	int data;
	struct LinkNode *prior;
	struct LinkNode *next;
};
typedef struct LinkNode *DoubleLinkList;
void Create(DoubleLinkList &list)
{
	list = (DoubleLinkList )malloc(sizeof(struct LinkNode));
	if(!list)
	{
		exit(1);
		return;
	}
	list->prior = NULL;
	list->next = NULL;
}
int GetLength(DoubleLinkList &list)
{
	int len = 0;
	DoubleLinkList p = list->next;
	while( p )
	{
		len++;
		p = p->next;
	}
	return len;
}
void Insert(DoubleLinkList &list, int i , int e)
{
	DoubleLinkList p = list;
	int j =0;
	// 找到i-1位置上的元素
	while(p && j<i-1)
	{
		j++;
		p= p->next;
	}
	if( !p || j > i)
	{
		printf("插入位置不合理\n");
		return; // 插入位置不合理
	}
	DoubleLinkList q = (DoubleLinkList) malloc(sizeof(struct LinkNode));
	q->data = e;
	q->prior = p;
	q->next = p->next;
	if(p->next)
	{
		p->next->prior = q;
	}
	p->next = q;

}
void Traverse(DoubleLinkList &list)
{
	printf("Traverse List\n");
	DoubleLinkList p = list->next;
	while(p)
	{
		printf("%d,", p->data);
		p = p->next;
	}
	printf("\n");
}
void Delete(DoubleLinkList &list, int i)
{
	DoubleLinkList p = list;
	int j =0;
	// 找到i-1位置上的元素
	while(p && j<i-1)
	{
		j++;
		p= p->next;
	}
	if( !p || j > i-1)
	{
		printf("删除位置不合理\n");
		return; // 插入位置不合理
	}
	if(!p->next)
	{
		return;
	}
	DoubleLinkList q = p->next;
	if(q->next)
	{
		q->next->prior = p;
		p->next = q->next;
	}
	else
	{
		p->next = NULL;
	}
	free(q);
	
}
int Locate(DoubleLinkList &list, int e)
{
	DoubleLinkList p  = list->next;
	int i =0;
	while(p)
	{
		i++;
		if(p->data == e)
		{
			return i;
		}
		p= p->next;
	}
	return -1;

}
void Destroy(DoubleLinkList &list)
{
	DoubleLinkList p = list->next;
	DoubleLinkList q;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(list);
}
int main()
{
	DoubleLinkList list;
	printf("CreateList\n");
	Create(list);
	printf("InsertList\n");
	Insert(list, 1, 1);
	Insert(list, 1, 2);
	Traverse(list);
	printf("DeleteList data 2\n");
	Delete(list,2);
	Traverse(list);
	printf("LocateList data 2\n location:%d\n", Locate(list, 2));
	printf("DestroyList\n");
	Destroy(list);
	system("pause");
	return 0;
}