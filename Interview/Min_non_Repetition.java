
/*
 * 题目要求：对给定的任意一正整数，求大于它的最小非“重复数（即相邻两位相同）”
 *思路：
 *(1)先对它加1；注意是先加1，这样可减少后续对最低位的操作
 *（2）从高位开始，自左向右遍历，判断是否有邻位相同：
 *			如果没有重复元素，则输出结果；
 *（3）有重复元素，但重复元素不为‘9’，低位加1，后面置0，输出结果；
 *（4）有重复元素，且重复元素为‘9’，产生进位，进位后再递归判断是否为重复数，
 *						是就再重头处理，不是就输出。
 * 
*/
public class Min_non_Repetition {
	int len = 0;
	int flag = 0;
	char mNumbers[] = null;
	int i = 0;
	char b = '0';
	int num = 5641099;     //9898989899
	
	public Min_non_Repetition(){
		String cin ="0"+String.valueOf(num+1);
		mNumbers = cin.toCharArray();      //{'0','2','9','9','9'...}
		len = mNumbers.length;
		System.out.println("数据为：" + String.valueOf(mNumbers));
		String res = traverse();
		System.out.println("结果为：" + res);
	}
	
	public String traverse(){
		isRepetition(mNumbers);   //判断是否为重复数
		return String.valueOf(mNumbers);
	}
	
	public void isRepetition(char mNumbers[]){
		for(i=1; i < len-1; i++) {
			if(mNumbers[i+1] == mNumbers[i]) {
				//有重复元素
				if(mNumbers[i] != '9') {
					//有重复元素且重复元素不为9
					mNumbers[i+1] += 1;    //相同的低位加1
				} 
				else {
					//有重复元素且重复元素为9,会产生进位
					mNumbers[i+1] = '1';
					mNumbers[i] = '0';
					mNumbers[i-1] += 1;
				} 
				//处理后面的数
				suffixHandle(mNumbers);  // 后边置0101...
				isRepetition(mNumbers);   // 递归，判断进位后会不会导致新的重复数
				break;  
			} 
		}
	}
	//后缀处理
	public void suffixHandle(char[] mNum){
		if(mNum[i+1] != '0') { 
			for(int k=i+2; k<len; k++) {
				mNum[k] = b;
				b = (b == '0')? '1':'0';
			}
		} else {
			b += 1;
			for(int k=i+2; k<len; k++) {
				mNum[k] = b;
				b = (b == '0')? '1':'0';
			}
		}
	}
	
}
