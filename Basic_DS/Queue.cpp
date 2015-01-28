#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int QElemType; 

//----单链队列——队列的链式存储结构----------
typedef struct QNode {    // 链队列的结点
	QElemType     data;
	struct QNode  *next;
} QNode,*QueuePtr;

typedef struct {         //队列
	QueuePtr  front;     //队头指针
	QueuePtr  rear;		 //队尾指针
} LinkQueue;

//-------基本操作的函数原型说明---------------
void InitQueue(LinkQueue &Q);
void DestoryQueue(LinkQueue &Q);
void ClearQueue(LinkQueue &Q);
void QueueEmpty(LinkQueue Q);
int  QueueLength(LinkQueue Q);
void GetHead(LinkQueue Q,QElemType e);
void EnQueue(LinkQueue &Q,QElemType e);
void DeQueue(LinkQueue &Q,QElemType &e);
//void QueueTraverse(LinkQueue Q,visit());

//构造一个空队列Q
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) {
		cout<<"存储分配失败！"<<endl;
		return;
	}
	Q.front->next = NULL;
	cout<<"空队列构造完成！"<<endl;
}

//销毁队列Q
void DestoryQueue(LinkQueue &Q) {
	while(Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

//插入元素e为Q的新的队尾元素
void EnQueue(LinkQueue &Q,QElemType e) {
	QNode *p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) {
		cout<<"存储分配失败！"<<endl;
		return;
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

//若队列不为空，则删除Q的队头元素，用e返回其值
void DeQueue(LinkQueue &Q, QElemType &e) {
	if(Q.front == Q.rear) {
		cout<<"队列为空！"<<endl;
		return;
	}
	QNode *p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) {
		cout<<"存储分配失败！"<<endl;
		return;
	}
	p = Q.front->next;  //Q是头结点，p指向对列第一个元素
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) {
		Q.rear = Q.front;
	}
	free(p);
}

//打印队列
void PrintQueue(LinkQueue &Q) {
	if(Q.front == Q.rear) 
		cout<<"队列为空！"<<endl;
	while(Q.front != Q.rear) {
		cout<<Q.front->next->data<<"--";
		Q.front = Q.front->next;
	}
	cout<<endl;
}

int main() {
	int num=0,i,n;
	int node;
	LinkQueue Q;
	InitQueue(Q);

	cout<<"请指定队列中的元素个数：";
	cin>>n;
	cout<<"请输入"<<n<<"数据：";
	for(i=1; i<=n; i++) {
		cin>>num;
		EnQueue(Q,num);
	}
	PrintQueue(Q);

	cout<<"删除队列头元素：";
	DeQueue(Q,node);
	cout<<"删除的数据为:"<<node<<endl;
	cout<<"队列更新为:";
	PrintQueue(Q);
	return 0;
}