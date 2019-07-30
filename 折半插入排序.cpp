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
//	L.length = 0;
	L.data[1]=11;L.data[2]=94;L.data[3]=32; L.data[4]=40; L.data[5]=90; L.data[6]=80; L.data[7]=46; L.data[8]=21;L.data[9]=69;  
	L.length = 9;
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
bool ListDelete_Sq(SqList &L,int i){//ɾ����λ��i��Ԫ�� 
	if(i<1||i>L.length) return 0;
	for(int j=i;j<L.length;j++){
		L.data[j-1] = L.data[j];
	} 
	--L.length;
	return 1;
} 
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
bool InsertSort(SqList &L,int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){
		L.data[0]=L.data[i];
		low=1;high=i-1;
		while(low<=high){
			mid=(low+high)/2;
			if(L.data[mid]>L.data[0]) high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=high+1;j--)
			L.data[j+1]=L.data[j];
		L.data[high+1]=L.data[0];
		for(int k=1;k<=L.length;k++){
			cout<<L.data[k]<<" ";
	}
	cout<<endl;
	}
	return 1;
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
		cout<<"1.����Ԫ�� 2.ɾ��Ԫ�� 3.�� 4.����Ԫ�� 5.��ձ� 6.�۰��������0. exit"<<endl; 
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
			case 6:{
				len = GetLength(L);
				InsertSort(L,len); 
				break;
			}  
		}
	}
	if (DestroyList(L)) cout<<"˳���������"<<endl; 
	else cout<<"˳�������ʧ��"<<endl;
	return 0; 
}
