/*
fibonacci����
�ص㣺 
             f(n) = f(n-1) + f(n-2)    if n>1 
             f(n) = n                  if n = 0,1 
*/


//�ݹ�ⷨ
int fibonacci(int n)
{
	if(n <= 0) 
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}


//�ǵݹ�ⷨ
int[] fibonacci(int n) { 
    int fib[n]={0}; 

    fib[0]=0; 
    fib[1]=1; 

    for(int i=2;i<N;i++) 
	    fib[i] = fib[i-1] + fib[i-2]; 

    return fib;
}


 