#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int QElemType; 

//----�������С������е���ʽ�洢�ṹ----------
typedef struct QNode {    // �����еĽ��
	QElemType     data;
	struct QNode  *next;
} QNode,*QueuePtr;

typedef struct {         //����
	QueuePtr  front;     //��ͷָ��
	QueuePtr  rear;		 //��βָ��
} LinkQueue;

//-------���������ĺ���ԭ��˵��---------------
void InitQueue(LinkQueue &Q);
void DestoryQueue(LinkQueue &Q);
void ClearQueue(LinkQueue &Q);
void QueueEmpty(LinkQueue Q);
int  QueueLength(LinkQueue Q);
void GetHead(LinkQueue Q,QElemType e);
void EnQueue(LinkQueue &Q,QElemType e);
void DeQueue(LinkQueue &Q,QElemType &e);
//void QueueTraverse(LinkQueue Q,visit());

//����һ���ն���Q
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) {
		cout<<"�洢����ʧ�ܣ�"<<endl;
		return;
	}
	Q.front->next = NULL;
	cout<<"�ն��й�����ɣ�"<<endl;
}

//���ٶ���Q
void DestoryQueue(LinkQueue &Q) {
	while(Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

//����Ԫ��eΪQ���µĶ�βԪ��
void EnQueue(LinkQueue &Q,QElemType e) {
	QNode *p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) {
		cout<<"�洢����ʧ�ܣ�"<<endl;
		return;
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

//�����в�Ϊ�գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
void DeQueue(LinkQueue &Q, QElemType &e) {
	if(Q.front == Q.rear) {
		cout<<"����Ϊ�գ�"<<endl;
		return;
	}
	QNode *p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) {
		cout<<"�洢����ʧ�ܣ�"<<endl;
		return;
	}
	p = Q.front->next;  //Q��ͷ��㣬pָ����е�һ��Ԫ��
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) {
		Q.rear = Q.front;
	}
	free(p);
}

//��ӡ����
void PrintQueue(LinkQueue &Q) {
	if(Q.front == Q.rear) 
		cout<<"����Ϊ�գ�"<<endl;
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

	cout<<"��ָ�������е�Ԫ�ظ�����";
	cin>>n;
	cout<<"������"<<n<<"���ݣ�";
	for(i=1; i<=n; i++) {
		cin>>num;
		EnQueue(Q,num);
	}
	PrintQueue(Q);

	cout<<"ɾ������ͷԪ�أ�";
	DeQueue(Q,node);
	cout<<"ɾ��������Ϊ:"<<node<<endl;
	cout<<"���и���Ϊ:";
	PrintQueue(Q);
	return 0;
}