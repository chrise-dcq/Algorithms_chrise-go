
/*
 * 题目描述： 
设有n个正整数，将它们联接成一排，组成一个最小的多位整数。  
程序输入：n个数 
程序输出：联接成的多位数    
例如：  
n=2时，2个整数32，321连接成的最小整数为：32132，  
n=4时，4个整数55，31，312, 33 联接成的最小整数为：312313355   
*/
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Connect_Integer_Min {
	String strs = "312 31 55 33 5";
	int n = 0;
	List<String> numList = new ArrayList<String>();
	String numOneByOne = null;
	
	//将字符串分割成单个字符串，每个字符串包含一个整数。
	public void connectIntegers() {
		String[] temp = strs.split(" ");   //将"55 31 312 33"分割成"55"、"31"、"312"、"33"
		for(int k=0; k<temp.length; k++) {
			numList.add(temp[k]);          //将他们都添加到集合List<String>中，以便集中操作
		}
		Collections.sort(numList);  // 将list中的String进行排序："31"、"312"、"33"、"55"
		String res = connectToMin(numList);
		System.out.println("结果为："+res);
	}
	//递归思想
	public String connectToMin(List<String> numList){
		if(numList.size() == 0) {   //递归的结束条件
			return "";
		}
		//第一步：从List<String>中挑选出所有String中最适合做高位的元素，
		//注意不一定是第1个元素就一定适合做高位，还得进行判断
		numOneByOne = getMinNumber(numList);
		//第二步：将取出的元素从List<String>中移除，以进行下一次的筛选
		numList.remove(numOneByOne);
		//第三步：递归地取出从高位到低位的元素，并联接
		return numOneByOne + connectToMin(numList);
	}
	//从排好序的list的最前两个数中取出一个最适合作最高位的元素
	public String getMinNumber(List<String> numList) {
		if(numList.size() == 1) {   //
			return numList.get(0);
		}
		String str0 = numList.get(0);
		String str1 = numList.get(1);
		if(!str1.contains(str0)) {
			return str0;
		}  else {      //如果str1中包含str0，则需要进一步判断str1中内容str0后的第一个字符
			if(str1.equalsIgnoreCase(str0))    //如果前两个元素相等，则返回其中一个
				return str0;  
			StringBuffer str1Buffer = new StringBuffer(str1);
			String str1_sub = str1Buffer.replace(0, str0.length(), "").toString();
			if(numList.size() == 2) {   //集合中只剩下两个元素的时候
				return str1_sub.charAt(0) > str0.charAt(0) ? str0:str1;
			}
			//集合中还有三个以上元素，则比较第二个数中不等于第一个数的第一个字符与第三个数的首字符的大小。
			//如果小，则输出str1，，否则str0+str2组成的数更小
			return str1_sub.charAt(0) > numList.get(2).charAt(0) ? str0:str1;
		}
	}
}
