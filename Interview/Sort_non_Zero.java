
/*
排序数字字符串的数字（升序），遇到0时从数字字符串中删除，
如“1324”排序后应该为“1234”，“9002”排序后应该为“29”；(Souhu2010)
*/
public class Sort_non_Zero {

	public void sortString(){
		String numStr = new String("0090501300204");
		//第一步：去掉字符串中的0
//		numStr = numStr.replace("0", ""); // 删除字符串中的0,方法一：一次全部替换
		while(numStr.contains("0")) {	 // 删除字符串中的0,方法二：循环一个个删0
			int i = numStr.indexOf("0");
			numStr = numStr.substring(0, i)+numStr.substring(i+1, numStr.length());
		}	
		
		char[] nums = numStr.toCharArray();    //字符串转字符数组
		//排序
		QuickSort(nums, 0, nums.length-1);
		
		numStr = numStr.valueOf(nums);       //字符数组转字符串。
		System.out.println("result:"+numStr);   
	}
	
	public void QuickSort(char[] s, int low, int high) {
		int key = 0;
		if(low < high) {
		key = Partition(s,low,high);
		QuickSort(s, low,key-1);
		QuickSort(s, key+1,high);
		}
	}
	
	public int Partition(char[] s,int low, int high) {
		char temp = s[low];
		
		while(low < high) {
			while (low < high && s[high] - temp >= 0) {
				--high;
			}
			s[low] = s[high];
			
			while (low < high && s[low]-temp <= 0) {
				++low;
			}
			s[high] = s[low];
		}
		
		s[low] = temp;
		return low;
	}
	
	
}
