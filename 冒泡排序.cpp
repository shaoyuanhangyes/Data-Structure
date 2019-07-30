#include<iostream> 
#define MAXSIZE 100
using namespace std;
typedef int ElemType;
typedef struct{
	ElemType *data;
	int length;
}SqList;
bool Initlist_Sq(SqList &L){//��ʼ��˳���L 
	L.data = new ElemType[MAXSIZE]; 
//	L.length=0;
	L.data[1]=98;L.data[2]=36;L.data[3]=-9; L.data[4]=0; L.data[5]=47; L.data[6]=23; 
//	L.data[7]=1; L.data[8]=8;L.data[9]=10; L.data[10]=7; 
	L.length = 6;
	return 1;
}
bool ListInsert_Sq(SqList &L,int i,ElemType e){//�����L 
	if((i<1)||(i>L.length+1)) return 0;
	if(L.length==MAXSIZE) return 0;
	for(int j=L.length;j>=i;j--){
		L.data[j+1] = L.data[j];
	}
	L.data[i] = e;
	++L.length;
	return 1;
}
//bool ListDelete_Sq(SqList &L,int i){//ɾ����λ��i��Ԫ�� 
//	if(i<1||i>L.length) return 0;
//	for(int j=i;j<L.length;j++){
//		L.data[j-1] = L.data[j];
//	} 
//	--L.length;
//	return 1;
//} 
int CleanList(SqList &L){//��ձ�L 
	L.length = 0;
	return 1;
}
int GetLength(SqList L){//��� 
	return (L.length); 
}
int ShowList(SqList L){//�����������Ա��Ԫ�ز���� 
	for(int i=1;i<=L.length;i++){
		cout<<L.data[i]<<" ";
	}
	cout<<endl; 
}
int DestroyList(SqList &L)
{
  if (L.data) delete[]L.data;//�ͷŴ洢�ռ�
  return 1;
}
void Swap(int x,int y){
	int t=y;
	y=x;x=t;
}
bool BubbleSort(SqList &L,int n){
	
	for(int i=1;i<n;i++){
		int s=0;
		for(int j=n;j>i;j--){
			if(L.data[j-1]>L.data[j]) swap(L.data[j-1],L.data[j]);//�������С��ǰ��� ����λ�� Ȼ���ٸ�ǰ��ıȽ� 
			s=1;
		}
		for(int k=1;k<=L.length;k++){
			cout<<L.data[k]<<" ";
	}
	cout<<endl;
		if(s==0) return 1;
	}
	
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
		cout<<"1.����Ԫ�� 2.ɾ��Ԫ�� 3.�� 4.����Ԫ�� 5.��ձ� 6.ð������0. exit"<<endl; 
		cin>>c;
		switch(c){
			case 1:{
				cout<<"������λ�õ���źͲ����Ԫ��"<<endl;
				cin>>i>>e;
				if (ListInsert_Sq(L,i,e)) cout<<"����ɹ�"<<endl;
				else cout<<"����ʧ��"<<endl;
				break;
			}
//			case 2:{
//				cout<<"������ɾ��Ԫ�ص�λ�����"<<endl;
//				cin>>i;
//				if (ListDelete_Sq(L,i)) cout<<"ɾ���ɹ�"<<endl;
//				else cout<<"ɾ��ʧ��"<<endl;
//				break;
//			}
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
			case 6:{
				len = GetLength(L);
				BubbleSort(L,len); 
				break;
			}  
		}
	}
	if (DestroyList(L)) cout<<"˳���������"<<endl; 
	else cout<<"˳�������ʧ��"<<endl;
	return 0; 
}
