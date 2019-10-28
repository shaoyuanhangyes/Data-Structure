#include<iostream>
using namespace std;
#define Maxsize 6
typedef char ElemType; 
typedef struct
{
	ElemType *data;//����Ԫ�� 
	int front,rear;//ͷָ����βָ�� 
}SqQueue;
bool InitQueue(SqQueue &Q)//��ʼ���ն���Q 
{
	Q.data = new ElemType[Maxsize];
	if(!Q.data) return 0;
	Q.front=Q.rear=0;//ͷָ�����βָ���Ƕ���Ϊ�յı�־ 
	return 1;
}
bool EnQueue(SqQueue &Q,ElemType e)//��� 
{
	if((Q.rear+1)%Maxsize==Q.front) return 0;//���� 
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%Maxsize;//��βָ��+1ȡģ=�����λ 
	return 1;
}
bool DeQueue(SqQueue &Q,ElemType &e)//���� 
{
	if(Q.front==Q.rear) return 0;//�ӿ� 
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%Maxsize;//����ָ��+1ȡģ=�����λ 
	return 1;
}
bool QueueLength(SqQueue Q)//ѭ�����г��� 
{
	cout<<(Q.rear-Q.front+Maxsize)%Maxsize;
}
void ShowQueue(SqQueue Q)
{
		int i=Q.front;
		while(i!=Q.rear)
		{
			cout<<Q.data[i]<<" ";
			i=(i+1)%Maxsize;
		}
	cout<<endl;
}
int main()
{
	SqQueue Q;
	int i,j,m,n;
	ElemType e;
	if(!InitQueue(Q)) cout<<"ѭ�����г�ʼ��ʧ��"<<endl;
	cout<<"������Ҫ��ӵ�Ԫ�ظ��� �������ܴ���5�������ʧ��"<<endl;
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
		cout<<"�������Ӧ���ܵ����֣� 1.��� 2.���� 3.��ѭ�����г��� 4.��ʾ����Ԫ�� "<<endl;
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
					cout<<"���г���Ϊ";
					QueueLength(Q);
					cout<<endl;
					break;
				}
			case 4:
				{
					cout<<"��ʾ���е�Ԫ��"<<endl;
					ShowQueue(Q);
					break;
				}			
		}
		cout<<"�Ƿ����ִ�в��� 1.���� 2.�˳�"<<endl;
		cin>>n;
	}while(n==1);
	return 0;
}
