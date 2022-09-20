#include "array.h"
/*
ADT 线性表(List)
Data 数据类型 ElementType
    每一个元素只有一个前驱和一个后继，对于除了第一个和最后一个元素以外，其余元素均有唯一的前驱和后继，数据元素之间是一对一的关系，
    即一个索引只对应一个值。(区别于树等高级结构)

    方法：
    SqList* InitList(Maxsize(如果Maxsize是全局变量就可以不用传)):这里没用书上的形式，选择使用返回一个指针的形式来新建一个线性表
    Status DestroyList(&L)：这里销毁一个线性表，用free函数进行销毁
    ListExist(&L):这里输入一个线性表，判断其是否为空表
    ListEmpty(&L):输入一个线性表，将其清空
    DeleteList(&L):从线性表中删除某个元素
    GetListLen(L):输出线性表的长度
    ListSort(&L，int reverse=-1,1):对于线性表排序 (reverse=1为逆序，reverse=-1为顺序)
    GetMax(&L):输出线性表中数据的最大值
    GetMin(&L):输出线性表里的最小值
*/

//下面来写第一个函数，有关于获取元素的操作
//参数中传入一个线性表L,以及需要获取的元素位置下标i,以及将获得的数据通过e来进行保存
Status Getelement(SqList L, int i, ElementType *e)
{
    if (L.length > 0 && 0 < i <= L.length) //如果输入的i的位置是合法范围，就使用e来进行保存，并返回ok，其余情况返回error
    {
        *e = L.data[i - 1];
        return OK;
    }
    else
        return Error;
}

//下面来写第二个函数，插入数据进入线性表中，传入参数为插入的表，以及所需插入的位置i，以及所需插入的元素值e
Status Insertelement(SqList *L, int i, ElementType e)
{
    if (L->length > 0 && 0 < i <= L->length) //如果输入的i的位置是合法范围，
    {
        if (L->length + 1 <= Maxsize) //可以向后移动一位
        {
            int j = 0;
            for (j = L->length - 1; j >= i - 1; j--)
            {
                L->data[j + 1] = L->data[j];
            }
            L->data[i - 1] = e;
            L->length ++;
            return OK;
        }

        else
        {
            return Error;
        }
    }
    else
        return Error;
}

//补一下初始化函数和销毁函数
//先来写初始化函数，返回一个指针

// void InitList(SqList *L)
// {
//     strcpy(L->data,(ElementType *)malloc(sizeof(ElementType) * Maxsize));
//     L->length = 0;
//     printf("InitList!");
//     free(L->data);
//     free(L);
// }
void InitList(SqList *LP)
{
    LP->length = 0;
}

Status CreateList(SqList *LP, ElementType a[], int n)
{
    int i;
    if (n < Maxsize)
    {
        for (i = 0; i < n; i++)
        { //通过循环将数组元素全部遍历放入顺序表中
            LP->data[i] = a[i];
            LP->length++;
        }
        return OK;
    }
    else
    {
        return Error;
    }
}

//销毁函数，传入一个线性表，并对其进行销毁

// void DestroyList(SqList *L)
// {
//     free(L->data);
//     free(L);
// }

Status ListExist(SqList L) //判断一个线性表是否为空表,若为空输出1，不为空输出0
{
    if (L.length == 0)
        return OK;
    else
        return Error;
}

Status DeleteList(SqList *L, int i, ElementType *e) //从线性表中删除第i个位置的某个元素,同时用e进行储存
{
    if (L->length > 0 && 0 < i <= L->length) //如果需要删除的i的位置是合法范围，就使用e来进行保存，并返回ok，其余情况返回error
    {
        int j = 0;
        *e = L->data[i - 1];
        for (j = i; j <= L->length; j++)
        {
            L->data[j - 1] = L->data[j];
        }
        L->length-=1;
        return OK;
    }
    else
        return Error;
}

int GetListLen(SqList L)
{
    int len = L.length;
    return len;
}

Status ListSort(SqList *L, int reverse) //对于线性表排序 (reverse=1为逆序从大到小,reverse=-1为顺序从小到大)
{
    int len = L->length;
    if (len <= 0)
        return Error;
    int i, j;
    if (reverse == 1)
    {
        for (i = 0; i < len - 2; i++)
        {
            for (j = 0; j < len - 1 - i; j++)
            {
                int temp;
                if (L->data[j] < L->data[j + 1])
                {
                    temp = L->data[j];
                    L->data[j] = L->data[j + 1];
                    L->data[j + 1] = temp;
                }
            }
        }
    }
    else if (reverse == -1)
    {
        for (i = 0; i < len - 2; i++)
        {
            for (j = i + 1; j < len - 1 - i; j++)
            {
                if (L->data[j] > L->data[j + 1])
                {
                    int temp;
                    temp = L->data[j];
                    L->data[j] = L->data[j + 1];
                    L->data[j + 1] = temp;
                }
            }
        }
    }
}

Status GetMax(SqList L, ElementType *e) //输出线性表中数据的最大值,用e来装该数据
{
    int len = GetListLen(L);
    int i;
    ElementType max = L.data[0];
    if (len <= 0)
        return Error;
    else
    {
        for (i = 1; i < len; i++)
        {
            if (L.data[i] > max)
            {
                max = L.data[i];
            }
        }
        *e = max;
        return OK;
    }
}

Status GetMin(SqList L, ElementType *e) //输出线性表中数据的最小值，用e来装该数据
{
    int len = GetListLen(L);
    int i;
    ElementType min = L.data[0];
    if (len <= 0)
        return Error;
    else
    {
        for (i = 1; i < len; i++)
        {
            if (L.data[i] < min)
            {
                min = L.data[i];
            }
        }
        *e = min;
        return OK;
    }
}

Status output(SqList L)
{
    int len = L.length, i = 0;
    if (len <= 0)
        return Error;
    else
    {
        for (i = 0; i < len; i++)
        {
            printf("%d ", L.data[i]);
            printf("\n");
        }
        printf("len=%d", len);
        return OK;
    }
}
//通过函数指针来进行对SqList的每个元素进行操作
// Status ListTraverse(SqList *L,bool visit(SqList))
// {
    
// }