#include<stdio.h>
int GetNext(char *T, int num) //由传入的模式串，以及next数组的下标返回对应的next的值
{
    if (num == 1)//初始设定
        return 0;
    else if (num >=2)//这里采用递归的思想采用next[num-1]来求next[num]
    {
        int k;
        k = GetNext(T,num - 1);//先求出k的值。即在字符数组下标为0到num-3这num-2个数内有k-1个前缀等于后缀（用next[num-1]-1表示）
        //即此处数组下标为0到k-2的这一段前缀等于后缀，现在多加1位即判断数组下标为k-1和num-1，如果相等则return k+1（长度为k的前缀等于后缀）
        while (T[k - 1] != T[num - 2] )
        {
            k=GetNext(T,k);//如果不相等，就取m=next[k],即对于前k-1个数，也就是上面提到的0,到k-2这一段，有长度为m-1的前缀等于后缀
            if (k==0) return 1;//我们希望看到T[m-1]=T[num-2],这样我们就能得到长度为m的前缀等于后缀。所以我们令这里的k=m=next[k]。
        }//依次类推知道当k退回到第一位的时候，即没有找到与T[num-2]相等的字符，就返回1
        return (k+1);
    }
}

int Getlen(char *T)//返回数组长度
{
    int po = 0;
    while(T[po] !='\0')
    {
        po++;
    }
    return po;
} 

void GetNextList(char *T, int next[])//next数组从1开始储存
{
    int i=1,len=Getlen(T);
    for(i=1;i<=len;i++)
    {
        next[i]=GetNext(T,i);
    }

    for(i=1;i<=len;i++)//测试用，无实际意义
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

