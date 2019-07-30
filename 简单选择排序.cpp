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
//	L.length=0;
	L.data[1]=98;L.data[2]=36;L.data[3]=-9; L.data[4]=0; L.data[5]=47; L.data[6]=23; L.data[7]=1; 
//	L.data[8]=8;L.data[9]=10; L.data[10]=7; 
	L.length = 7;
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
//bool ListDelete_Sq(SqList &L,int i){//删除表位置i的元素 
//	if(i<1||i>L.length) return 0;
//	for(int j=i;j<L.length;j++){
//		L.data[j-1] = L.data[j];
//	} 
//	--L.length;
//	return 1;
//} 
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
int DestroyList(SqList &L){
  if (L.data) delete[]L.data;//释放存储空间
  return 1;
}
bool SelectSort(SqList &L,int n){
	int i,j,min;
	for(i=1;i<=n;i++){
		min=i;
		for(j=i+1;j<=n;j++){
			if(L.data[j]<L.data[min]){
				min=j; 
			} 
		}
		if(min!=i){
			L.data[0]=L.data[i];
			L.data[i]=L.data[min];
			L.data[min]=L.data[0];
		}
		for(int k=1;k<=L.length;k++){//一次dk排序后遍历表 观察元素排序变化 
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
		cout<<"1.插入元素 2.删除元素 3.表长 4.遍历元素 5.清空表 6.简单选择排序0. exit"<<endl; 
		cin>>c;
		switch(c){
			case 1:{
				cout<<"请输入位置的序号和插入的元素"<<endl;
				cin>>i>>e;
				if (ListInsert_Sq(L,i,e)) cout<<"插入成功"<<endl;
				else cout<<"插入失败"<<endl;
				break;
			}
//			case 2:{
//				cout<<"请输入删除元素的位置序号"<<endl;
//				cin>>i;
//				if (ListDelete_Sq(L,i)) cout<<"删除成功"<<endl;
//				else cout<<"删除失败"<<endl;
//				break;
//			}
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
				SelectSort(L,len); 
				break;
			}  
		}
	}
	if (DestroyList(L)) cout<<"顺序表已销毁"<<endl; 
	else cout<<"顺序表销毁失败"<<endl;
	return 0; 
}
for(int z=1;z<=L.length;z++){//一次dk排序后遍历表 观察元素排序变化 
		cout<<L.data[z]<<" ";
	}
	cout<<endl; 
