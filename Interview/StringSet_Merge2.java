
/*
 * 给定一个字符串的集合，格式如： 
 * {aaa bbb ccc}，{bbb ddd}，{eee fff}，{ggg}，{ddd hhh} 
 * 要求将其中交集不为空的集合合并，要求合并完成后的集合之间无交集，例如上例应输出： 
 * {aaa bbb ccc ddd hhh}，{eee fff}， {ggg} 
 
 解法二：
 * 思路：
 * 	1. 首先得到所有元素的总集合（aaa, bbb, ccc, ddd, eee, fff, ggg, hhh），
 *  2. 为所有集合标记一个二进制数，来表示包含哪些集合，得到数组int bina[5]，复杂度O(N^2)；
                     例如，{aaa, bbb, ccc} = 1 1 1 0 0 0 0 0，
                {bbb, ddd}      = 0 1 0 1 0 0 0 0，
                {eee, fff}      = 0 0 0 0 1 1 0 0，
                {ggg}           = 0 0 0 0 0 0 1 0，
                {ddd, hhh}      = 0 0 0 1 0 0 0 1，

 *  3. 然后写一个函数，判断int数组中的第一个元素是否与其他元素&操作为空；
 *  4. 输出结果。
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;

public class StringSet_Merge2 {
	String string = "{aaa bbb ccc},{bbb ddd},{eee fff},{ggg},{ddd hhh}";
	List<String[]> mSubSetList = new ArrayList<String[]>(); //将集合都添加到List中，总共5个
	List<String> mSetList = null;     //所有元素的总集合："aaa bbb ccc ddd eee fff ggg hhh"
	
	//将给定的字符串分割，得到5个集合和一个总的无重复元素的集合
	public void init() {
		String[] strings = string.split(",");
		for(int i=0; i<strings.length; i++) {
			String stringtemp = strings[i].replace("{", "").replace("}", "");
			mSubSetList.add(stringtemp.split(" "));
		}
		
		String strs = string.replace("{", "").replace("}", "").replace(",", " ");
		String[] strset = strs.split(" ");
		List<String> tempSet = new ArrayList<String>();
		for(int j=0;j<strset.length; j++) {
			tempSet.add(strset[j]);
		}
		HashSet hashSet = new HashSet(tempSet);    //去重
		mSetList = new ArrayList<String>(hashSet) ;
		Collections.sort(mSetList);
//		for(int k=0; k<mSetList.size(); k++) {   无重复的所有元素集合
//			System.out.print(""+mSetList.get(k)+" ");
//		}
		markSet();
	}
	
	public void markSet(){
		int len = mSubSetList.size();   //5,表示五对大括号
		int[] bina = new int[len];
		
		for(int k=0;k<len; k++) { //表示五对大括号
			String [] subSet= mSubSetList.get(k);
			for(int j=0; j < subSet.length; j++) {  //表示一对大括号内的元素
				String detailStr = subSet[j];
				for(int i=0; i<mSetList.size(); i++) {  //表示去重后的集合
					if(detailStr.equals(mSetList.get(i))) {
						bina[k] += Math.pow(2,i);   //将每个集合类的元素在无重复元素的总集合中的对应位置上标志二进制的1
						break;
					}
				}
			}
		}
		unionSubSet(bina,0);
//		System.out.println("bina : " + bina[0]+" "+bina[1]+" "+bina[2]+" "+bina[3]+" "+bina[4]);
		System.out.println("去重合并结果为：");
		for(int p=0;p<len;p++){
			if(bina[p]>0){
				System.out.println(binarryToString(bina[p]));
			}
		}

	}
	
	//去掉重复元素并合并两个字符串集合
	public void unionSubSet(int[] b,int start){
		if(start > b.length-1) {
			return;
		}
		for(int i=start+1;i<b.length; i++) {
			if(b[start] == 0){
				break;
			}
			if(b[i]>0 && (b[start] & b[i])>0){
				b[start] = b[start] | b[i];
				b[i] = 0;//被合并之后将被合并的{}的b[i]=0，标记为删除
			}
		}
		unionSubSet(b,++start);
	}
	//将整数转换成二进制，根据二进制中的1，在总集合中找到对应元素输出
	public String binarryToString(int binarryData){
		String resultStr = "{";
		int index =0;
		while(binarryData>0){
			if(binarryData%2 == 1){
				resultStr += mSetList.get(index)+ " ";
			}
			binarryData = binarryData/2;
			index++;
		}
		resultStr= resultStr.trim();
		resultStr += "}";
		return resultStr;
	}
}