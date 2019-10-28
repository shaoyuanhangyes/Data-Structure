#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}*LiStack;
bool InitStack(LiStack &S)//链栈初始化 
{
	S=NULL;//S始终指向栈顶元素 
	return 1;
}
bool Push(LiStack &S,ElemType e)//入栈 
{
	LinkNode *p =new LinkNode;
	p->data=e;
	p->next=S;
	S=p;
	return 1;
}
bool Pop(LiStack &S,ElemType &e)//出栈 
{
	LinkNode *p=new LinkNode;
	if(S==NULL) return 0;//空栈 
	e=S->data;
	p=S;
	S=S->next;
	delete p;
	return 1;
}
bool GetTop(LiStack S)//取栈顶元素; 
{
	if(S!=NULL) cout<<S->data<<endl;
	return 1;
}
void Show(LiStack &S)
{
	LinkNode *p =S;//p代替S对栈进行从上到下的遍历 
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
	if(!InitStack(S)) cout<<"链栈初始化失败"<<endl;
	cout<<"请输入要入栈的元素个数"<<endl;
	cin>>j;
	for(int i=1;i<=j;i++)
	{
		cout<<"请输入入栈的元素"<<endl;
		cin>>e;
		Push(S,e);
	}
	cout<<"元素入栈成功"<<endl;
	do
	{
		cout<<"请输入对应功能的数字： 1.入栈 2.出栈 3.取栈顶元素 4.从栈顶到栈底显示元素 "<<endl;
		cin>>m;
		switch(m)
		{
			case 1:
				{
					cout<<"请输入入栈的元素"<<endl;
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
					cout<<"栈顶元素为"<<endl;
					GetTop(S);
					break;
				}
			case 4:
				{
					cout<<"栈顶到栈底的元素依次为"<<endl;
					Show(S); 
					break;
				}
		}
		cout<<"是否继续执行操作 1.继续 2.退出"<<endl;
		cin>>n;
	}while(n==1);
}

