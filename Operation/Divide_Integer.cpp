#include "stdio.h"
/*求正整数n的划分数*/
int Divide_Integer(int n,int m)
{
	if(n<1 || m<1) 
		return 0;
	if((n==1)||(m==1))
		return 1;
	if (n<m)
		return q(n,n);
	if(n==m)
		return q(n,m-1)+1;

	return q(n,m-1)+q(n-m,m);
}

int main()
{	
	int n ;
	printf("输入一个整数:");
	scanf("%d",&n);
	printf("%d有%d种不同的划分\n",n,Divide_Integer(n,n));
}