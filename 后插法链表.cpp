#include<iostream>//15180073邵远航 
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;//next指向struct Lnode结构体变量 
}LNode,*LinkList;//结构体类型LNode 别名为*LinkList 
int InitList_L(LinkList &L,int n)//后插法创建空表 
{
	L=new LNode;//头结点 
	L->next=NULL;
	LinkList r;
	r=L;
	for(int i=1;i<=n;i++)
	{
		cout<<"请输入一个元素"<<endl;
		LNode *p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	return 1;
}
int ListInsert_L(LinkList &L,int i,ElemType e)//插入数据 
{
	LNode *p=L;
	int j=1;
	while(p&&(j<i))
	{
		p=p->next;
		++j;
	}
	LNode *s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
int ListDelete_L(LinkList &L,int i)//删除数据 
{
	LNode *p=L;
	int j=1;
	while(p&&(j<i))
	{
		p=p->next;
		++j;
	}
//	if((!p->next)&&(j>i)) return 0;
	LNode *q=new LNode;
	q=p->next;
	p->next=q->next;
	delete q;
	return 1;	
}
void Disp_L(LinkList L)//显示数据 
{
	LNode *p=L;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->data<<" ";
	}
	cout<<endl;
}
int main()
{
	LinkList L;
	cout<<"请输入要插入的元素数量";
	int i,j,m,n;
	ElemType e;
	cin>>n;
	if(InitList_L(L,n)) cout<<"单链表创建完毕"<<endl;
	else cout<<"单链表创建失败"<<endl; 
	do
	{
		cout<<"请输入对应功能的数字： 1.插入 2.删除 3.显示表 "<<endl;
		cin>>m;
		switch(m)
		{
			case 1:
				{
					cout<<"请输入要插入的位置"<<endl;
					cin>>i;
					cout<<"请输入要输入的元素"<<endl;
					cin>>e;
					if(!ListInsert_L(L,i,e)) cout<<"插入数据失败"<<endl;
					else cout<<"插入数据成功"<<endl;
					break; 
				}
			case 2:
				{
					cout<<"请输入要删除的位置"<<endl;
					cin>>i;
					if(!ListDelete_L(L,i)) cout<<"删除失败"<<endl;
					else cout<<"删除成功"<<endl;
					break; 
				}
			case 3:
				{
					cout<<"输出表数据"<<endl;
					Disp_L(L);
					break;
				}
		}
		cout<<"是否继续执行操作 1.继续 2.退出"<<endl;
		cin>>j;
	}while(j==1);
	return 0;
}
