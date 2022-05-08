#include<bits/stdc++.h>
using namespace std;
int cls,n,ava[105],ump[10005];
vector<queue<int>> vec(105);
queue<int> qq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> cls >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        ump[y] = x;
    }
    while(1){
        char c;
        int x;
        cin >> c;
        //cout << c << " " << x << "\n";
        if(c=='X'){
            cout << "0\n";
            return 0;
        }
        if(c=='D'){
            if(!qq.empty()){
                cout << vec[qq.front()].front() << "\n";
                vec[qq.front()].pop();
                if(vec[qq.front()].empty()){
                    ava[qq.front()] = 0;
                    qq.pop();
                }
            }else
                cout << "empty\n";
        }else{
            cin >> x;
            if(ava[ump[x]]==0){
                ava[ump[x]] = 1;
                qq.push(ump[x]);
            }
            vec[ump[x]].push(x);
            //cout << ump[x] << " " << vec[ump[x]].size() << "\n";
        }
    }
}
