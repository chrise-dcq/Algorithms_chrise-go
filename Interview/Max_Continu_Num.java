
/*
 * 用递归算法计算一个字符串中最大的连续字符个数。
 * 比如aaabbcc 输出3，aabbcc 输出2，abc输出1
 * */
public class Max_Continu_Num {
	
	public int getMax(String str){
		int len = str.length();
		if(1 == len) {
			return 1;
		}
		int x = calFromthis(str);
		String subString = str.substring(1, len);

		int getSublen = getMax(subString);
		if(x > getSublen) {
			return getSublen+1;
		} else {
			return getSublen;
		}
	}
	//计算每段子串的第一个字符的重复数
	public int calFromthis(String substring) {
		int count = 1;
		char first = substring.charAt(0);
		for(int i=1; i < substring.length(); i++) {
			if(first == substring.charAt(i)) {
				count++;
			} else{
				break;
			}
		}
		return count;
	}
}
