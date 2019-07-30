#include<iostream>//15180073��Զ�� 
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;//prior nextָ��ָ��struct DNode�ṹ����� 
}DNode,*DLinkList; //�ṹ������ΪDNode ����DLinkList
int InitList(DLinkList &L,int n){
	L=new DNode;//ͷ��� 
	L->next=NULL;
	DLinkList r;
	r=L;
	for(int i=1;i<=n;i++){
		cout<<"������һ��Ԫ��"<<endl;
		DNode *p=new DNode;
		cin>>p->data;
		p->next=NULL;
		p->prior=r;
		r->next=p;
		r=p;
	}
	return 1;
}
int ListInsert(DLinkList &L,int i,ElemType e){//�������� 
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
void ShowList(DLinkList L){//��ʾԪ�� 
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
	cout<<"������Ҫ�����Ԫ������";
	int i,j,m,n;
	ElemType e;
	cin>>n;
	if(InitList(L,n)) cout<<"˫���������"<<endl;
	else cout<<"˫������ʧ��"<<endl; 
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
					if(!ListInsert(L,i,e)) cout<<"��������ʧ��"<<endl;
					else cout<<"�������ݳɹ�"<<endl;
					break; 
				}
			case 2:
				{
					cout<<"������Ҫɾ����λ��"<<endl;
					cin>>i;
					if(!ListDelete(L,i)) cout<<"ɾ��ʧ��"<<endl;
					else cout<<"ɾ���ɹ�"<<endl;
					break; 
				}
			case 3:
				{
					cout<<"���������"<<endl;
					ShowList(L);
					break;
				}
		}
		cout<<"�Ƿ����ִ�в��� 1.���� 2.�˳�"<<endl;
		cin>>j;
	}while(j==1);
	return 0;
}
