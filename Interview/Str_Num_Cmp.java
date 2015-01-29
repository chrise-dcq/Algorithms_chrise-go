
/*
 * 设计strnumcmp函数，比较字符串的大小。功能为:
（a）当字符串中有数字时，以数字大小为准;
（b）对于只有其中一个字符串有数字的情况，仍然沿用strcmp方式。

 * */
public class Str_Num_Cmp {
	String str1 = new String("as24dfss13fsda");
	String str2 = new String("abc546sfada");
	int Value_s1=0;
	int Value_s2=0;
	
	public int strnumcmp(){
		int m = 0;
		int n = 0;
		for(int i=0;i<str1.length(); i++) {
			if(str1.charAt(i)>='0' && str1.charAt(i)<='9') {   //
				m++;
				Value_s1 =  Value_s1*10 +Integer.parseInt(String.valueOf(str1.charAt(i)));
			}
		}
		for(int j=0;j<str2.length(); j++) {
			if(str2.charAt(j)>='0' && str2.charAt(j)<='9') {   //
				n++;
				Value_s2 =  Value_s2*10 +Integer.parseInt(String.valueOf(str2.charAt(j)));
			}
		}
		if(m !=0 && n != 0) {              //将两个字符串中的数字进行比较大小
			System.out.println("字符串1中的数值: "+Value_s1+", 字符串2中的数值: "+Value_s2);
			return Value_s1 == Value_s2 ? 0 : (Value_s1 < Value_s2 ? -1:1);
		} else {
			return str1.compareTo(str2);
		}
	}
	
	public void PrintResult(){
		int flag = strnumcmp();
		if (flag == 0) {
			System.out.println("字符串str1 等于 字符串str2！");
		} else if (flag > 0) {
			System.out.println("字符串str1 大于 字符串str2！");
		} else if (flag < 0) {
			System.out.println("字符串str1 小于 字符串str2！");
		}
	}
}
		
			
