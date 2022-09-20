#include "array.h"
int main()
{
    SqList p;
    int t[10]={1,5,4,19,6,8,4,16,25,9};
    int max = 0,min = 0;
    InitList(&p);
    CreateList(&p,t,10);
    Insertelement(&p,3,7);
    output(p);
    return 0;
}
