#include"getnext.h"
#include<stdio.h>
int Index(char *Str,char *T,int pos)//�����Ӵ�T������Str�ĵ�pos���ַ����λ�ã���������ڣ��򷵻�0
{
    int i,j;
    int lens=Getlen(Str);
    int lent=Getlen(T);
    i=pos,j=0;
    while(i<lens && j<lent)
    {
        if (j==0||Str[i]==T[j])
        {
            i++,j++;
        }

        else
        {
            j=GetNext(T,j+1)-1;
        }
    }
    if (j==lent)
    {
        return i-lent+1;
    }

    else return 0;
}

int main()
{
    int t;
    char *s="abccbaabbcab";
    char *m="abbc";
    t=Index(s,m,2);
    printf("%d",t);
    return 0;
}
