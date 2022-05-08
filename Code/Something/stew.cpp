#include<bits/stdc++.h>
using namespace std;
int n,minn=1e9,in[20];
vector <pair<int,int>> vec;
void gen (int lv){
    int tempp=1,temps=0;
    if(lv==n){
        for(int i=0;i<n;i++){
            if(in[i]==1){
                tempp*=vec[i].first;
                temps+=vec[i].second;
            }
        }
        if(abs(tempp-temps)<minn&&tempp!=1&&temps!=0){
            minn = abs(tempp-temps);
        }
        tempp = 1;
        temps = 0;
        return;
}
    for(int i=0;i<2;i++){
        in[lv] = i;
        gen(lv+1);
    }
}
main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vec.emplace_back(a,b);
    }
    gen(0);
    cout << minn;
    return 0;
}
