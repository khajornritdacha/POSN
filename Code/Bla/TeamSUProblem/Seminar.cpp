#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using pi=pair<short,short>;
int N,K,ans;
short sch[10010],mem[10010][2010];
vector<pi> vec;
main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        short st,ed;
        cin >> st >> ed;
        sch[ed]=max(sch[ed],st);
    }
    for(int i=1; i<=1e4; i++){
        if(sch[i]!=0){
            vec.emplace_back(i,sch[i]);

            if(DEBUG){
                cout << sch[i] << " " << i << "\n";
            }
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<vec.size(); i++){
        short st,ed;
        tie(ed,st) = vec[i];
        if(i!=0){
            for(int j=0; j<=K; j++){
                mem[i][j]=mem[i-1][j];
            }
        }
        pi temp = {st,0};
        int k = lower_bound(vec.begin(),vec.end(),temp)-vec.begin();

        if(DEBUG){
            cout << "I&K: " << i << " " << k << "\n";
        }

        if(k==0){
            mem[i][0] = max(mem[i][0],(short)1);
        }else{
            mem[i][0] = max(mem[i][0],(short)(mem[k-1][0]+1));
        }

        if(DEBUG){
            cout << "K=0: " << mem[i][0] << "\n";
        }

        for(int j=1; j<=K; j++){

            if(DEBUG){
                cout << "K=" << j << ": " << mem[i][j] << " " << k << " " << mem[k-1][j] << "\n";
            }
            temp = {st,0};
            k = lower_bound(vec.begin(),vec.end(),temp)-vec.begin();
            if(k!=0){
                mem[i][j] = max(mem[i][j],(short)(mem[k-1][j]+1));
            }

            if(DEBUG){
                cout << "K=" << j << ": " << mem[i][j] << "\n";
            }

            temp = {st+1,0};
            k = lower_bound(vec.begin(),vec.end(),temp)-vec.begin();
            if(k!=0){
                mem[i][j] = max(mem[i][j], (short)(mem[k-1][j-1]+1));
            }

            if(DEBUG){
                cout << "K=" << j << ": " << mem[i][j] << "\n";
            }

        }
    }
    for(int i=0; i<=K; i++){
        ans = max(ans,(int) mem[vec.size()-1][i]);
    }
    cout << ans;
}
