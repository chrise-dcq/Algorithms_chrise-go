/*ð������
����˼�룺ð�������Ǿ���n-1����������ɵģ���i��������ӵ�1��������n-i������
����i�����Ⱥ�һ������������С�����򽻻�������
Ч�ʷ���������ʼ����Ϊ������ֻ�����һ�����򣬽���n-1�αȽ��Ҳ��ƶ���¼��
��֮��ʼΪ����ʱ���������n-1�����򣬹�n*(n-1)/2�αȽϺ��ƶ���
һ�ָĽ��취������ĳһ��ð����������з���û�н��н����������Ϳ��Խ�������
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
                flag = 1;       //��־λ
                array[j] = array[j] + array[j+1];  
                array[j+1] = array[j] - array[j+1];  
                array[j] = array[j] - array[j+1];  
            }  
        }  
        if(flag == 0) 
			break;  
    }  
}  