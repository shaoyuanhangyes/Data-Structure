#include<iostream>//15180073邵远航 
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;//prior next指针指向struct DNode结构体变量 
}DNode,*DLinkList; //结构体类型为DNode 别名DLinkList
int InitList(DLinkList &L,int n){
	L=new DNode;//头结点 
	L->next=NULL;
	DLinkList r;
	r=L;
	for(int i=1;i<=n;i++){
		cout<<"请输入一个元素"<<endl;
		DNode *p=new DNode;
		cin>>p->data;
		p->next=NULL;
		p->prior=r;
		r->next=p;
		r=p;
	}
	return 1;
}
int ListInsert(DLinkList &L,int i,ElemType e){//插入数据 
	DNode *p=L;
	int j=1;
	while(p&&(j<i))
	{
		p=p->next;
		++j;
	}
	DNode *s=new DNode;
	s->data=e;
	s->next=p->next;
	p->next->prior=s;
	s->prior=p;
	p->next=s;
	return 1; 
} 
int ListDelete(DLinkList &L,int i){
	DNode *p=L;
	int j=1;
	while(p&&(j<i)){
		p=p->next;
		++j;
	}
	DNode *q=new DNode;
	q=p->next;
	p->next=q->next;
	q->next->prior=p;
	delete q;
	return 1;
}
void ShowList(DLinkList L){//显示元素 
	DNode *p=L;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->data<<" ";
	}
	cout<<endl;
}
int main(){
	DLinkList L;
	cout<<"请输入要插入的元素数量";
	int i,j,m,n;
	ElemType e;
	cin>>n;
	if(InitList(L,n)) cout<<"双链表创建完毕"<<endl;
	else cout<<"双链表创建失败"<<endl; 
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
					if(!ListInsert(L,i,e)) cout<<"插入数据失败"<<endl;
					else cout<<"插入数据成功"<<endl;
					break; 
				}
			case 2:
				{
					cout<<"请输入要删除的位置"<<endl;
					cin>>i;
					if(!ListDelete(L,i)) cout<<"删除失败"<<endl;
					else cout<<"删除成功"<<endl;
					break; 
				}
			case 3:
				{
					cout<<"输出表数据"<<endl;
					ShowList(L);
					break;
				}
		}
		cout<<"是否继续执行操作 1.继续 2.退出"<<endl;
		cin>>j;
	}while(j==1);
	return 0;
}
