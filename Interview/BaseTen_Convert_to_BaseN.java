package BaiduMechine;
/*
十进制转N进制
这里欠考虑了，如果N为23或者36怎么办呢，先记下来以后来修改
*/
public class BaseTen_Convert_to_BaseN {
	
	public char[] fromTenToN (int num, int N) {
		if(0 == num || N < 2 || N > 16)
			return null;
		
		char[] result = new char[32];
		int tempNum = num;
		int ncount = 0;
		
		while(tempNum > 0) {
			int temp = tempNum % N;
			if(temp >= 10)
				temp = 'A' + (temp-10) - '0';
			
			result[ncount++] = (char) (temp + '0');
			tempNum = tempNum/N;
		}
		result[ncount] = '\0';
		ReverseString(result);
		
		return result;
	}
	
	public void ReverseString(char[] array) {
		if(null == array || array.length == 1) 
			return;
		
		int i = 0;
		int j = array.length - 1;
		
		while(i < j) {
			array[i] ^= array[j];
			array[j] ^= array[i];
			array[i] ^= array[j];
			++i;
			--j;
		}
	}
}
