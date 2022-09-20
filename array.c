#include "array.h"
/*
ADT ���Ա�(List)
Data �������� ElementType
    ÿһ��Ԫ��ֻ��һ��ǰ����һ����̣����ڳ��˵�һ�������һ��Ԫ�����⣬����Ԫ�ؾ���Ψһ��ǰ���ͺ�̣�����Ԫ��֮����һ��һ�Ĺ�ϵ��
    ��һ������ֻ��Ӧһ��ֵ��(���������ȸ߼��ṹ)

    ������
    SqList* InitList(Maxsize(���Maxsize��ȫ�ֱ����Ϳ��Բ��ô�)):����û�����ϵ���ʽ��ѡ��ʹ�÷���һ��ָ�����ʽ���½�һ�����Ա�
    Status DestroyList(&L)����������һ�����Ա���free������������
    ListExist(&L):��������һ�����Ա��ж����Ƿ�Ϊ�ձ�
    ListEmpty(&L):����һ�����Ա��������
    DeleteList(&L):�����Ա���ɾ��ĳ��Ԫ��
    GetListLen(L):������Ա�ĳ���
    ListSort(&L��int reverse=-1,1):�������Ա����� (reverse=1Ϊ����reverse=-1Ϊ˳��)
    GetMax(&L):������Ա������ݵ����ֵ
    GetMin(&L):������Ա������Сֵ
*/

//������д��һ���������й��ڻ�ȡԪ�صĲ���
//�����д���һ�����Ա�L,�Լ���Ҫ��ȡ��Ԫ��λ���±�i,�Լ�����õ�����ͨ��e�����б���
Status Getelement(SqList L, int i, ElementType *e)
{
    if (L.length > 0 && 0 < i <= L.length) //��������i��λ���ǺϷ���Χ����ʹ��e�����б��棬������ok�������������error
    {
        *e = L.data[i - 1];
        return OK;
    }
    else
        return Error;
}

//������д�ڶ����������������ݽ������Ա��У��������Ϊ����ı��Լ���������λ��i���Լ���������Ԫ��ֵe
Status Insertelement(SqList *L, int i, ElementType e)
{
    if (L->length > 0 && 0 < i <= L->length) //��������i��λ���ǺϷ���Χ��
    {
        if (L->length + 1 <= Maxsize) //��������ƶ�һλ
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

//��һ�³�ʼ�����������ٺ���
//����д��ʼ������������һ��ָ��

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
        { //ͨ��ѭ��������Ԫ��ȫ����������˳�����
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

//���ٺ���������һ�����Ա��������������

// void DestroyList(SqList *L)
// {
//     free(L->data);
//     free(L);
// }

Status ListExist(SqList L) //�ж�һ�����Ա��Ƿ�Ϊ�ձ�,��Ϊ�����1����Ϊ�����0
{
    if (L.length == 0)
        return OK;
    else
        return Error;
}

Status DeleteList(SqList *L, int i, ElementType *e) //�����Ա���ɾ����i��λ�õ�ĳ��Ԫ��,ͬʱ��e���д���
{
    if (L->length > 0 && 0 < i <= L->length) //�����Ҫɾ����i��λ���ǺϷ���Χ����ʹ��e�����б��棬������ok�������������error
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

Status ListSort(SqList *L, int reverse) //�������Ա����� (reverse=1Ϊ����Ӵ�С,reverse=-1Ϊ˳���С����)
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

Status GetMax(SqList L, ElementType *e) //������Ա������ݵ����ֵ,��e��װ������
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

Status GetMin(SqList L, ElementType *e) //������Ա������ݵ���Сֵ����e��װ������
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
//ͨ������ָ�������ж�SqList��ÿ��Ԫ�ؽ��в���
// Status ListTraverse(SqList *L,bool visit(SqList))
// {
    
// }