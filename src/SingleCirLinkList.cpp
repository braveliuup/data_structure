/************************************************************************/
/* ��ѭ������ʹ��βָ���ʾ
	1. ʹ��βָ���ʾѭ��������Է�����ڱ�ͷ�ͱ�λ��������
	2. �뵥����Ľṹ��һ��
*/
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct LinkNode {
	int data;
	struct LinkNode *next;
};

typedef struct LinkNode* SCLinkList;

void Create(SCLinkList &L)
{
	L = (SCLinkList)malloc(sizeof(struct LinkNode));
	if(!L){
		exit(1);
	}
	L->next = L;
}

void Destroy(SCLinkList &L)
{
	SCLinkList head = L->next;
	SCLinkList p = head->next;
	SCLinkList q;
	while (p != head)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);

}
int GetLength(SCLinkList &L)
{
	int len =0;
	SCLinkList p = L->next;
	while(p != L)
	{
		len++;
		p = p->next;
	}
	return len;
}
void Insert(SCLinkList &L, int i, int e)
{
	SCLinkList head = L->next;
	SCLinkList p = head;
	int j =0;
	if(i <1 || i > GetLength(L) + 1) 
	{
		printf("����λ�ò�����");
		return ;
	}
	// ���� i-1λ�õĽڵ�
	while(j < i-1)
	{
		p = p->next;
		j++;
	}
	SCLinkList q = (SCLinkList)malloc(sizeof(struct LinkNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	// ����Ԫ�غ�ı�βָ�� 
	if(q->next == head){
		L = q;
	}
}

void Delete(SCLinkList &L, int i, int &e)
{
	SCLinkList head = L->next;
	SCLinkList p = head;
	int j =0 ;
	if(i<1 || i> GetLength(L)) 
	{
		printf("ɾ��λ�ò�����\n");
		return ;
	}
	// �ҵ�i-1λ�õ�Ԫ��
	while(j < i-1)
	{
		p = p->next;
		j++;
	}
	if(p->next != head)
	{
		SCLinkList q = p->next;
		p->next = q->next;
		free(q);
	}
	// �ı�βָ���λ��
	if(p->next == head)
	{
		L = p;
	}
}

void Traverse(SCLinkList &L)
{
	SCLinkList head = L->next;
	SCLinkList p = head->next;
	while(p != head)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

int Locate(SCLinkList &L, int e)
{
	SCLinkList head = L->next;
	SCLinkList p = head;
	int i =0;
	while(p->next != head)
	{
		p = p->next;
		i++;
		if(p->data == e)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	SCLinkList linkList;
	printf("Create List\n");
	Create(linkList);
	printf("Insert List\n");
	Insert(linkList, 1, 1);
	Insert(linkList, 1, 2);
	Insert(linkList, 1, 3);
	printf("Traverse List\n");
	Traverse(linkList);
	printf("Locate data 1\n");
	int location = Locate(linkList, 1);
	printf("%d\n", location);
	printf("Delete location 2\n");
	int e;
	Delete(linkList, 2, e);
	Traverse(linkList);
	printf("Destroy List\n");
	Destroy(linkList);
	system("pause");
	return 0;
}