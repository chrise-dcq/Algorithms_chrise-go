

/*递归方法求阶乘*/
int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n-1);
}
