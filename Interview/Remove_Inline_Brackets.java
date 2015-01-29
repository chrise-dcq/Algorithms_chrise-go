
/*
 *给定一个如下格式的字符串，(1,(2,3),(4,(5,6),7))括号内的元素可以是数组，
 *也可以是另一个括号，请实现一个算法消除嵌套的括号，
 *比如把上面的表达式变成：（1,2,3,4,5,6,7），如果表达式有误请报错
 */
public class Remove_Inline_Brackets {
	String res = null;
	String str = new String("(1,(2,3),(4,(5,6),7))"); 
	public void result(){
		String result = removeBrackets();
		System.out.println("输出结果为：" + result);
	}
	

	public String removeBrackets() {
		int n = str.length();
		char[] temp = new char[n];
		char[] stack = new char[n];       //用来进行括号匹配的栈
 		int i = 0;
 		int j = 0;
 		int top = -1;
//		while(str.charAt(i) != '\0') {
 		while(i<str.length()) {
			if(str.charAt(i) != '(' && str.charAt(i) != ')')
				temp[++j] = str.charAt(i);
			else {
				if(top == -1 || str.charAt(i) == stack[top]) {   //初始和输入为'('时入栈
					System.out.println("str.charAt(i):"+str.charAt(i));
					stack[++top] = str.charAt(i);
				} else {
					top--;         //栈不为空，且新输入为')'，则将栈顶出栈，消掉一对括号。
				}
			}
			i++;
		}
		
		if(top != -1) {
			System.out.println("表达式有误！");
		} else {
			temp[0] = '(';
			temp[++j] = ')';
			res = new String(temp);
		}
		return res;
	}

}
