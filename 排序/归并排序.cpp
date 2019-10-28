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
	L.data[1]=49;L.data[2]=38;L.data[3]=65; L.data[4]=97; L.data[5]=76; L.data[6]=13; L.data[7]=27; 
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
void Merge(SqList &L,int low,int mid,int high){//low=1 high=n表长 
	int i,j,k;
	SqList B;//辅助顺序表B 
	B.data=new ElemType[MAXSIZE];
	for(int k=low;k<=high;k++) B.data[k]=L.data[k];//将L中所有的元素都复制到B中 
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
		if(B.data[i]<=B.data[j]) L.data[k]=B.data[i++];//将B划分为左右半区 从各自半区第一个互相比较 
		else L.data[k]=B.data[j++];//较小的插入到L中 然后后移继续比较大小 直到i超过mid或者j超过high 
	}
	while(i<=mid) L.data[k++]=B.data[i++];//j越界了i还未遍历完 表示左边区剩下的都是大的 
	while(j<=high)  L.data[k++]=B.data[j++];//i越界了j还未遍历完 表示右半区剩下的都是大的 
	//这两个while循环只会有一个会执行 
}
bool MergeSort(SqList &L,int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(L,low,mid);//左半区递归 
		MergeSort(L,mid+1,high);//右半区递归 
		Merge(L,low,mid,high);
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
		cout<<"1.插入元素 2.删除元素 3.表长 4.遍历元素 5.清空表 6.归并排序0. exit"<<endl; 
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
				MergeSort(L,1,len); 
				break;
			}  
		}
	}
	if (DestroyList(L)) cout<<"顺序表已销毁"<<endl; 
	else cout<<"顺序表销毁失败"<<endl;
	return 0; 
}
