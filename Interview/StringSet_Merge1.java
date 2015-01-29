package StringHandle;
/* 给定一个字符串的集合，格式如： 
*  {aaa bbb ccc}，{bbb ddd}，{eee fff}，{ggg}，{ddd hhh} 
*  要求将其中交集不为空的集合合并，要求合并完成后的集合之间无交集，例如上例应输出： 
*  {aaa bbb ccc ddd hhh}，{eee fff}， {ggg} 

 解法一：
*/
import java.util.ArrayList;
import java.util.List;

public class StringSet_Merge1 {
	List<String> str1 = new ArrayList<String>();
	List<String> str2 = new ArrayList<String>();
	List<String> str3 = new ArrayList<String>();
	List<List<String>> listAll = new ArrayList<List<String>>();
	
	public void init() {
		str1.add("aaa");
		str1.add("bb");
		str1.add("ccc");
		str1.add("dd");
		str2.add("fff");
		str3.add("gg");
		listAll.add(str1);
		listAll.add(str2);
		listAll.add(str3);
	}
	
	public void mergeInterString(){
		boolean flag_sub = false;
		init();
		for(int i=0; i<listAll.size(); i++) {
			for(int j=i+1; j<listAll.size(); j++) {
				flag_sub = false;
				if(AcontantB(listAll.get(i),listAll.get(j))) {  //A中包含B
					for(int m=0; m<listAll.get(j).size(); m++) { 
					//将B的逐个元素取出，如果A中没有就添加到A中去
						if(!(listAll.get(i).contains(listAll.get(j).get(m)))){
							listAll.get(i).add(listAll.get(j).get(m));
						}
					}
					listAll.remove(j);
					j--;
					flag_sub = true;
				}
			}
			if(flag_sub) {
				i--;
			}
		}
		for(int n=0; n<listAll.size(); n++) {
			System.out.print("{");
			System.out.print(listAll.get(n).toString()+"," );
			System.out.print("},");
		}
	}
	
	public boolean AcontantB(List<String> str1, List<String> str2){
		List<String> temp = new ArrayList<String>();
		temp.addAll(str1);
		for(int i=0; i<str2.size(); i++) {
			if(!(temp.contains(str2.get(i)))){
				temp.add(str2.get(i));
			}
		}
		if(temp.size() < str1.size() + str2.size()) {  //说明有重复元素
			return true;
		} else {
			return false;   //没有重复元素
		}
	} 
}
