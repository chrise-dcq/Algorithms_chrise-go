/**
 *整型数组的整合。例如已知数组a前半部分a[0,mid-1],后半部分a[mid,num-1]，
 *现前半部分和后半部分均已排好序。
 *要求：实现a数组的从小到大排序。空间复杂度为o(1) 
 *来源：百度笔试题
 */
public class Adjust_TwoOrderSub_IntArray {
	int[] intArray = {1,2,3,101,102,2,3,4,5,101,105};
	
	public void MergeIntData(int[] a, int num, int mid) {
		if(mid<0 || num<0 || null==a || a[mid-1]<a[mid]) {
			return;
		}
		int temp=0,low=0,high=0;
		if(mid <= num/2) {  
			while(low < mid) {  
				while(a[low]<a[mid+high]){  //每次只能交换前半部分和后半部分的一位。
					++low;      //找到前半部分大于后半部分时跳出循环
				}
				while(a[mid+high+1] < a[low]){
					++high;    // 找到前半部分大于mid的数应该在后半部分什么位置。
					if(high >= num-mid) {
						high = num-mid-1;
						break;
					}
				}
				temp = a[low];
				for(int i=low; i<mid+high; i++) {
					a[i] = a[i+1];  //a[low+1]到a[mid+high]之间的数往前移一位
								//空间复杂度限制为o(1)
				}
				a[mid+high] = temp;
			}
		} else {
			while(high < num-mid) {
				while(a[low] < a[mid+high])
					++low;
				temp = a[mid+high];
				for(int j=mid+high;j>low; --j) {
					a[j] = a[j-1];
				}
				a[low] = temp;
				++high;
			}
		}
	}
}
