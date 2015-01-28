
/*
shell����
����˼�룺shell�����ǶԲ��������һ���Ľ�����ÿ�������ȸ���һ��������ȡһ�����������У�������������н���ֱ�Ӳ�������Ȼ�󲻶ϵ���С�������������е�Ԫ��������ֱ������Ϊ1��ʱ�������оͺ�ԭ�ȵĴ���������һ���ˣ���ʱֻ��Ҫ�������ıȽϺ��ƶ��Ϳ�����ɶ����е������ˡ�
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