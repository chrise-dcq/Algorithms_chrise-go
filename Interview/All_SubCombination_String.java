import java.util.ArrayList;
import java.util.List;

/**
 *输入一个字符串，输出该字符串中字符的所有组合。
 *举个例子，如果输入abc，它的组合有a、b、c、ab、ac、bc、abc。
 * 来源：Ali、Baidu 面试题
 */
public class All_SubCombination_String {
	
	public void combination(String str){  
		char[] strs = str.toCharArray();
        if(strs==null|| strs.length==0) {  
            return ;  
        }  
        List<Character> list = new ArrayList();  
        for(int i=1; i <= strs.length; i++) {  
            combine(strs,0,i,list);  
        }  
    }  
    //从字符数组中第begin个字符开始挑选number个字符加入list中  
    public static void combine(char[] cs,int begin,int number,List<Character> list){  
        if(number==0){  
            System.out.println(list.toString());  
            return ;  
        }  
        if(begin==cs.length){  
        	
            return;  
        }  
        list.add(cs[begin]);  
        combine(cs,begin+1,number-1,list); 
        
        list.remove((Character)cs[begin]);  
        combine(cs,begin+1,number,list);  
    }  
}
