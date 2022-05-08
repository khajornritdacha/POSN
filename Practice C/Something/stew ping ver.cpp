#include<bits/stdc++.h>
using namespace std;
int a[15],b[15],t[15];
int n,j,maxx=100000000;
void gen(int x);
main()
{
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        scanf("%d %d",&a[j],&b[j]);
    }
    gen(0);
    printf("%d",maxx);
}
void gen(int x)
{
    int kom=1,pet=0;
    if(x==n)
    {
        for(int k=0;k<n;k++)
        {
            if(t[k]!=0)
            {
                kom=kom*a[k+1];
                pet=pet+b[k+1];
            }
            //printf("%d ",t[k]);
        }
        //printf("\n");
        if(abs(kom-pet)<maxx&&kom!=1&&pet!=0)
        {
            maxx=abs(kom-pet);
        }
        kom=1;
        pet=0;
        return ;
    }
    for(int i=0;i<=1;i++)
    {
        t[x]=i;
        gen(x+1);
    }
}
