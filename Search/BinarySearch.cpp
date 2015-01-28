/*
���ֲ���
˵��
�����Ѱ�������Ѿ�������Ӧ�þ���������������������ԣ��Լ�����Ѱ�ȶԵĴ����� 
������Ѱ�Ļ���ԭ�򣬶�����Ѱ�����������ԭ��Ĵ��� 

�ⷨ
�ڶ�����Ѱ���У������е��м俪ʼ��Ѱ����������С����������Ѱ������
���������������������ߵ���һ����С��Ҫ��Ѱ�Ķ������������˷�ʱ������ߵ�����
�����Ѱ������������Ѱ�Ķ������ұߵ�����������Ѱ��ֱ����Ѱ��ߵ����� 
�����ڶ�����Ѱ���У������в��ϵķ�Ϊ�������ݣ�ÿ�δӷָ�Ĳ�����ȡ�м����ȶԣ�

����Ҫ��Ѱ92�����µ����У������м�������Ϊ(0+9)/2=4��������0��ʼ���� 
[3 24 57 57 67 68 83 90 92 95] 
����67С��92������ת��Ѱ�ұߵ����У� 
3 24 57 57 67 [68 83 90 92 95] 
����90С��92������Ѱ�ұߵ����У���ξ��ҵ���Ҫ�����ˣ� 
3 24 57 57 67 68 83 90 [92 95] 
*/

#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

#define MAX 10 
#define SWAP(x,y) {int t; t=x; x=y; y=t;} 

//���ֲ���
int bisearch(int number[],int find){ 
    int low,mid,upper; 
	low=0; 
        upper=MAX-1; 
	while(low <= upper){ 
		mid = (low+upper)/2; 
		if(number[mid]<find) 
			low = mid+1; 
		else if(number[mid]>find) 
			upper = mid-1; 
		else 
            		return mid; 
	} 
	return -1; 
} 

//�������򡪡�����ҪƵ���Ľ�������
void quicksort(int number[],int left,int right) { 
	if (left < right) {	
		int key = number[left];  //��׼ֵ 
		int low = left; 
		int high = right;
		while(low < high) { 
			while(low < high && number[high] >= key) { // ��������
					high--;
			}
			number[low] = number[high];
			while(low < high && number[low] <= key) { // �������� 
					low++;
			}
			number[high] = number[low];
		} 
		number[low] = key;
		quicksort(number,left,low-1);  // ����߽��еݹ� 
		quicksort(number,low+1,right); // ���ұ߽��еݹ� 
	}
} 

int main(void){ 
    int number[MAX] = {0}; 
    int i,find; 

    srand(time(NULL)); //�����ڵ�ϵͳʱ����Ϊ������������������������ֻ�����ó�NULL���ܻ��ϵͳ��ʱ�䣡
    printf("������������У�"); 
    for(i=0;i<MAX;i++){ 
         number[i]=rand()%100;    //�������10����
         printf("%d ",number[i]); 
    } 
    printf("\n");

    quicksort(number,0,MAX-1); 

    printf("������"); 
    for(i=0;i<MAX;i++) 
		 printf("%d ",number[i]); 
    printf("\n");

    printf("�������ֵ��"); 
    scanf("%d",&find); 
    if((i = bisearch(number,find)) >= 0) 
	     printf("�ҵ�����������%d",i);
	else 
		 printf("\n�Ҳ���ָ����"); 
	printf("\n"); 
	return 0; 
} 

//��������
// void quicksort(int number[],int left,int right) { 
//        int i,j,s; 
//        if(left < right) { 
// 				s=number[(left+right)/2];   //��׼ֵ 
//				i=left-1; 
// 				j=right+1; 
//				while(1) { 
// 					while(number[++i]<s); // ������  
// 					while(number[--j]>s); // ������ 
// 					if(i >= j) 
// 						break;
// 					SWAP(number[i],number[j]); 
// 				} 
// 				quicksort(number,left,i-1);  // ����߽��еݻ� 
// 				quicksort(number,j+1,right); // ���ұ߽��еݻ� 
// 		} 
// } 