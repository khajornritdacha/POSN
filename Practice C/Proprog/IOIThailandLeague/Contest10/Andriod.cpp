#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,Q,M,inq[N],a[N];
deque<int> dq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q >> M;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    while(Q--){
        int i;
        cin >> i;
        //cout << M << "\n";
        if(!inq[i]){
            if(M < a[i]){
                while(!dq.empty() and M < a[i]){
                    M += a[dq.front()];
                    inq[dq.front()] = false;
                    dq.pop_front();
                }
            }
            M -= a[i];
            dq.push_back(i);
            inq[i] = true;
        }else{
            deque<int> tmp;
            while(!dq.empty() and dq.front() != i){
                tmp.push_back(dq.front());
                dq.pop_front();
            }
            if(!dq.empty())
                dq.pop_front();
            while(!tmp.empty()){
                dq.push_front(tmp.back());
                tmp.pop_back();
            }
            dq.push_back(i);
        }
    }
    cout << M;
}
