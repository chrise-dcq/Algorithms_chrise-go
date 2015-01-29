
/*
 * 使用c/c++编写函数，实现字符串反转，
 * 要求不使用任何系统函数，且时间复杂度最小，
 * 函数原型：char* reverse_str(char* str)    (Souhu2010)
 * */
public class Reverse_String {
	String str = new String("abdcceba");
	
	public void reverse_str_result(){
		String res = null;
		res = reverse_str(str);
		System.out.println("结果为： " +res);
	}
	
	public String reverse_str(String str){
		this.str = str;
		int len = str.length();
		char[] chStr = str.toCharArray();
		
		for(int i=0,j=len-1; i < j; i++,j--) {
			chStr[i] ^= chStr[j];
			chStr[j] ^= chStr[i];
			chStr[i] ^= chStr[j];
		}
		return new String(chStr);
	}
}
