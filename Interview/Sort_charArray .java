
//一组随机排列的字母数组，请编写一个时间复杂度为o(n)的算法，将这些字符从小到大排好。
//其中，字母区分大小写，小写字母在前，大写字母在后。
//思路：考虑到一般的排序算法时间复杂度都大于o(n).
        以空间换时间。
public class Sort_charArray {
	char[] a = {'R','B','B','b','W','W','B','R','b','w'}; //待排序的字母数组
	public static final int SIZE =52;
	int index[] = new int[SIZE];
	int temp = 0;
	
	//将待排序的字母数组逐一对应index[52] = {aAbBcCdDeEfFgG....xXyYzZ}进行标记
	public void setIndex(){
		int j = 0;
		
		for (int i=0; i<a.length; i++) {
			if(a[i]>'a' && a[i]<'z') {
				temp = 2*(a[i] - 'a');
			} else if (a[i]>'A' && a[i]<'Z'){
				temp = 2*(a[i] - 'A')+1;
			}
			index[temp]++;
		}
		getAlpByIndex(index);
	}
	
	public void getAlpByIndex(int[] index){
		for(int k=0; k<SIZE; k++) {
			while(index[k] > 0) {
				PrintAlp(k);
				index[k]--;
			}
		}
	}
	public void PrintAlp(int k) {
		if(k%2 == 0) {
			System.out.print(""+(char)(k/2 + 97));
		} else {
			System.out.print(""+(char)(k/2 + 65));
		}
	}
}
