#include<stdio.h>
#include<stdlib.h>
#include<sort.h>

#define MAXSIZE 10  
typedef int ElemType;

int main()
{
    int i;
	ElemType a[MAXSIZE];
	
	printf("please input a  original array :\n");
	for(i=0;i<MAXSIZE;i++)
		scanf("%d",&a[i]);
	
	MergeSort(a, 0, MAXSIZE-1);

	printf("the sort array is:\n");
	for(i=0;i<MAXSIZE;i++)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}