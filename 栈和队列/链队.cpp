#include<iostream>
using namespace std;
typedef char ElemType; 
typedef struct LNode
{
	ElemType data;
	struct LNode *next;//next指向struct Lnode结构体变量 
}LNode,*LinkNode;//结构体类型LNode 别名为*LinkNode 
typedef struct{
	LNode *front,*rear;
}LinkQueue;
bool InitQueue(LinkQueue &Q){//初始化 
	Q.front=Q.rear=new LNode;  
    Q.front->next=NULL;  
	return 1;
}
bool EnQueue(LinkQueue &Q,ElemType e)//入列 
{
	LNode *p=new LNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
bool DeQueue(LinkQueue &Q,ElemType &e)//出队 
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
int DestroyQueue(LinkQueue &Q,ElemType &e)//销毁链队列 
{
	while(!InitQueue(Q))
	{  
		DeQueue(Q,e);
	}
	delete Q.front;  
    Q.front=Q.rear=NULL;
    return 1;
}
void DispQueue(LinkQueue Q)//显示链队列元素 
{
	LNode *p=new LNode;
	LNode *q=new LNode;
	if(Q.rear==NULL) cout<<"队列为空"<<endl;
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
	if(!InitQueue(Q)) cout<<"链队初始化失败"<<endl;
	cout<<"请输入要入队的元素个数"<<endl;
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
		cout<<"请输入对应功能的数字： 1.入队 2.出队 3.销毁链队列 4.显示队列元素 "<<endl;
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
					if(!DestroyQueue(Q,e)) cout<<"销毁失败"<<endl;
					else cout<<"销毁成功"<<endl; 
					break;
				}
			case 4:
				{
					cout<<"显示队列的元素"<<endl;
					DispQueue(Q);
					break;
				}			
		}
		cout<<"是否继续执行操作 1.继续 2.退出"<<endl;
		cin>>n;
	}while(n==1);
	return 0;
}
