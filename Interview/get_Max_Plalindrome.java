
/*
 * 有一个长度为N(N很大)的字符串，求其最大回文字符串。
 这里的解法是最直接粗暴的一种，还有更好的办法
 * */
public class get_Max_Plalindrome {
	String str = "ababcfcba";
	char[] a = str.toCharArray();
	int len = a.length;
	
	public void getSub(){
		int wanthuiwenlen = 0;
		String wantSubString  = "";
		if(len == 1) {
			System.out.println("字符串只有一位，不是回文");
			return ;
		}
		for(int i=0; i<len; i++){
			for(int j=len-1; j>i; j--){
				String subString = str.substring(i, j+1);
				if(isHuiWen(subString)) {
					//如果str[i:j]是回文
					int huiwen_len = subString.length();
					if(huiwen_len > wanthuiwenlen){
						wanthuiwenlen = huiwen_len;
						wantSubString = subString;
					}
				}
			}
		}
		System.out.println("最长回文为：" +wantSubString );
	}
	
	//判断给定的字符串是否为回文
	public boolean isHuiWen(String string) {
		int subLen = string.length();
		int m = 0;
		int n = subLen-1;
		
		StringBuilder temp = new StringBuilder(string);
		String reverseString  = temp.reverse().toString().trim();
		System.out.println("reverseString:"+reverseString+", string:"+string);
		return reverseString.equals(string.trim());
	}
	
}
