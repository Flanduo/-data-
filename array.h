#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
#define Ture 1
#define False 0
#define OK 1
#define Error 0
typedef int Status; //定义状态类型，用int类型返回函数执行的状态

typedef int ElementType; //这里的int 可以替换为所需保存的数据类型
// typedef struct
// {
//     ElementType data*;
//     int length;
// } SqList; //这里构造了一个名为SqList的线性表结构，内容包含表长，以及记录的数据

typedef struct
{
    ElementType data[Maxsize];
    int length;
} SqList; //这里构造了一个名为SqList的线性表结构，内容包含表长，以及记录的数据


Status Getelement(SqList L, int i, ElementType *e);
Status Insertelement(SqList *L, int i, ElementType e);
void InitList(SqList *L);
// void DestroyList(SqList *L);
Status ListExist(SqList L);
Status DeleteList(SqList *L, int i, ElementType *e);
int GetListLen(SqList L);
Status ListSort(SqList *L, int reverse);
Status GetMax(SqList L,ElementType *e);
Status GetMin(SqList L,ElementType *e);
void InitList(SqList *LP);
Status CreateList(SqList *LP, ElementType a[], int n);
Status output(SqList L);
