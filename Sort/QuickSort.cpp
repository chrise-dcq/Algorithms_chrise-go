/*
快速排序：就平均时间而言，快速排序是目前被认为最好的一种内部排序方法。
时间复杂度：o(nlogn)
这是最简单的快速排序的实现，取第一个元素为基准，
不足之处是当原序列有序时，将蜕化为冒泡排序，时间复杂度为o(n)。
改进的办法有：“三者取中”法来选取枢轴记录
*/

template <typename T>
void QuickSort(T number[], int low, int high)
{
	int pivotloc;
	if(low < high) {
		pivotloc = Partition(number, low, high);  //将数组一分为二
		QuickSort(number, low, pivotloc-1);       //递归形式的快速排序
		QuickSort(number, pivotloc+1, high);
	}
}

int Partition(T number[],int low,int high){ 
        int pivotkey; 
		pivotkey = number[low];
		while (low < high) {
			while (low < high && number[high] >= pivotkey)
				--high;
			number[low] = number[high];
			while(low < high && number[low] <= pivotkey)
				++low;
			number[high] = number[low];
		}
		number[low] = pivotkey;
		return low;
} 

