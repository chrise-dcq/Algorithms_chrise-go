
/*�۰��������
�����ֱ�Ӳ��������۰��������������˹ؼ��ּ�ıȽϴ���������¼���ƶ���������.ʱ�临�Ӷ���:o(n^2);
*/

template <typename T>
void BInsertSort (T array[],int size){
     int i,j; 
     int high,low,mid;
	 T temp;

	 for (i = 1; i <= size; ++i) {
	     temp = array[i];
		 low = 0;
		 high = i-1;   //���ҷ�Χ��0��i-1
		 while(low <= high) {
			 mid = low + (high - low)/2;       //�۰�
			 if (temp < array[mid]) 
				 high = mid - 1;
			 else 
				 low = mid + 1;
		 } //while
		 for (j = i-1; j >= high+1; --j) {
			array[j+1] = array[j];            //��¼����
		 }
		//�۰���ҽ�����high+1λ�ü�Ϊ����λ��
		array[high+1] = temp;
	}
}//BInsertSort