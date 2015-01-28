
#define STACK_INIT_SIZE  100;   //�洢�ռ��ʼ������,��Ԫ��Ϊ��λ
#define STACK_INCREMENT  10;    //�洢�ռ��������,��Ԫ��Ϊ��λ

//-------ջ��˳��洢��ʾ------------------
typedef struct {
	SElemType  *base;    //��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType  *top;     //ջ��ָ��
	int  stacksize;      //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
} SqStack;

/*�����������������������ջ��ѹջ��*/

//����һ����ջS
void InitStack(SqStack &S) {

	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) {
		cout<<"����ռ�ʧ�ܣ�"<<endl;
		exit(OVERFLOW);
	}
	
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;  //�ڳ�ʼ��ջʱ�ȷ���һ�������������Ժ�����������������
}

//��ջ��Ϊ�գ�����e����S��ջ��Ԫ��
void GetTop(SqStack S, SElemType &e) {
	
	if(S.top == S.base) {
		cout<<"ջΪ�գ�"<<endl;
		return;
	}
	e = *(S.top-1);
}	

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