#include<bits/stdc++.h>
using namespace std;
int n,A[100100];
main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    bool positive=false;
    int sum=0;
    int nowp,ansp,prep,nown,ansn,pren,maxneg;
    nowp=ansp=prep=maxneg=-1e9;
    nown=ansn=pren=1e9;
    for(int i=0; i<n; i++)
    {
        nowp=max(A[i],A[i]+prep);
        ansp=max(ansp,nowp);
        prep=nowp;
        nown=min(A[i],A[i]+pren);
        ansn=min(ansn,nown);
        pren=nown;
        sum+=A[i];
        if(A[i]>0)
            positive=true;
        else
            maxneg=max(maxneg,A[i]);
    }
    if(!positive)
    {
        cout << maxneg;
        return 0;
    }
    cout << max(ansp,sum-ansn);
}
