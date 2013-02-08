#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

#define MAXSIZE 100
typedef int keytype;
typedef struct
{
    keytype key;
}redtype;

typedef struct{
    redtype r[MAXSIZE+1];
    int length;
}SqList;

void Creat_list(SqList &L){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&L.r[i]);
    }
    L.length=n;
}

void print(SqList &L){
    int j;
    for(j=1;j<L.length;j++)
        printf("%d ",L.r[j]);
    printf("%d\n",L.r[L.length]);
}

void InsertSort(SqList &L){
    int i,j;
    for(i=2;i<=L.length;i++)
    {
        if(L.r[i].key<=L.r[i-1].key)
        {
            L.r[0]=L.r[i];
            for(j=i-1;L.r[0].key<L.r[j].key;j--)
                L.r[j+1]=L.r[j];
            L.r[j+1]=L.r[0];
        }
        print(L);
    }
}

void BInsertSort(SqList &L){
    int i,j;
    int low,high,m;
    for(i=2;i<=L.length;i++)
    {
        L.r[0]=L.r[i];
        low=1;high=i-1;
        while(low<=high)
        {
            m=(low+high)/2;
            if(L.r[0].key<L.r[m].key) high=m-1;
            else low=m+1;
        }
        for(j=i-1;j>=high+1;j--)
            L.r[j+1]=L.r[j];
        L.r[high+1]=L.r[0];
        print(L);
    }
}

int main()
{
    SqList L;
    Creat_list(L);
    BInsertSort(L);
    return 0;
}
