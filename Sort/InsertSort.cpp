

/*直接插入排序 Straight Insert Sort
基本思想：插入排序依据遍历到第N个元素的时候前面的N-1个元素已经是排序好的，
那么就查找前面的N-1个元素把这第N个元素放在合适的位置，如此下去直到遍历完序列的元素为止。
*/
template <typename T>
void InsertSort(T array[], int size) 
{
	int i,j;
	T temp;
	for(i = 1; i < size; ++i) {
		temp = array[i];
		for(j = i-1; j >= 0 && temp < array[j]; --j) {
			array[j+1] = array[j];            //记录后移
		} 
		array[j+1] = temp;
	} 
} //InsertSort
