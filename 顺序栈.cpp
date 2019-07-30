#include<iostream>
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct
{
	ElemType data[Maxsize];
	int top;//ջ��ָ�� 
}SqStack;
void InitStack(SqStack &S){
	S.top=-1;
} 
bool Push(SqStack &S,ElemType e)//��ջ ��ջ������һ���µ�Ԫ�� 
{
	if(S.top==Maxsize-1) return 0;//ջ�� 
	S.data[++S.top]=e; 
	return 1;
}
int Pop(SqStack &S,ElemType &e)//��ջ ��ջ��Ԫ��ɾ�� 
{
	if(S.top==-1) return 0;//ջ�� 
	e=S.data[S.top--];
	return 1;
}
bool GetTop(SqStack S,ElemType &e){//ȡջ��Ԫ�� 
	if(S.top==-1) return 0;
	e=S.data[S.top];
	return 1;
} 
int Show(SqStack S){
	int i;
	for(i=S.top;i>=0;i--){
		cout<<S.data[i]<<endl;
	}
	cout<<endl;
	return 1;
}
int main()
{
	SqStack S;
	int i,j,m,n;
	ElemType e;
	InitStack(S);
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
					cout<<"ɾ���ɹ�"<<endl;
					break; 
				}
			case 3:
				{
					ElemType a;
					GetTop(S,a);
					cout<<"ջ��Ԫ����"<<a<<endl;
					break; 
				}
			case 4:
				{
					cout<<"��ջ����ջ����ʾԪ��"<<endl;
					Show(S);
					break;
				}
		 } 
		cout<<"�Ƿ����ִ�в��� 1.���� 2.�˳�"<<endl;
		cin>>n;
	}while(n==1);
	return 0;
}

