#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}*LiStack;
bool InitStack(LiStack &S)//��ջ��ʼ�� 
{
	S=NULL;//Sʼ��ָ��ջ��Ԫ�� 
	return 1;
}
bool Push(LiStack &S,ElemType e)//��ջ 
{
	LinkNode *p =new LinkNode;
	p->data=e;
	p->next=S;
	S=p;
	return 1;
}
bool Pop(LiStack &S,ElemType &e)//��ջ 
{
	LinkNode *p=new LinkNode;
	if(S==NULL) return 0;//��ջ 
	e=S->data;
	p=S;
	S=S->next;
	delete p;
	return 1;
}
bool GetTop(LiStack S)//ȡջ��Ԫ��; 
{
	if(S!=NULL) cout<<S->data<<endl;
	return 1;
}
void Show(LiStack &S)
{
	LinkNode *p =S;//p����S��ջ���д��ϵ��µı��� 
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	LiStack S;
	int i,j,m,n;
	ElemType e;
	if(!InitStack(S)) cout<<"��ջ��ʼ��ʧ��"<<endl;
	cout<<"������Ҫ��ջ��Ԫ�ظ���"<<endl;
	cin>>j;
	for(int i=1;i<=j;i++)
	{
		cout<<"��������ջ��Ԫ��"<<endl;
		cin>>e;
		Push(S,e);
	}
	cout<<"Ԫ����ջ�ɹ�"<<endl;
	do
	{
		cout<<"�������Ӧ���ܵ����֣� 1.��ջ 2.��ջ 3.ȡջ��Ԫ�� 4.��ջ����ջ����ʾԪ�� "<<endl;
		cin>>m;
		switch(m)
		{
			case 1:
				{
					cout<<"��������ջ��Ԫ��"<<endl;
					cin>>e;
					Push(S,e);
					break;
				}
			case 2:
				{
					Pop(S,e);
					break;
				}
			case 3:
				{
					cout<<"ջ��Ԫ��Ϊ"<<endl;
					GetTop(S);
					break;
				}
			case 4:
				{
					cout<<"ջ����ջ�׵�Ԫ������Ϊ"<<endl;
					Show(S); 
					break;
				}
		}
		cout<<"�Ƿ����ִ�в��� 1.���� 2.�˳�"<<endl;
		cin>>n;
	}while(n==1);
}

