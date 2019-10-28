#include<iostream>
using namespace std;
#define Maxsize 6
typedef char ElemType; 
typedef struct
{
	ElemType *data;//队列元素 
	int front,rear;//头指针与尾指针 
}SqQueue;
bool InitQueue(SqQueue &Q)//初始化空队列Q 
{
	Q.data = new ElemType[Maxsize];
	if(!Q.data) return 0;
	Q.front=Q.rear=0;//头指针等于尾指针是队列为空的标志 
	return 1;
}
bool EnQueue(SqQueue &Q,ElemType e)//入队 
{
	if((Q.rear+1)%Maxsize==Q.front) return 0;//队满 
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%Maxsize;//队尾指针+1取模=向后移位 
	return 1;
}
bool DeQueue(SqQueue &Q,ElemType &e)//出队 
{
	if(Q.front==Q.rear) return 0;//队空 
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%Maxsize;//队首指针+1取模=向后移位 
	return 1;
}
bool QueueLength(SqQueue Q)//循环队列长度 
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
	if(!InitQueue(Q)) cout<<"循环队列初始化失败"<<endl;
	cout<<"请输入要入队的元素个数 个数不能大于5否则入队失败"<<endl;
	cin>>j;
	for(i=1;i<=j;i++)
	{
		cout<<"请输入要入队的元素"<<endl;
		cin>>e;
		EnQueue(Q,e); 
	}
	cout<<"元素入队成功"<<endl;
	do
	{
		cout<<"请输入对应功能的数字： 1.入队 2.出队 3.求循环队列长度 4.显示队列元素 "<<endl;
		cin>>m;
		switch(m)
		{
			case 1:
				{
					cout<<"请输入入队的元素"<<endl;
					cin>>e;
					EnQueue(Q,e);
					break;
				}
			case 2:
				{
					DeQueue(Q,e);
					cout<<"删除成功"<<endl;
					break;
				}
			case 3:
				{
					cout<<"队列长度为";
					QueueLength(Q);
					cout<<endl;
					break;
				}
			case 4:
				{
					cout<<"显示队列的元素"<<endl;
					ShowQueue(Q);
					break;
				}			
		}
		cout<<"是否继续执行操作 1.继续 2.退出"<<endl;
		cin>>n;
	}while(n==1);
	return 0;
}
