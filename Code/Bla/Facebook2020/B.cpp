#include<bits/stdc++.h>
using namespace std;
int cnt,t;
main()
{
    FILE *fs,*fi;
    fs=fopen("input.txt","r");
    fi=fopen("output.txt","w");
    fscanf(fs,"%d",&t);
    while(cnt<t)
    {
        int n;
        char temp;
        fscanf(fs,"%d%c",&n,&temp);
        int a[3]={0,0,0};
        for(int i=0; i<n; i++)
        {
            char x;
            fscanf(fs,"%c",&x);
            a[x-'A']++;
        }
        fprintf(fi,"Case #%d: ",++cnt);
        if(abs(a[0]-a[1])<3)
        {
            fprintf(fi,"Y\n");
        }
        else
        {
            fprintf(fi,"N\n");
        }
    }
}
