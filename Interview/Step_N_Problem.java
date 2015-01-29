/*
 * 台阶问题：有n个台阶，每次可以踏出一个台阶，或2个，问有多少种走法？
 * 思路一：动态规划
 * 思路二：非递归——
 * */
public class Step_N_Problem {
	private static int STEP_N = 5;
	
	public Step_N_Problem(){
		int sum = calSteps(STEP_N);
		System.out.println("结果为：" + sum);
	}
	
	public int calSteps(int n){
		int steps = 0;
		
		if(n == 1) 
			return 1;
		if(n == 2)
			return 2;
		
		int oneStep = 2;
		int twoStep = 1;
		for(int i =3; i<=n; i++) {
			steps = oneStep + twoStep;
			twoStep = oneStep;
			oneStep = steps;
		}
		return steps;
	}
}
