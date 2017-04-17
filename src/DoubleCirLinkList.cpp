/************************************************************************/
/* 双向循环链表： 在双向链表的基础上，尾节点的后继指向头结点， 头结点的前驱指向尾节点
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
typedef struct LinkNode *DoubleCirLinkList;
void Create(DoubleCirLinkList &list)
{
	list = (DoubleCirLinkList )malloc(sizeof(struct LinkNode));
	if(!list)
	{
		exit(1);
		return;
	}
	list->prior = list;
	list->next = list;
}
int GetLength(DoubleCirLinkList &list)
{
	int len = 0;
	DoubleCirLinkList head = list;
	DoubleCirLinkList p = head;
	while( p->next != head)
	{
		p = p->next;
		len++;
	}
	return len;
}
void Insert(DoubleCirLinkList &list, int i , int e)
{
	DoubleCirLinkList p = list;
	int j =0;
	if (i< 1 || i > GetLength(list)+1)
	{
		printf("插入位置不合理");
		return;
	}
	// 找到i-1位置上的元素
	while(j<i-1)
	{
		j++;
		p= p->next;
	}
	DoubleCirLinkList q = (DoubleCirLinkList) malloc(sizeof(struct LinkNode));
	q->data = e;
	q->prior = p;
	q->next = p->next;
	p->next->prior = q; //搞一个双向循环链表的话  就不用判断后继是否为空了
	p->next = q;

}
void Traverse(DoubleCirLinkList &list)
{
	printf("Traverse List\n");
	DoubleCirLinkList p = list->next;
	while(p != list)
	{
		printf("%d,", p->data);
		p = p->next;
	}
	printf("\n");
}
void Delete(DoubleCirLinkList &list, int i)
{
	DoubleCirLinkList p = list;
	int j =0;
	if( i< 1 || i > GetLength(list))
	{
		printf("删除位置不合理\n");
		return; // 插入位置不合理
	}
	// 找到i位置上的元素
	while( j<i)
	{
		j++;
		p= p->next;
	}
	
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	
}
int Locate(DoubleCirLinkList &list, int e)
{
	DoubleCirLinkList p  = list->next;
	int i =0;
	while(p != list)
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
void Destroy(DoubleCirLinkList &list)
{
	DoubleCirLinkList p = list->next;
	DoubleCirLinkList q;
	while(p != list)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(list);
}
int main()
{
	DoubleCirLinkList list;
	printf("CreateList\n");
	Create(list);
	printf("InsertList [1,1] [1,2]\n");
	Insert(list, 1, 1);
	Insert(list, 1, 2);
	Traverse(list);
	printf("DeleteList Location 2\n");
	Delete(list,2);
	Traverse(list);
	printf("LocateList data 2\n location:%d\n", Locate(list, 2));
	printf("DestroyList\n");
	Destroy(list);
	system("pause");
	return 0;
}