/*冒泡排序
基本思想：冒泡排序是经过n-1趟子排序完成的，第i趟子排序从第1个数至第n-i个数，
若第i个数比后一个数大（则升序，小则降序）则交换两数。
效率分析：若初始序列为正序，则只需进行一趟排序，进行n-1次比较且不移动记录；
反之初始为逆序时，则需进行n-1趟排序，共n*(n-1)/2次比较和移动。
一种改进办法：当在某一趟冒泡排序过程中发现没有进行交换操作，就可以结束排序。
*/

template <typename T>
void BubbleSort(T array[], int size)  
{  
	int i,j;
    int flag = 0;  
    for(i = 0; i < size-1; i++)  
    {  
        for(j = 0; j < size-1-i; j++)  
        {  
            if(array[j] > array[j+1])  
            {  
                flag = 1;       //标志位
                array[j] = array[j] + array[j+1];  
                array[j+1] = array[j] - array[j+1];  
                array[j] = array[j] - array[j+1];  
            }  
        }  
        if(flag == 0) 
			break;  
    }  
}  