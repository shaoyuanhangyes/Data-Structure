#include<iostream> 
#define MAXSIZE 100
using namespace std;
typedef int ElemType;
typedef struct{
	ElemType *data;
	int length;
}SqList;
bool Initlist_Sq(SqList &L){//初始化顺序表L 
	L.data = new ElemType[MAXSIZE]; 
//	L.length = 0;
	L.data[1]=11;L.data[2]=94;L.data[3]=32; L.data[4]=40; L.data[5]=90; L.data[6]=80; L.data[7]=46; L.data[8]=21;L.data[9]=69;  
	L.length = 9;
	return 1;
}
bool ListInsert_Sq(SqList &L,int i,ElemType e){//插入表L 
	if((i<1)||(i>L.length+1)) return 0;
	if(L.length==MAXSIZE) return 0;
	for(int j=L.length;j>=i;j--){
		L.data[j+1] = L.data[j];
	}
	L.data[i] = e;
	++L.length;
	return 1;
}
bool ListDelete_Sq(SqList &L,int i){//删除表位置i的元素 
	if(i<1||i>L.length) return 0;
	for(int j=i;j<L.length;j++){
		L.data[j-1] = L.data[j];
	} 
	--L.length;
	return 1;
} 
int CleanList(SqList &L){//清空表L 
	L.length = 0;
	return 1;
}
int GetLength(SqList L){//求表长 
	return (L.length); 
}
int ShowList(SqList L){//遍历整个线性表的元素并输出 
	for(int i=1;i<=L.length;i++){
		cout<<L.data[i]<<" ";
	}
	cout<<endl; 
}
int DestroyList(SqList &L)
{
  if (L.data) delete[]L.data;//释放存储空间
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
	if (Initlist_Sq(L)) cout<<"顺序表初始化成功"<<endl;
	else cout<<"顺序表初始化失败"<<endl; 
	cout<<"输入相应的数字来进行相应的操作"<<endl;
	int c = -1;
	while(c!=0){
		cout<<"1.插入元素 2.删除元素 3.表长 4.遍历元素 5.清空表 6.折半插入排序0. exit"<<endl; 
		cin>>c;
		switch(c){
			case 1:{
				cout<<"请输入位置的序号和插入的元素"<<endl;
				cin>>i>>e;
				if (ListInsert_Sq(L,i,e)) cout<<"插入成功"<<endl;
				else cout<<"插入失败"<<endl;
				break;
			}
			case 2:{
				cout<<"请输入删除元素的位置序号"<<endl;
				cin>>i;
				if (ListDelete_Sq(L,i)) cout<<"删除成功"<<endl;
				else cout<<"删除失败"<<endl;
				break;
			}
			case 3:{
				len = GetLength(L);
				cout<<"表的长度为"<<len<<endl;
				break;
			}
			case 4:{
				ShowList(L);
				break;
			}
			case 5:{
				if (CleanList(L)) cout<<"清空成功"<<endl;
				else cout<<"清空失败"<<endl;
				break;
			}
			case 6:{
				len = GetLength(L);
				InsertSort(L,len); 
				break;
			}  
		}
	}
	if (DestroyList(L)) cout<<"顺序表已销毁"<<endl; 
	else cout<<"顺序表销毁失败"<<endl;
	return 0; 
}
