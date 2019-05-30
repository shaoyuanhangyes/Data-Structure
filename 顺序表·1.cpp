#include<iostream> 
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;
typedef int Status;
typedef char ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;
Status Initlist_Sq(SqList &L){//��ʼ��˳���L 
	L.elem = new ElemType[MAXSIZE]; 
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}
Status ListInsert_Sq(SqList &L,int i,ElemType e){//�����L 
	if((i<1)||(i>L.length+1)) return ERROR;
	if(L.length==MAXSIZE) return OVERFLOW;
	for(int j=L.length;j>=i;j--){
		L.elem[j] = L.elem[j-1];
	}
	L.elem[i-1] = e;
	++L.length;
	return OK;
}
Status ListDelete_Sq(SqList &L,int i){//ɾ����λ��i��Ԫ�� 
	if(i<1||i>L.length) return ERROR;
	for(int j=i;j<L.length;j++){
		L.elem[j-1] = L.elem[j];
	} 
	--L.length;
	return OK;
} 
int CleanList(SqList &L){//��ձ�L 
	L.length = 0;
	return OK;
}
int GetLength(SqList L){//��� 
	return (L.length); 
}
int ShowList(SqList L){//�����������Ա��Ԫ�ز���� 
	for(int i=0;i<L.length;i++){
		cout<<L.elem[i]<<" ";
	}
	cout<<endl; 
}
int DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;//�ͷŴ洢�ռ�
  return OK;
}

int main(){
	int i,len;
	ElemType e;
	SqList L;
	if (Initlist_Sq(L)) cout<<"˳����ʼ���ɹ�"<<endl;
	else cout<<"˳����ʼ��ʧ��"<<endl; 
	cout<<"������Ӧ��������������Ӧ�Ĳ���"<<endl;
	int c = -1;
	while(c!=0){
		cout<<"1.�ṩһ��λ�ò���һ��Ԫ�� 2.ɾ���ṩλ�õ�һ��Ԫ�� 3.��� 4.��ȡ�������е�Ԫ�� 5.��ձ� 0. exit"<<endl; 
		cin>>c;
		switch(c){
			case 1:{
				cout<<"������λ�õ���źͲ����Ԫ��"<<endl;
				cin>>i>>e;
				if (ListInsert_Sq(L,i,e)) cout<<"����ɹ�"<<endl;
				else cout<<"����ʧ��"<<endl;
				break;
			}
			case 2:{
				cout<<"������ɾ��Ԫ�ص�λ�����"<<endl;
				cin>>i;
				if (ListDelete_Sq(L,i)) cout<<"ɾ���ɹ�"<<endl;
				else cout<<"ɾ��ʧ��"<<endl;
				break;
			}
			case 3:{
				len = GetLength(L);
				cout<<"��ĳ���Ϊ"<<len<<endl;
				break;
			}
			case 4:{
				ShowList(L);
				break;
			}
			case 5:{
				if (CleanList(L)) cout<<"��ճɹ�"<<endl;
				else cout<<"���ʧ��"<<endl;
				break;
			} 
		}
	}
	if (DestroyList(L)) cout<<"˳���������"<<endl; 
	else cout<<"˳�������ʧ��"<<endl;
	return 0; 
}
