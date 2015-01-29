
/*
 * 前后颠倒输入的英文中的单词位置，
 * 标点符号（只可以出现在句尾）位置不变，
 * 如输入“Hello how are you!”输出应该为“you are how Hello!”
 */
public class InvertWords {
	private String hello = "Hello how are you？";
	private String res = "";
	
	public void invertWord(){
		char lastchar = hello.charAt(hello.length()-1);
//		boolean flagg = (lastchar >= 'a' && lastchar <= 'z') 
//							|| (lastchar >='A' && lastchar <= 'Z')
//							|| (lastchar == ' ');
		hello = hello.replace((String.valueOf(lastchar)), "");
		String[] subString = hello.split(" ");  //以空格分割字符串
		for(int i=subString.length-1;i>=0 ;--i) {
			res += subString[i]+" ";
		}
		res = res.trim();    //去掉前后的空格
		res = res + lastchar;
		System.out.println("倒置后的字符串为：" + res);
	}
}
