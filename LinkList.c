#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define TRUE 1
#define FALSE -1
typedef int Status;
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *next;
}Node,*LinkList;
//初始化链表
Status ListInit(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	return OK;
} 
//录入数据(1)头插法
void CreateList(LinkList *L,int n)
{
	int i;
	Node *p;
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	for(i=n;i>0;i--)
	{
		p=(LinkList)malloc(sizeof(Node));
		printf("No.%d:",i);
		scanf("%d",&p->data);
		p->next=(*L)->next;
		(*L)->next=p;
	}
}
//录入方法(2)尾插发
LinkList *Create(LinkList *L)
{
	Node *r,*s;
	int c,n;
	int i;
	*L=(LinkList)malloc(sizeof(Node));
	r=*L;
	printf("你要输入多少个数:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("No.%d:",i);
		scanf("%d",&c);
		s=(LinkList)malloc(sizeof(Node));
		s->data=c;
		s->next=NULL;
		r->next=s;
		r=s;
	}
	return L;
}
//输出链表
void PrintList(LinkList L)
{
	Node *p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
//获取长度
int GetLength(LinkList L)
{
	Node *p;
	int count=0;
	p=L->next;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
//判空
void ListEmpty(LinkList L)
{
	Node *p;
	p=L->next;
	if(p==NULL)
		printf("It's empty\n");
	else
		printf("It's not empty\n");
}
//获取元素
Status Getelem(LinkList L,int i,int *e)
{
	Node *p;
	p=L->next;
	int j=1;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(p==NULL||j>i)
		return -1;
	*e=p->data;
	return OK;
}
//插入元素
Status ListInsert(LinkList *L,int i,Elemtype e)
{
	//在单链表L中第i个位置插入e
	Node *p,*s;
	int j=0;
	p=*L;
	while(p!=NULL&&j<i-1)
	{
		//找到i-1个结点
		p=p->next;
		j++;
	}
	if(j!=i-1)
		return FALSE;//未找到插入位置，出错处理
	s=(LinkList)malloc(sizeof(Node));//生成新结点
	s->data=e;
	s->next=p->next;//插入新结点
	p->next=s;
	return TRUE;
}
//删除元素
Status ListDelete(LinkList *L,int i,Elemtype *e)
{
	Node *p,*r;
	int j=0;
	p=*L;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(j!=i-1)
		return FALSE;
	r=p->next;
	p->next=p->next->next;
	*e=r->data;
	free(r);
	return TRUE;
}
int main()
{
	LinkList L;
	int choice;
	do
	{
		printf("1.ListInit\t2.CreateList(头插法)\t3.*Create(尾插法)\n4.PrintList\t5.GetLength\t6.ListEmpty\n7.Getelem\t8.ListInsert\t9.ListDelete\n");
		printf("\n请输入你的选择:\n");
		scanf("%d",&choice);
		switch(choice)
		{
		//system("cls");
		case 0:printf("byebye\n");
			break;
		case 1:
			{
				if(ListInit(&L)==OK)
				printf("success\n");
				else
					printf("false\n");
				break;
			}
		case 2:
			{
				int n;
				printf("请输入你要存放的数据量:\n");
				scanf("%d",&n);
				CreateList(&L,n);
				break;
			}
		case 3:
			{
				L=*Create(&L);
				break;
			}
		case 4:
			{
				PrintList(L);
				printf("\n");
				break;
			}
		case 5:
			{
				int count;
				count=GetLength(L);
				printf("长度为:%d\n",count);
				break;
			}
		case 6:
			{
				ListEmpty(L);
				break;
			}
		case 7:
			{
				int i;
				int e;
				printf("请问你想要第几个数:\n");
				scanf("%d",&i);
				if(Getelem(L,i,&e)==OK)
					printf("第%d个数是:%d\n",i,e);
				else
					printf("没有这个数\n");
				break;
			}
		case 8:
			{
				int i,e;
				printf("请输入你要插入的位置和数据:\n");
				scanf("%d%d",&i,&e);
				if(ListInsert(&L,i,e)==TRUE)
					printf("插入成功\n");
				else
					printf("插入失败");
				break;
			}
		case 9:
			{
				int i,e;
				printf("你想要删除第几个元素:\n");
				scanf("%d",&i);
				if(ListDelete(&L,i,&e)==TRUE)
					printf("删除成功\n");
				else
					printf("删除失败\n");
				printf("第%d个数是:%d\n",i,e);
			}
		default:printf("输入错误，请重新输入\n");
			break;
			//system("pause");
		}
	}while(choice!=0);

	return 0;
}


