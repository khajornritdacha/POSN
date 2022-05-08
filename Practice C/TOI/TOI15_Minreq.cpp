#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tu;
const int N=15,M=1e7+10;
int L[N],P[N],qs[M],a[M],times[N],n,m,tc,pos[N];
vector<tu> vec;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> tc;
    for(int i=1; i<=n; i++){
        cin >> L[i];
    }
    for(int i=1; i<=n; i++){
        cin >> P[i];
    }
    sort(L+1, L+1+n), sort(P+1, P+1+n);
    for(int i=1; i<=n; i++){
        L[i]-=P[i];
        //cout << "LEFT : " << L[i] << " \n"[i==n];
    }
    for(int i=1; i<=m; i++){
        cin >> a[i];
        qs[i]=a[i]+qs[i-1];
    }
    for(int i=1; i<=tc; i++){
        cin >> times[i];
    }
    for(int test=1; test<=tc; test++){
        vec.clear();
        int t = times[test];
        bool ok = true;
        pos[0] = 0, pos[n+1]=m+1;
        for(int i=1; i<=n; i++){
            cin >> pos[i];
        }
        for(int i=2; i<=n+1; i++){
            vec.emplace_back(qs[pos[i]-1]-qs[pos[i-1]-1], pos[i-1], pos[i]-1);
            //cout << "CHK : " << qs[pos[i]-1]-qs[pos[i-1]-1] << " " <<  pos[i-1] << " " <<  pos[i]-1 << "\n";
        }
        sort(vec.begin(), vec.end());
        for(int num=0; num<vec.size(); num++){
            int cnt=0,sum=0,waste,st,ed;
            tie(waste, st, ed) = vec[num];
            //cout << "VEC :  " << num+1 << " " << waste << " " << st << " " << ed << "\n";
            for(int i=st; i<=ed; i++){
                if(sum+a[i]>L[num+1]){
                    sum=0;
                    cnt++;
                }
                sum+=a[i];
                //cout << "IDX : " << i << " " << sum << " " << cnt << " " << t << "\n";
                if(cnt>=t or a[i]>L[num+1]){
                    ok=false;
                    break;
                }
            }
            if(!ok)
                break;
        }
        cout << (ok ? "P" : "F") << "\n";
    }
}
