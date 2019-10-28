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
	L.data[1]=49;L.data[2]=38;L.data[3]=65; L.data[4]=97; L.data[5]=76; L.data[6]=13; L.data[7]=27; 
//	L.data[8]=8;L.data[9]=10; L.data[10]=7; 
	L.length = 7;
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
int DestroyList(SqList &L){
  if (L.data) delete[]L.data;//�ͷŴ洢�ռ�
  return 1;
}
void Merge(SqList &L,int low,int mid,int high){//low=1 high=n�� 
	int i,j,k;
	SqList B;//����˳���B 
	B.data=new ElemType[MAXSIZE];
	for(int k=low;k<=high;k++) B.data[k]=L.data[k];//��L�����е�Ԫ�ض����Ƶ�B�� 
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
		if(B.data[i]<=B.data[j]) L.data[k]=B.data[i++];//��B����Ϊ���Ұ��� �Ӹ��԰�����һ������Ƚ� 
		else L.data[k]=B.data[j++];//��С�Ĳ��뵽L�� Ȼ����Ƽ����Ƚϴ�С ֱ��i����mid����j����high 
	}
	while(i<=mid) L.data[k++]=B.data[i++];//jԽ����i��δ������ ��ʾ�����ʣ�µĶ��Ǵ�� 
	while(j<=high)  L.data[k++]=B.data[j++];//iԽ����j��δ������ ��ʾ�Ұ���ʣ�µĶ��Ǵ�� 
	//������whileѭ��ֻ����һ����ִ�� 
}
bool MergeSort(SqList &L,int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(L,low,mid);//������ݹ� 
		MergeSort(L,mid+1,high);//�Ұ����ݹ� 
		Merge(L,low,mid,high);
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
		cout<<"1.����Ԫ�� 2.ɾ��Ԫ�� 3.�� 4.����Ԫ�� 5.��ձ� 6.�鲢����0. exit"<<endl; 
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
				MergeSort(L,1,len); 
				break;
			}  
		}
	}
	if (DestroyList(L)) cout<<"˳���������"<<endl; 
	else cout<<"˳�������ʧ��"<<endl;
	return 0; 
}
