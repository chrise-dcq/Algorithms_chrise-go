
/*折半插入排序
相较与直接插入排序，折半插入排序仅减少了关键字间的比较次数，而记录的移动次数不变.时间复杂度是:o(n^2);
*/
typedef int ElemType;

void BInsertSort (ElemType array[],int size){
     int i,j; 
     int high,low,mid;
	 ElemType temp;

	 for (i = 1; i <= size; ++i) {
	     temp = array[i];
		 low = 0;
		 high = i-1;   //查找范围由0到i-1
		 while(low <= high) {
			 mid = low + (high - low)/2;       //折半
			 if (temp < array[mid]) 
				 high = mid - 1;
			 else 
				 low = mid + 1;
		 } //while
		 for (j = i-1; j >= high+1; --j) {
			array[j+1] = array[j];            //记录后移
		 }
		//折半查找结束后high+1位置即为插入位置
		array[high+1] = temp;
	}
}//BInsertSort