#include<iostream>//15180073��Զ�� 
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;//nextָ��struct Lnode�ṹ����� 
}LNode,*LinkList;//�ṹ������LNode ����Ϊ*LinkList 
int InitList_L(LinkList &L,int n)//��巨�����ձ� 
{
	L=new LNode;//ͷ��� 
	L->next=NULL;
	LinkList r;
	r=L;
	for(int i=1;i<=n;i++)
	{
		cout<<"������һ��Ԫ��"<<endl;
		LNode *p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	return 1;
}
int ListInsert_L(LinkList &L,int i,ElemType e)//�������� 
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
int ListDelete_L(LinkList &L,int i)//ɾ������ 
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
void Disp_L(LinkList L)//��ʾ���� 
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
	cout<<"������Ҫ�����Ԫ������";
	int i,j,m,n;
	ElemType e;
	cin>>n;
	if(InitList_L(L,n)) cout<<"�����������"<<endl;
	else cout<<"��������ʧ��"<<endl; 
	do
	{
		cout<<"�������Ӧ���ܵ����֣� 1.���� 2.ɾ�� 3.��ʾ�� "<<endl;
		cin>>m;
		switch(m)
		{
			case 1:
				{
					cout<<"������Ҫ�����λ��"<<endl;
					cin>>i;
					cout<<"������Ҫ�����Ԫ��"<<endl;
					cin>>e;
					if(!ListInsert_L(L,i,e)) cout<<"��������ʧ��"<<endl;
					else cout<<"�������ݳɹ�"<<endl;
					break; 
				}
			case 2:
				{
					cout<<"������Ҫɾ����λ��"<<endl;
					cin>>i;
					if(!ListDelete_L(L,i)) cout<<"ɾ��ʧ��"<<endl;
					else cout<<"ɾ���ɹ�"<<endl;
					break; 
				}
			case 3:
				{
					cout<<"���������"<<endl;
					Disp_L(L);
					break;
				}
		}
		cout<<"�Ƿ����ִ�в��� 1.���� 2.�˳�"<<endl;
		cin>>j;
	}while(j==1);
	return 0;
}
