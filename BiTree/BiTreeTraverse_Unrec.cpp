//�������������򡢺�������ķǵݹ��㷨

#define MAXSIZE 100

typedef struct 
{
	BiTree Elem[MAXSIZE];
	int top;
} SqStack;

//��������ǵݹ��㷨
void PreOrderTraverse_Unrec(BiTree T) {
	SqStack S;
	StackInit(S);
	p = T;
	
	while(p != null) || !StackEmpty(S)) {
		while(p != null) {    //����������
			Visit(p->data);
			Push(S,p);
			p = p->lchild;
		}
		if(!StackEmpty(S)) {
			p = Pop(S);
			p = p->rchild;
		}
	}
} //PreOrderTraverse_Unrec

//��������ǵݹ��㷨
void InOrderTraverse_Unrec(BiTree T) {
	SqStack S;
	StackInit(S);
	p = T;
	
	while(p != null) || !StackEmpty(S)) {
		while(p != null) {    //����������
			Push(S,p);
			p = p->lchild;
		}
		if(!StackEmpty(S)) {
			p = Pop(S);
			Visit(p->data);   //���ʸ��ڵ�
			p = p->rchild;    //ͨ����һ��ѭ��ʵ������������
		}
	}
} //InOrderTraverse_Unrec

//��������ǵݹ��㷨
#define MAXSIZE 100
typedef enum{L,R} tagtype;
typedef struct 
{
	BiTree ptr;
	tagtype tag;
} StackNode;

typedef struct 
{
	StackNode Elem[MAXSIZE];
	int top;
} SqStack;

void PostOrderTraverse_Unrec(BiTree T) {
	SqStack S;
	StackNode x;
	StackInit(S);
	p = T;

	do {
		while (p != null) {  //����������
			x.ptr = p;
			x.tag = L;       //���Ϊ������
			Push(S,x);
			p = p->lchild;
		}
		
		while(!StackEmpty(S) && S.Elem[S.top].tag == R) {
			x = Pop(S);
			p = x.ptr;
			Visit(p->data);  //tagΪR����ʾ������������ϣ��ʷ��ʸ����
		}
		
		if(!StackEmpty(S)) {
			S.Elem[S.top].tag = R;   //����������
			p = S.Elem[S.top].ptr->rchild;
		}
	}
}//PostOrderTraverse_Unrec


//����Ԫ��eΪ�µ�ջ��Ԫ��
void Push(SqStack &S, SElemType e) {
	
	if(S.top - S.base >= S.stacksize) {    //ջ����׷�Ӵ洢�ռ�
		S.base = (SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
		if(!S.base) {
			cout<<"����ռ�ʧ�ܣ�"<<endl;
			exit(OVERFLOW);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top++ = e; 
}			


//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ		
void Pop(SqStack *S, SElemType &e) {
	if(S.top == S.base) {
		cout<<"ջΪ�գ�"<<endl;
		return;
	}
	e = * --S.top;
}













