/*
�������򣺾�ƽ��ʱ����ԣ�����������Ŀǰ����Ϊ��õ�һ���ڲ����򷽷���
ʱ�临�Ӷȣ�o(nlogn)
������򵥵Ŀ��������ʵ�֣�ȡ��һ��Ԫ��Ϊ��׼��
����֮���ǵ�ԭ��������ʱ�����ɻ�Ϊð������ʱ�临�Ӷ�Ϊo(n)��
�Ľ��İ취�У�������ȡ�С�����ѡȡ�����¼
*/

template <typename T>
void QuickSort(T number[], int low, int high)
{
	int pivotloc;
	if(low < high) {
		pivotloc = Partition(number, low, high);  //������һ��Ϊ��
		QuickSort(number, low, pivotloc-1);       //�ݹ���ʽ�Ŀ�������
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

