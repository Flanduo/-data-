#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
#define Ture 1
#define False 0
#define OK 1
#define Error 0
typedef int Status; //����״̬���ͣ���int���ͷ��غ���ִ�е�״̬

typedef int ElementType; //�����int �����滻Ϊ���豣�����������
// typedef struct
// {
//     ElementType data*;
//     int length;
// } SqList; //���ﹹ����һ����ΪSqList�����Ա�ṹ�����ݰ��������Լ���¼������

typedef struct
{
    ElementType data[Maxsize];
    int length;
} SqList; //���ﹹ����һ����ΪSqList�����Ա�ṹ�����ݰ��������Լ���¼������


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
