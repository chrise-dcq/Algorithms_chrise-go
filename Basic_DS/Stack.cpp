
#define STACK_INIT_SIZE  100;   //存储空间初始分配量,以元素为单位
#define STACK_INCREMENT  10;    //存储空间分配增量,以元素为单位

//-------栈的顺序存储表示------------------
typedef struct {
	SElemType  *base;    //在栈构造之前和销毁之后，base的值为NULL
	SElemType  *top;     //栈顶指针
	int  stacksize;      //当前已分配的存储空间，以元素为单位
} SqStack;

/*基本操作：创建、输出、出栈、压栈、*/

//构造一个空栈S
void InitStack(SqStack &S) {

	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) {
		cout<<"分配空间失败！"<<endl;
		exit(OVERFLOW);
	}
	
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;  //在初始化栈时先分配一个基本容量，以后如果不够再逐段扩大
}

//若栈不为空，则用e返回S的栈顶元素
void GetTop(SqStack S, SElemType &e) {
	
	if(S.top == S.base) {
		cout<<"栈为空！"<<endl;
		return;
	}
	e = *(S.top-1);
}	

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