#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include "string.h"
 
typedef int ElemType ;
 
/************************************************************************/
/*             �����ǹ������Ա����Ӵ洢��������������18���㷨        */
 
/* 1.��ʼ�����Ա����õ�����ı�ͷָ��Ϊ�� */
/* 2.�������Ա��˺������븺����ֹ��ȡ����*/
/* 3.��ӡ��������ı���*/
/* 4.������Ա�L�е�����Ԫ�أ����ͷŵ�����L�����еĽ�㣬ʹ֮��Ϊһ���ձ� */
/* 5.���ص�����ĳ��� */
/* 6.��鵥�����Ƿ�Ϊ�գ���Ϊ���򷵻أ������򷵻أ� */
/* 7.���ص������е�pos������е�Ԫ�أ���pos������Χ����ֹͣ�������� */
/* 8.�ӵ������в��Ҿ��и���ֵx�ĵ�һ��Ԫ�أ������ҳɹ��򷵻ظý��data��Ĵ洢��ַ�����򷵻�NULL */
/* 9.�ѵ������е�pos������ֵ�޸�Ϊx��ֵ�����޸ĳɹ����أ������򷵻أ� */
/* 10.������ı�ͷ����һ��Ԫ�� */
/* 11.�������ĩβ���һ��Ԫ�� */
/* 12.�������е�pos�����λ�ò���Ԫ��Ϊx�Ľ�㣬������ɹ����أ������򷵻أ� */
/* 13.�����������в���Ԫ��x��㣬ʹ�ò������Ȼ���� */
/* 14.�ӵ�������ɾ����ͷ��㣬���Ѹý���ֵ���أ���ɾ��ʧ����ֹͣ�������� */
/* 15.�ӵ�������ɾ����β��㲢��������ֵ����ɾ��ʧ����ֹͣ�������� */
/* 16.�ӵ�������ɾ����pos����㲢��������ֵ����ɾ��ʧ����ֹͣ�������� */
/* 17.�ӵ�������ɾ��ֵΪx�ĵ�һ����㣬��ɾ���ɹ��򷵻�1,���򷵻�0 */
/* 18.����2��Ԫ�ص�λ�� */
/* 19.�����Ա���п������� */
 
 
/************************************************************************/
typedef struct LNode{    /* ���嵥���������� */
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
 /*
LNode�ǽṹ��struct LNode��һ��������������LNodeȥ���������
�������Ѿ���int/char�����Ĺؼ���һ���ˡ�
LinkList�ǽṹ��struct LNode���͵�ָ��ı�����Ҳ����ȥ���������
�����������ָ������ṹ��ָ�����.
LNode *p;��������ͬ��LinkList p; 
LinkList head    ��LinkList���Ϊ��������������
LNode   *pnew    ��LNode���Ϊһ�����
*/
 
/* 1.��ʼ�����Ա����õ�����ı�ͷָ��Ϊ�� */
void initList(LNode **pLNode)
{
    *pLNode = NULL;
    printf("initList����ִ�У���ʼ���ɹ�\n");
}
 
/* 2.�������Ա��˺������븺����ֹ��ȡ����*/
LNode *creatList(LNode *pHead)
{
    LNode *pnew;
    LNode *tail;    // β���
 
	tail = pHead;
    pnew = (LNode *)malloc(sizeof(LNode)); //�����½ڵ�
    if(pnew == NULL)
    {
        printf("�ڴ����ʧ��\n");
        exit(0);
    }
    memset(pnew,0,sizeof(LNode));   //Ϊ�շ�����ڴ�Ĩ0
 
    scanf("%d",&pnew->data);    //�����½ڵ�
    pnew->next = NULL;         //�½ڵ��ָ����Ϊ��
    while(pnew->data > 0)        //�����ֵ����0�������ֱ�������ֵΪ��
    {
        if(pHead == NULL)       //�ձ������ͷ
        {
            pHead = p1;
        }
        else               
        {
            tail->next = pnew;       //�ǿձ������β
        }
        tail = pnew;
        pnew = (LNode *)malloc(sizeof(LNode));    //��������һ���ڵ�
        if(pnew == NULL)
        {
			printf("�ڴ����ʧ��\n");
			exit(0);
        }
        memset(pnew,0,sizeof(LNode));
        scanf("%d",&pnew->data);
        pnew->next = NULL;
    }
    printf("creatList����ִ�У��������ɹ�\n");
    return pHead;           //���������ͷָ��
}
 
/* 3.��ӡ��������ı���*/
void printList(LNode *pHead)
{
    if(NULL == pHead)   //����Ϊ��
    {
        printf("PrintList����ִ�У�����Ϊ��\n");
    }
    else
    {
        while(NULL != pHead)
        {
            printf("%d ",pHead->data);
            pHead = pHead->next;   // ����
        }
        printf("\n");
    }
}
 
/* 4.������Ա�L�е�����Ԫ�أ����ͷŵ�����L�����еĽ�㣬ʹ֮��Ϊһ���ձ� */
void clearList(LNode *pHead)
{
    LNode *pNext;            //����һ����pHead���ڽڵ�
 
    if(pHead == NULL)
    {
        printf("clearList����ִ�У�����Ϊ��\n");
        return;
    }
    while(pHead->next != NULL)
    {
        pNext = pHead->next;//������һ����ָ��
        free(pHead);
        pHead = pNext;      //��ͷ����
    }
    printf("clearList����ִ�У������Ѿ����\n");
}
 
/* 5.���ص�����ĳ��� */
int sizeList(LNode *pHead)
{
    int size = 0;
 
    while(pHead != NULL)
    {
        size++;         //��������size��С�������ʵ�ʳ���С1
        pHead = pHead->next;
    }
    printf("sizeList����ִ�У������� %d \n",size);
    return size;    //�����ʵ�ʳ���
}
 
/* 6.��鵥�����Ƿ�Ϊ�գ���Ϊ���򷵻أ������򷵻أ� */
int isEmptyList(LNode *pHead)
{
    if(pHead == NULL)
    {
        printf("isEmptyList����ִ�У�����Ϊ��\n");
        return 1;
    }
    printf("isEmptyList����ִ�У�����ǿ�\n");
 
    return 0;
}
 
/* 7.���ص������е�pos������е�Ԫ�أ���pos������Χ����ֹͣ�������� */
ElemType getdata(LNode *pHead, int pos)
{
    int i=0;
 
    if(pos < 1)         //ע��߽�����
    {
        printf("getdata����ִ�У�posֵ�Ƿ�\n");
        return 0;
    }
    if(pHead == NULL)
    {
        printf("getdata����ִ�У�����Ϊ��\n");
        return 0;
        //exit(1);
    }
    while(pHead !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pHead = pHead->next; //�Ƶ���һ���
    }
    if(i < pos)                  //�����Ȳ������˳�
    {
        printf("getdata����ִ�У�posֵ����������\n");
        return 0;
    }
 
    return pHead->data;
}
 
/* 8.�ӵ������в��Ҿ��и���ֵx�ĵ�һ��Ԫ�أ������ҳɹ��򷵻ظý��data��Ĵ洢��ַ�����򷵻�NULL */
ElemType *getElemAddr(LNode *pHead, ElemType x)
{
    if(NULL == pHead)
    {
        printf("getElemAddr����ִ�У�����Ϊ��\n");
        return NULL;
    }
    if(x < 0)
    {
        printf("getElemAddr����ִ�У�����ֵX���Ϸ�\n");
        return NULL;
    }
    while((pHead->data != x) && (NULL != pHead->next)) //�ж��Ƿ�����ĩβ���Լ��Ƿ������Ҫ�ҵ�Ԫ��
    {
        pHead = pHead->next;
    }
    if((pHead->data != x) && (pHead != NULL))
    {
        printf("getElemAddr����ִ�У���������δ�ҵ�xֵ\n");
        return NULL;
    }
    if(pHead->data == x)
    {
        printf("getElemAddr����ִ�У�Ԫ�� %d �ĵ�ַΪ 0x%x\n",x,&(pHead->data));
    }
 
    return &(pHead->data);//����Ԫ�صĵ�ַ
}
 
/* 9.�ѵ������е�pos������ֵ�޸�Ϊx��ֵ�����޸ĳɹ����أ������򷵻أ� */
int modifyElem(LNode *pLNode,int pos,ElemType x)
{
    LNode *pHead;
    pHead = pLNode;
    int i = 0;
 
    if(NULL == pHead)
    {
        printf("modifyElem����ִ�У�����Ϊ��\n");
    }
    if(pos < 1)
    {
        printf("modifyElem����ִ�У�posֵ�Ƿ�\n");
        return 0;
    }
    while(pHead !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pHead = pHead->next; //�Ƶ���һ���
    }
    if(i < pos)                  //�����Ȳ������˳�
    {
        printf("modifyElem����ִ�У�posֵ����������\n");
        return 0;
    }
    pLNode = pHead;
    pLNode->data = x;
    printf("modifyElem����ִ��\n");
     
    return 1;
}
 
/* 10.������ı�ͷ����һ��Ԫ�� */
int insertHeadList(LNode **pLNode,ElemType insertElem)
{
    LNode *pInsert;
    pInsert = (LNode *)malloc(sizeof(LNode));
    memset(pInsert,0,sizeof(LNode));
    pInsert->data = insertElem;
	
    pInsert->next = *pLNode;
    *pLNode = pInsert;
    printf("insertHeadList����ִ�У����ͷ����Ԫ�سɹ�\n");
 
    return 1;
}
 
/* 11.�������ĩβ���һ��Ԫ�� */
int insertLastList(LNode **pLNode,ElemType insertElem)
{
    LNode *pInsert;
    LNode *pHead;
    LNode *pTmp; //����һ����ʱ����������ŵ�һ���ڵ�
 
    pHead = *pLNode;
    pTmp = pHead;
    pInsert = (LNode *)malloc(sizeof(LNode)); //����һ���½ڵ�
    memset(pInsert,0,sizeof(LNode));
    pInsert->data = insertElem;
 
    while(pHead->next != NULL)
    {
        pHead = pHead->next;
    }
    pHead->next = pInsert;   //������ĩβ�ڵ����һ���ָ������ӵĽڵ�
    *pLNode = pTmp;
    printf("insertLastList����ִ�У����β����Ԫ�سɹ�\n");
 
    return 1;
}
 
/* 12.�������е�pos�����λ�ò���Ԫ��Ϊx�Ľ�㣬������ɹ����أ������򷵻أ� */
/* 13.�����������в���Ԫ��x��㣬ʹ�ò������Ȼ���� */
/* 14.�ӵ�������ɾ����ͷ��㣬���Ѹý���ֵ���أ���ɾ��ʧ����ֹͣ�������� */
/* 15.�ӵ�������ɾ����β��㲢��������ֵ����ɾ��ʧ����ֹͣ�������� */
/* 16.�ӵ�������ɾ����pos����㲢��������ֵ����ɾ��ʧ����ֹͣ�������� */
/* 17.�ӵ�������ɾ��ֵΪx�ĵ�һ����㣬��ɾ���ɹ��򷵻�1,���򷵻�0 */
/* 18.����2��Ԫ�ص�λ�� */
/* 19.�����Ա���п������� */
 
/******************************************************************/
int main()
{
    LNode *pList=NULL;
    int length = 0;
 
    ElemType posElem;
 
    initList(&pList);       //�����ʼ��
    printList(pList);       //����������ӡ����
 
    pList=creatList(pList); //��������
    printList(pList);
     
    sizeList(pList);        //����ĳ���
    printList(pList);
 
    isEmptyList(pList);     //�ж������Ƿ�Ϊ������
     
    posElem = getdata(pList,3);  //��ȡ������Ԫ�أ����Ԫ�ز���3�����򷵻�0
    printf("getdata����ִ�У�λ�� 3 �е�Ԫ��Ϊ %d\n",posElem);   
    printList(pList);
 
    getElemAddr(pList,5);   //���Ԫ��5�ĵ�ַ
 
    modifyElem(pList,4,1);  //��������λ��4�ϵ�Ԫ���޸�Ϊ1
    printList(pList);
 
    insertHeadList(&pList,5);   //��ͷ����Ԫ��12
    printList(pList);
 
    insertLastList(&pList,10);  //��β����Ԫ��10
    printList(pList);
 
    clearList(pList);       //�������
    system("pause");
     
}