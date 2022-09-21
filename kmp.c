#include"getnext.h"
#include<stdio.h>
int Index(char *Str,char *T,int pos)//返回子串T在主串Str的第pos个字符后的位置，如果不存在，则返回0
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
