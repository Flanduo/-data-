#include<stdio.h>
int GetNext(char *T, int num) //�ɴ����ģʽ�����Լ�next������±귵�ض�Ӧ��next��ֵ
{
    if (num == 1)//��ʼ�趨
        return 0;
    else if (num >=2)//������õݹ��˼�����next[num-1]����next[num]
    {
        int k;
        k = GetNext(T,num - 1);//�����k��ֵ�������ַ������±�Ϊ0��num-3��num-2��������k-1��ǰ׺���ں�׺����next[num-1]-1��ʾ��
        //���˴������±�Ϊ0��k-2����һ��ǰ׺���ں�׺�����ڶ��1λ���ж������±�Ϊk-1��num-1����������return k+1������Ϊk��ǰ׺���ں�׺��
        while (T[k - 1] != T[num - 2] )
        {
            k=GetNext(T,k);//�������ȣ���ȡm=next[k],������ǰk-1������Ҳ���������ᵽ��0,��k-2��һ�Σ��г���Ϊm-1��ǰ׺���ں�׺
            if (k==0) return 1;//����ϣ������T[m-1]=T[num-2],�������Ǿ��ܵõ�����Ϊm��ǰ׺���ں�׺�����������������k=m=next[k]��
        }//��������֪����k�˻ص���һλ��ʱ�򣬼�û���ҵ���T[num-2]��ȵ��ַ����ͷ���1
        return (k+1);
    }
}

int Getlen(char *T)//�������鳤��
{
    int po = 0;
    while(T[po] !='\0')
    {
        po++;
    }
    return po;
} 

void GetNextList(char *T, int next[])//next�����1��ʼ����
{
    int i=1,len=Getlen(T);
    for(i=1;i<=len;i++)
    {
        next[i]=GetNext(T,i);
    }

    for(i=1;i<=len;i++)//�����ã���ʵ������
    {
        printf("%d ",next[i]);
    }
}

//int main()
//{
//    char *T="ababaaababaa";
//    int a[]={};
//    GetNextList(T,a);
//    return 0;
//}

