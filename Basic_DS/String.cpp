//------���Ķѷ���洢��ʾ------
typedef struct {
	char *ch;       //���ǿմ����򰴴�������洢��������chΪNULL
	int  length;    //������
} HString;

//����һ����ֵ���ڴ�����chars�Ĵ�T
void StrAssign(HString &T,char *chars) {
	int i=0,j;
	char c;
	if(T.ch)
		free(T.ch);
	for(i=0, c=chars; c; ++i,++c) ; //��chars�ĳ���i
	if(!i) {
		T.ch = NULL;
		T.length = 0;
	}
	else {
		if(!(T.ch = (char *)malloc(i*sizeof(char)))) {
			cout<<"���·���ռ�ʧ�ܣ�"<<endl;
			return;
		}
		for(j=0; j<i; ++j) {
			T.ch[j] = chars[j];
		}
		T.length = i;
	}
	cout<<"���ɴ�T��"<<endl;
}


//����S��Ԫ�ظ�������Ϊ���ĳ���
int StrLength(HString S) {
	return S.length;
}

//�Ƚ��������Ĵ�С
//��S>T,�򷵻�ֵ>0����S=T,�򷵻�ֵ=0����S<T,�򷵻�ֵ<0
int StrCompare(HString S,HString T) {
	for(i=0; i<S.length && i<T.length; ++i) {
		if(S.ch[i] != T.ch[i])
			return S.ch[i]-T.ch[i];
	}
	return S.length-T.length
}

//����S���
void ClearString(HString &S) {
	if(S.ch) {
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	count<<"��S�����"<<endl;
}


//�ڴ�S�ĵ�pos���ַ�ǰ���봮T
//��ʼ��������S�ʹ�T�����ڣ�1<StrLength(S)+1
void StrInsert (HString &S, int pos, HString T) {
	int i = 0, j = 0;
	if(pos < 0 || pos > S.length+1) {
		cout<<"λ��ָ�����Ϸ��������¼�飡"<<endl;
		return;
	}
	if(T.length) {    //T�ǿգ������·���ռ䣬����T
		if( !(S.ch =(char *)realloc(S.ch, (S.length+T.length)*sizeof(char)))) {
			cout<<"���·���ռ�ʧ�ܣ�"<<endl;
			return;
		}
		for (i = S.length-1;i >= pos-1 ;--i)    //Ϊ����T�ڳ�λ��
			S.ch[i+T.length] = S.ch[i];
		//S.ch[pos-1..pos+T.length-2] = T.ch[0..T.length-1]   //����T
		for (j=0;j<=T.length-1;++j) {
			S.ch[pos-1+j] = T.ch[j];
		}
			S.length += T.length;
	}
	cout<<"������ϣ�"<<endl;
}

//��T������S1��S2���Ӷ��ɵ��´�
void Concat(HString &T, HString S1, HString S2) {
	if(T.ch) 
		free(T.ch);     //�ͷžɿռ�
	if(!(T.ch=(char *)malloc((S1.length+S2.length)*sizeof(char)))) {
			cout<<"���·���ռ�ʧ�ܣ�"<<endl;
			return;
	}
	T.length = S1.length+S2.length;
	for(int i=0; i<S1.length;++i) {
		T.ch[i] = S1.ch[i];
	}
	for(int j=0; j<S2.length;++j) {
		T.ch[j] = S2.ch[j];
	}

}

//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
HString SubString(HString &Sub, HString S,int pos,int len) {
	if(pos<0 || pos>S.length || len<0 || len>S.length-pos+1) {
		cout<<"ָ�����ݲ�����"<<endl;
		return;
	}
	if(Sub.ch) 
		free(Sub.ch);
	if(!len) {
		Sub.ch = NULL;
		Sub.length = 0;  //���Ӵ�
	}
	else {
		Sub.ch = (char *)malloc(len*sizeof(char));
		for(int k=0; k<len;k++) 
			Sub.ch[k] = S[pos-1+k];
		Sub.length = len;
	}
}
