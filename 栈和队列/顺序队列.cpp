#include<iostream>
using namespace std;
#define Maxsize 100
typedef char ElemType;
typedef struct{
	ElemType data[Maxsize];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue &Q){//��ʼ������ ��ָ�����βָ�� ��Ҳ�Ƕ���Ϊ�յı�־ 
	Q.front=Q.rear=0;
}
bool EnQueue(SqQueue &Q,ElemType e){
	if(Q.rear=Maxsize) return 0;//����
	 
}
int main(){
	SqQueue Q;
	ElemType e;
	return 0;
}
