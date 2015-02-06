//二叉树先序、中序、后序遍历的非递归算法

#define MAXSIZE 100

typedef struct 
{
	BiTree Elem[MAXSIZE];
	int top;
} SqStack;

//先序遍历非递归算法
void PreOrderTraverse_Unrec(BiTree T) {
	SqStack S;
	StackInit(S);
	p = T;
	
	while(p != null) || !StackEmpty(S)) {
		while(p != null) {    //遍历左子树
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

//中序遍历非递归算法
void InOrderTraverse_Unrec(BiTree T) {
	SqStack S;
	StackInit(S);
	p = T;
	
	while(p != null) || !StackEmpty(S)) {
		while(p != null) {    //遍历左子树
			Push(S,p);
			p = p->lchild;
		}
		if(!StackEmpty(S)) {
			p = Pop(S);
			Visit(p->data);   //访问根节点
			p = p->rchild;    //通过下一次循环实现右子树遍历
		}
	}
} //InOrderTraverse_Unrec

//后序遍历非递归算法
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
		while (p != null) {  //遍历左子树
			x.ptr = p;
			x.tag = L;       //标记为左子树
			Push(S,x);
			p = p->lchild;
		}
		
		while(!StackEmpty(S) && S.Elem[S.top].tag == R) {
			x = Pop(S);
			p = x.ptr;
			Visit(p->data);  //tag为R，表示右子树访问完毕，故访问根结点
		}
		
		if(!StackEmpty(S)) {
			S.Elem[S.top].tag = R;   //遍历右子树
			p = S.Elem[S.top].ptr->rchild;
		}
	}
}//PostOrderTraverse_Unrec


//插入元素e为新的栈顶元素
void Push(SqStack &S, SElemType e) {
	
	if(S.top - S.base >= S.stacksize) {    //栈满，追加存储空间
		S.base = (SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
		if(!S.base) {
			cout<<"分配空间失败！"<<endl;
			exit(OVERFLOW);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top++ = e; 
}			


//若栈不空，则删除S的栈顶元素，用e返回其值		
void Pop(SqStack *S, SElemType &e) {
	if(S.top == S.base) {
		cout<<"栈为空！"<<endl;
		return;
	}
	e = * --S.top;
}













