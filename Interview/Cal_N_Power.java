package meituan.bishi1;
/**
 * 给定整x，定义函数A(n) = 1+x+x^2+x^3+……+x^n，（n为>=0的整数）。
 * 已知乘法运算的时间远大于加法运算，输入x、n，如何尽可能快的计算出A(n)。
1）描述思路
2）评估你的算法需要进行多少次乘法运算
3）请用熟悉的语言编程实现
 */
public class Cal_N_Power {
	public static int mX = 2;
	private int mN = 3;
	
	public CalNPower(){
		double res = calFunction(mX,mN);
		System.out.println("计算结果为：" + res);
	}
	
	public double calFunction(int x, int n){
		double sum = 0;
		int xn = 0;
		
		if(n == 0)
			return 1;
		if(n == 1) { 
			return x+1;
		} else {
			xn = cal_N_Power(x,n);    // n>1
			sum = (1-xn)/(1-x);
		} 
		return sum;
	}
	//折半法计算x的n次方，
	public int cal_N_Power(int x, int n) {
		int temp = 0;
		if(n == 0) {
			return 1;
		}
		if(n == 1) {
			return x;
		}
		
		temp += cal_N_Power(x,n/2);  //注意递归得有终止条件
		if((n & 0x1) > 0) { // n为偶数
			return temp*temp;
		} else {
			return x*temp*temp;
		}
	}
}
