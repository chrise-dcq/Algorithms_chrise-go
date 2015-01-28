#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include "string.h"
 
typedef int ElemType ;
 
/************************************************************************/
/*             以下是关于线性表链接存储（单链表）操作的18种算法        */
 
/* 1.初始化线性表，即置单链表的表头指针为空 */
/* 2.创建线性表，此函数输入负数终止读取数据*/
/* 3.打印链表，链表的遍历*/
/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */
/* 5.返回单链表的长度 */
/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */
/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
/* 10.向单链表的表头插入一个元素 */
/* 11.向单链表的末尾添加一个元素 */
/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
/* 18.交换2个元素的位置 */
/* 19.将线性表进行快速排序 */
 
 
/************************************************************************/
typedef struct LNode{    /* 定义单链表结点类型 */
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
 /*
LNode是结构体struct LNode的一个别名，可以用LNode去定义变量，
在这里已经和int/char这样的关键字一样了。
LinkList是结构体struct LNode类型的指针的别名，也可以去定义变量，
定义出来的是指向这个结构的指针变量.
LNode *p;这条语句等同于LinkList p; 
LinkList head    把LinkList理解为代表这整个链表
LNode   *pnew    把LNode理解为一个结点
*/
 
/* 1.初始化线性表，即置单链表的表头指针为空 */
void initList(LNode **pLNode)
{
    *pLNode = NULL;
    printf("initList函数执行，初始化成功\n");
}
 
/* 2.创建线性表，此函数输入负数终止读取数据*/
LNode *creatList(LNode *pHead)
{
    LNode *pnew;
    LNode *tail;    // 尾结点
 
	tail = pHead;
    pnew = (LNode *)malloc(sizeof(LNode)); //申请新节点
    if(pnew == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    memset(pnew,0,sizeof(LNode));   //为刚分配的内存抹0
 
    scanf("%d",&pnew->data);    //输入新节点
    pnew->next = NULL;         //新节点的指针置为空
    while(pnew->data > 0)        //输入的值大于0则继续，直到输入的值为负
    {
        if(pHead == NULL)       //空表，接入表头
        {
            pHead = p1;
        }
        else               
        {
            tail->next = pnew;       //非空表，接入表尾
        }
        tail = pnew;
        pnew = (LNode *)malloc(sizeof(LNode));    //再重申请一个节点
        if(pnew == NULL)
        {
			printf("内存分配失败\n");
			exit(0);
        }
        memset(pnew,0,sizeof(LNode));
        scanf("%d",&pnew->data);
        pnew->next = NULL;
    }
    printf("creatList函数执行，链表创建成功\n");
    return pHead;           //返回链表的头指针
}
 
/* 3.打印链表，链表的遍历*/
void printList(LNode *pHead)
{
    if(NULL == pHead)   //链表为空
    {
        printf("PrintList函数执行，链表为空\n");
    }
    else
    {
        while(NULL != pHead)
        {
            printf("%d ",pHead->data);
            pHead = pHead->next;   // 后移
        }
        printf("\n");
    }
}
 
/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */
void clearList(LNode *pHead)
{
    LNode *pNext;            //定义一个与pHead相邻节点
 
    if(pHead == NULL)
    {
        printf("clearList函数执行，链表为空\n");
        return;
    }
    while(pHead->next != NULL)
    {
        pNext = pHead->next;//保存下一结点的指针
        free(pHead);
        pHead = pNext;      //表头下移
    }
    printf("clearList函数执行，链表已经清除\n");
}
 
/* 5.返回单链表的长度 */
int sizeList(LNode *pHead)
{
    int size = 0;
 
    while(pHead != NULL)
    {
        size++;         //遍历链表size大小比链表的实际长度小1
        pHead = pHead->next;
    }
    printf("sizeList函数执行，链表长度 %d \n",size);
    return size;    //链表的实际长度
}
 
/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */
int isEmptyList(LNode *pHead)
{
    if(pHead == NULL)
    {
        printf("isEmptyList函数执行，链表为空\n");
        return 1;
    }
    printf("isEmptyList函数执行，链表非空\n");
 
    return 0;
}
 
/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
ElemType getdata(LNode *pHead, int pos)
{
    int i=0;
 
    if(pos < 1)         //注意边界条件
    {
        printf("getdata函数执行，pos值非法\n");
        return 0;
    }
    if(pHead == NULL)
    {
        printf("getdata函数执行，链表为空\n");
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
        pHead = pHead->next; //移到下一结点
    }
    if(i < pos)                  //链表长度不足则退出
    {
        printf("getdata函数执行，pos值超出链表长度\n");
        return 0;
    }
 
    return pHead->data;
}
 
/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
ElemType *getElemAddr(LNode *pHead, ElemType x)
{
    if(NULL == pHead)
    {
        printf("getElemAddr函数执行，链表为空\n");
        return NULL;
    }
    if(x < 0)
    {
        printf("getElemAddr函数执行，给定值X不合法\n");
        return NULL;
    }
    while((pHead->data != x) && (NULL != pHead->next)) //判断是否到链表末尾，以及是否存在所要找的元素
    {
        pHead = pHead->next;
    }
    if((pHead->data != x) && (pHead != NULL))
    {
        printf("getElemAddr函数执行，在链表中未找到x值\n");
        return NULL;
    }
    if(pHead->data == x)
    {
        printf("getElemAddr函数执行，元素 %d 的地址为 0x%x\n",x,&(pHead->data));
    }
 
    return &(pHead->data);//返回元素的地址
}
 
/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
int modifyElem(LNode *pLNode,int pos,ElemType x)
{
    LNode *pHead;
    pHead = pLNode;
    int i = 0;
 
    if(NULL == pHead)
    {
        printf("modifyElem函数执行，链表为空\n");
    }
    if(pos < 1)
    {
        printf("modifyElem函数执行，pos值非法\n");
        return 0;
    }
    while(pHead !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pHead = pHead->next; //移到下一结点
    }
    if(i < pos)                  //链表长度不足则退出
    {
        printf("modifyElem函数执行，pos值超出链表长度\n");
        return 0;
    }
    pLNode = pHead;
    pLNode->data = x;
    printf("modifyElem函数执行\n");
     
    return 1;
}
 
/* 10.向单链表的表头插入一个元素 */
int insertHeadList(LNode **pLNode,ElemType insertElem)
{
    LNode *pInsert;
    pInsert = (LNode *)malloc(sizeof(LNode));
    memset(pInsert,0,sizeof(LNode));
    pInsert->data = insertElem;
	
    pInsert->next = *pLNode;
    *pLNode = pInsert;
    printf("insertHeadList函数执行，向表头插入元素成功\n");
 
    return 1;
}
 
/* 11.向单链表的末尾添加一个元素 */
int insertLastList(LNode **pLNode,ElemType insertElem)
{
    LNode *pInsert;
    LNode *pHead;
    LNode *pTmp; //定义一个临时链表用来存放第一个节点
 
    pHead = *pLNode;
    pTmp = pHead;
    pInsert = (LNode *)malloc(sizeof(LNode)); //申请一个新节点
    memset(pInsert,0,sizeof(LNode));
    pInsert->data = insertElem;
 
    while(pHead->next != NULL)
    {
        pHead = pHead->next;
    }
    pHead->next = pInsert;   //将链表末尾节点的下一结点指向新添加的节点
    *pLNode = pTmp;
    printf("insertLastList函数执行，向表尾插入元素成功\n");
 
    return 1;
}
 
/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
/* 18.交换2个元素的位置 */
/* 19.将线性表进行快速排序 */
 
/******************************************************************/
int main()
{
    LNode *pList=NULL;
    int length = 0;
 
    ElemType posElem;
 
    initList(&pList);       //链表初始化
    printList(pList);       //遍历链表，打印链表
 
    pList=creatList(pList); //创建链表
    printList(pList);
     
    sizeList(pList);        //链表的长度
    printList(pList);
 
    isEmptyList(pList);     //判断链表是否为空链表
     
    posElem = getdata(pList,3);  //获取第三个元素，如果元素不足3个，则返回0
    printf("getdata函数执行，位置 3 中的元素为 %d\n",posElem);   
    printList(pList);
 
    getElemAddr(pList,5);   //获得元素5的地址
 
    modifyElem(pList,4,1);  //将链表中位置4上的元素修改为1
    printList(pList);
 
    insertHeadList(&pList,5);   //表头插入元素12
    printList(pList);
 
    insertLastList(&pList,10);  //表尾插入元素10
    printList(pList);
 
    clearList(pList);       //清空链表
    system("pause");
     
}