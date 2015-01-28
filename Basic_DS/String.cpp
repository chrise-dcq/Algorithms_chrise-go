//------串的堆分配存储表示------
typedef struct {
	char *ch;       //若是空串，则按串长分配存储区，否则ch为NULL
	int  length;    //串长度
} HString;

//生成一个其值等于串常量chars的串T
void StrAssign(HString &T,char *chars) {
	int i=0,j;
	char c;
	if(T.ch)
		free(T.ch);
	for(i=0, c=chars; c; ++i,++c) ; //求chars的长度i
	if(!i) {
		T.ch = NULL;
		T.length = 0;
	}
	else {
		if(!(T.ch = (char *)malloc(i*sizeof(char)))) {
			cout<<"重新分配空间失败！"<<endl;
			return;
		}
		for(j=0; j<i; ++j) {
			T.ch[j] = chars[j];
		}
		T.length = i;
	}
	cout<<"生成串T！"<<endl;
}


//返回S的元素个数，称为串的长度
int StrLength(HString S) {
	return S.length;
}

//比较两个串的大小
//若S>T,则返回值>0；若S=T,则返回值=0；若S<T,则返回值<0
int StrCompare(HString S,HString T) {
	for(i=0; i<S.length && i<T.length; ++i) {
		if(S.ch[i] != T.ch[i])
			return S.ch[i]-T.ch[i];
	}
	return S.length-T.length
}

//将串S清空
void ClearString(HString &S) {
	if(S.ch) {
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	count<<"串S被清空"<<endl;
}


//在串S的第pos个字符前插入串T
//初始条件：串S和串T都存在，1<StrLength(S)+1
void StrInsert (HString &S, int pos, HString T) {
	int i = 0, j = 0;
	if(pos < 0 || pos > S.length+1) {
		cout<<"位置指定不合法，请重新检查！"<<endl;
		return;
	}
	if(T.length) {    //T非空，则重新分配空间，插入T
		if( !(S.ch =(char *)realloc(S.ch, (S.length+T.length)*sizeof(char)))) {
			cout<<"重新分配空间失败！"<<endl;
			return;
		}
		for (i = S.length-1;i >= pos-1 ;--i)    //为插入T腾出位置
			S.ch[i+T.length] = S.ch[i];
		//S.ch[pos-1..pos+T.length-2] = T.ch[0..T.length-1]   //插入T
		for (j=0;j<=T.length-1;++j) {
			S.ch[pos-1+j] = T.ch[j];
		}
			S.length += T.length;
	}
	cout<<"插入完毕！"<<endl;
}

//用T返回由S1和S2连接而成的新串
void Concat(HString &T, HString S1, HString S2) {
	if(T.ch) 
		free(T.ch);     //释放旧空间
	if(!(T.ch=(char *)malloc((S1.length+S2.length)*sizeof(char)))) {
			cout<<"重新分配空间失败！"<<endl;
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

//用Sub返回串S的第pos个字符起长度为len的子串
HString SubString(HString &Sub, HString S,int pos,int len) {
	if(pos<0 || pos>S.length || len<0 || len>S.length-pos+1) {
		cout<<"指定数据不合理！"<<endl;
		return;
	}
	if(Sub.ch) 
		free(Sub.ch);
	if(!len) {
		Sub.ch = NULL;
		Sub.length = 0;  //空子串
	}
	else {
		Sub.ch = (char *)malloc(len*sizeof(char));
		for(int k=0; k<len;k++) 
			Sub.ch[k] = S[pos-1+k];
		Sub.length = len;
	}
}
