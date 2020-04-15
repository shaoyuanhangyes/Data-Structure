#include<iostream>
using namespace std;
typedef char ElemType; 
typedef struct LNode
{
	ElemType data;
	struct LNode *next;//nextָ��struct Lnode�ṹ����� 
}LNode,*LinkNode;//�ṹ������LNode ����Ϊ*LinkNode 
typedef struct{
	LNode *front,*rear;
}LinkQueue;
bool InitQueue(LinkQueue &Q){//��ʼ�� 
	Q.front=Q.rear=new LNode;  
    Q.front->next=NULL;  
	return 1;
}
bool EnQueue(LinkQueue &Q,ElemType e)//���� 
{
	LNode *p=new LNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
bool DeQueue(LinkQueue &Q,ElemType &e)//���� 
{
	if(Q.front==Q.rear) return 0;
	LNode *p=new LNode;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	delete p;
	return 1; 
}
int DestroyQueue(LinkQueue &Q,ElemType &e)//���������� 
{
	while(!InitQueue(Q))
	{  
		DeQueue(Q,e);
	}
	delete Q.front;  
    Q.front=Q.rear=NULL;
    return 1;
}
void DispQueue(LinkQueue Q)//��ʾ������Ԫ�� 
{
	LNode *p=new LNode;
	LNode *q=new LNode;
	if(Q.rear==NULL) cout<<"����Ϊ��"<<endl;
	else
	{
		p=Q.front->next;
		q=Q.rear;
		while(p!=NULL)
			{
				cout<<p->data<<" ";
				p=p->next;
			} 
			cout<<endl;
	}
} 
int main()
{
	LinkQueue Q;
	int i,j,m,n;
	ElemType e;
	if(!InitQueue(Q)) cout<<"���ӳ�ʼ��ʧ��"<<endl;
	cout<<"������Ҫ��ӵ�Ԫ�ظ���"<<endl;
	cin>>j;
	for(i=1;i<=j;i++)
	{
		cout<<"������Ҫ��ӵ�Ԫ��"<<endl;
		cin>>e;
		EnQueue(Q,e); 
	}
	cout<<"Ԫ����ӳɹ�"<<endl;
	do
	{
		cout<<"�������Ӧ���ܵ����֣� 1.��� 2.���� 3.���������� 4.��ʾ����Ԫ�� "<<endl;
		cin>>m;
		switch(m)
		{
			case 1:
				{
					cout<<"��������ӵ�Ԫ��"<<endl;
					cin>>e;
					EnQueue(Q,e);
					break;
				}
			case 2:
				{
					DeQueue(Q,e);
					cout<<"ɾ���ɹ�"<<endl;
					break;
				}
			case 3:
				{
					if(!DestroyQueue(Q,e)) cout<<"����ʧ��"<<endl;
					else cout<<"���ٳɹ�"<<endl; 
					break;
				}
			case 4:
				{
					cout<<"��ʾ���е�Ԫ��"<<endl;
					DispQueue(Q);
					break;
				}			
		}
		cout<<"�Ƿ����ִ�в��� 1.���� 2.�˳�"<<endl;
		cin>>n;
	}while(n==1);
	return 0;
}
