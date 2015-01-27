typedef int ElemType;

/*ֱ�Ӳ������� Straight Insert Sort
����˼�룺�����������ݱ�������N��Ԫ�ص�ʱ��ǰ���N-1��Ԫ���Ѿ�������õģ�
��ô�Ͳ���ǰ���N-1��Ԫ�ذ����N��Ԫ�ط��ں��ʵ�λ�ã������ȥֱ�����������е�Ԫ��Ϊֹ��
*/
void InsertSort(ElemType array[], int size) 
{
	int i,j;
	ElemType temp;
	for(i = 1; i < size; ++i) {
		temp = array[i];
		for(j = i-1; j >= 0 && temp < array[j]; --j) {
			array[j+1] = array[j];            //��¼����
		} 
		array[j+1] = temp;
	} 
} //InsertSort
