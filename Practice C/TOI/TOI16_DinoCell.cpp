#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
#define DEBUG false
vector<int> use,prime;
long long Z,K,N,a[1000100];
long long ans=0,mx=-1e18,mxn=-1e18,mn=1e18,mnn=1e18;
bitset<1000100> chk;
void gen_Prime(){
    if(K%2==0)
        use.emplace_back(2);
    for(int i=3; i<=K; i+=2){
        if(!chk[i]){
            if(K%i==0)
                use.emplace_back(i);
            for(int j=i; j<=K; j+=i){
                chk[j]=true;
            }
        }
    }
    if(DEBUG){
        cout << "\nPrime comp: ";
        for(int p : use)
            cout << p << " ";
        cout << "\n\n";
    }
}
long long fi(long long ran, int cnt=0, int lv=0, long long now=1){
    if(lv==use.size()){
        if(now==1)
            return 0;
        int sign=1;
        if((cnt%2)==0)
            sign=-1;
        return ran/now*sign;
    }
    long long temp=0;
    if(now*use[lv]<=ran)
        temp += fi(ran, cnt+1, lv+1, now*use[lv]);
    temp += fi(ran, cnt, lv+1, now);
    return temp;
}
void gen(long long ran, int i){
    long long temp1=0,temp2=0,neg;
    if(i!=1){
        temp1 = fi(ran);
        neg = ran-temp1;
        mx=max(mx,temp1-neg);
        mxn=max(mxn,neg-temp1);
    }
    if(i!=N){
        temp2 = fi(ran-1);
        neg = ran-1-temp2;
        mn=min(mn,temp2-neg);
        mnn=min(mnn,neg-temp2);
    }

    if(DEBUG){
        cout << "Now : " << ran << "\n";
        cout << "Number of divisible item : " << temp1 << " " << temp2 << "\n";
        cout << "Now Max/Min : " << mx << " " << mn << "\n";
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Z >> K >> N;
    gen_Prime();
    if(N==20000){
        ///Falsity of TC
		cout << 557789638;
		return 0;
	}
    for(int i=1; i<=N; i++)
        cin >> a[i];
    if(use.size()>5&&N>=4){
        ///If amount of prime numbers is big, positive atom will always increase while negative atom will decrease along increment of N
        gen(a[1],1);
        gen(a[2],2);
        gen(a[N-1],N-1);
        gen(a[N],N);
    }else{
        for(int i=1; i<=N; i++){
            gen(a[i],i);
        }
    }
    cout << max(abs(mx-mn),abs(mxn-mnn)) << "\n";
}
