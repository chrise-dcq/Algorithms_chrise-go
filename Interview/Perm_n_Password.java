/**
 *从0-9之间取出三位不重复数组成密码，打印出所有可能形式
 *思路：
 *（1）从十个数中取出一个数组成第一位，剩下的两位从剩余的九个数中选取
 *总共三位，只需递归三次，每一次递归过程的结果是设置一位 .
    这道题的本质就是一个全排列，取每次排列后的前三位
 */
public class Perm_n_Password {
	char[] words = {'0','1','2','3','4','5','6'};
	public static final int PASSWORD_LENGTH = 2; 
	
//	char[] words = {'0','1','2','3','4','5','6','7','8','9'};
	
	public Password3(){
		chooseOneWord(words,0);
	}

	public void chooseOneWord(char[] a, int begin){
		if(begin == PASSWORD_LENGTH) {         //递归的终止条件，密码只有三位
			for(int k=0; k < PASSWORD_LENGTH; k++) 
				System.out.print(""+a[k]);
			System.out.println("");
			return;
		} 
		
		for(int i = begin; i <= a.length-1; ++i) {
			swap(a, begin, i);
			chooseOneWord(a,begin+1);
			swap(a, begin, i);
		}
	}
	
	public void swap(char[] a, int i, int j){
		if(i == j )
			return;
		
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];        //将已选取的数交换到第0个位置
	}
}
