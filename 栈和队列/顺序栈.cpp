#include<iostream>
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct
{
	ElemType data[Maxsize];
	int top;//栈顶指针 
}SqStack;
void InitStack(SqStack &S){
	S.top=-1;
} 
bool Push(SqStack &S,ElemType e)//入栈 在栈顶插入一个新的元素 
{
	if(S.top==Maxsize-1) return 0;//栈满 
	S.data[++S.top]=e; 
	return 1;
}
int Pop(SqStack &S,ElemType &e)//出栈 将栈顶元素删除 
{
	if(S.top==-1) return 0;//栈空 
	e=S.data[S.top--];
	return 1;
}
bool GetTop(SqStack S,ElemType &e){//取栈顶元素 
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
					cout<<"删除成功"<<endl;
					break; 
				}
			case 3:
				{
					ElemType a;
					GetTop(S,a);
					cout<<"栈顶元素是"<<a<<endl;
					break; 
				}
			case 4:
				{
					cout<<"从栈顶到栈底显示元素"<<endl;
					Show(S);
					break;
				}
		 } 
		cout<<"是否继续执行操作 1.继续 2.退出"<<endl;
		cin>>n;
	}while(n==1);
	return 0;
}

