
/*
shell排序
基本思想：shell排序是对插入排序的一个改进，它每次排序先根据一个增量获取一个若干子序列，对这这个子序列进行直接插入排序，然后不断的缩小增量扩大子序列的元素数量，直到增量为1的时候子序列就和原先的待排列序列一样了，此时只需要做少量的比较和移动就可以完成对序列的排序了。
*/
template <typename T>
void ShellSort(T array[], int length)  
{  
    int i,j,increment;  
	ElemType temp;

    for(increment = length/2; increment > 0; increment /= 2)  
    {  
        for(i = increment; i < length; i++)  
        {  
            temp = array[i];  
            for(j = i - increment; j >= 0 && array[j] > temp; j -= increment)  
            {  
                array[j + increment] = array[j];  
            }  
            array[j + increment] = temp;  
        }  
    }  
} 