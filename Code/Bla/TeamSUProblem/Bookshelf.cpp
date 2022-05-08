#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
long long N,L;
long long h[100010],w[100010],dp[100010];
vector<long long> trs,trm;
struct fenwick{
    void ups(int i, long long val){
        while(i<=N){
            trs[i]+=val;
            i+=(i&-i);
        }
    }
    long long sum(int i){
        long long ans=0;
        while(i>=1){
            ans+=trs[i];
            i-=(i&-i);
        }
        return ans;
    }
};
struct segment{
    int ub(long long val){
        fenwick fen;
        int l=1,r=N,mid,ans=N+1;

        if(DEBUG){
            cout << "VAL: " << val << " ";
        }
        while(l<=r){
            mid=(l+r)/2;
            if(fen.sum(mid)>val){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    void upm(int pos, long long val){
        pos+=N-1;
        trm[pos]=val;
        for(int i=pos/2; i; i/=2){
            trm[i]=max(trm[i*2],trm[i*2+1]);
        }
    }
    long long mx(int l, int r){
        long long ans=0;
        for(l+=N-1,r+=N-1; l<=r; l/=2,r/=2){
            if((l%2)==1){
                ans=max(ans,trm[l++]);
            }
            if((r%2)==0){
                ans=max(ans,trm[r--]);
            }
        }
        return ans;
    }
};
main(){
    cin >> N >> L;
    segment seg;
    fenwick fen;
    for(int i=1; i<=N; i++){
        cin >> h[i] >> w[i];
    }
    trm.resize(2*N,0);
    trs.resize(N+1,0);
    for(int i=1; i<=N; i++){
        int k = seg.ub(L-w[i]);
        int k2=N-k+2;
        if(DEBUG){
            cout << "I&K: " << i << " " << k << " " << k2 << "\n";
        }
        seg.upm(i,h[i]);
        fen.ups(N-i+1,w[i]);
        dp[i]=min(dp[k2-1]+seg.mx(k2,i), dp[i-1]+h[i]);
        if(DEBUG){
            cout << "Now: " << dp[i] << "\n";
            cout << "Max: " << seg.mx(k2,i) << " " << dp[k2-1] << "\n";
        }
        /*if(DEBUG){
            for(int j=1; j<=N; j++){
                cout << fen.sum(j) << " ";
            }
            cout << "\n";
        }*/
    }
    cout << dp[N];
}
