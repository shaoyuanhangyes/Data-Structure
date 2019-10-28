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
Status Initlist_Sq(SqList &L){//初始化顺序表L 
	L.elem = new ElemType[MAXSIZE]; 
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}
Status ListInsert_Sq(SqList &L,int i,ElemType e){//插入表L 
	if((i<1)||(i>L.length+1)) return ERROR;
	if(L.length==MAXSIZE) return OVERFLOW;
	for(int j=L.length;j>=i;j--){
		L.elem[j] = L.elem[j-1];
	}
	L.elem[i-1] = e;
	++L.length;
	return OK;
}
Status ListDelete_Sq(SqList &L,int i){//删除表位置i的元素 
	if(i<1||i>L.length) return ERROR;
	for(int j=i;j<L.length;j++){
		L.elem[j-1] = L.elem[j];
	} 
	--L.length;
	return OK;
} 
int CleanList(SqList &L){//清空表L 
	L.length = 0;
	return OK;
}
int GetLength(SqList L){//求表长 
	return (L.length); 
}
int ShowList(SqList L){//遍历整个线性表的元素并输出 
	for(int i=0;i<L.length;i++){
		cout<<L.elem[i]<<" ";
	}
	cout<<endl; 
}
int DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;//释放存储空间
  return OK;
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
		cout<<"1.提供一个位置插入一个元素 2.删除提供位置的一个元素 3.求表长 4.获取表内所有的元素 5.清空表 0. exit"<<endl; 
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
		}
	}
	if (DestroyList(L)) cout<<"顺序表已销毁"<<endl; 
	else cout<<"顺序表销毁失败"<<endl;
	return 0; 
}
