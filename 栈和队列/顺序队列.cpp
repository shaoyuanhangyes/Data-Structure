#include<iostream>
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct{
	ElemType data[Maxsize];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue &Q){//初始化队列 首指针等于尾指针 这也是队列为空的标志 
	Q.front=Q.rear=0;
}
bool EnQueue(SqQueue &Q,ElemType e){
	if(Q.rear=Maxsize) return 0;//队满
	 
}
int main(){
	SqQueue Q;
	ElemType e;
	return 0;
}
