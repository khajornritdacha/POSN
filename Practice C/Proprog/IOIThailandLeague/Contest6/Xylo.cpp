#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> la;
int ans,n,me[10],tran[110];
string str;
bool chk(int st){
    int cnt = 0, idx = st;
    int use[10];
    for(int i=0; i<7; i++)
        use[i] = me[i];
    while(true){
        if(use[idx] <= 0){
            break;
        }
        use[idx]--;
        cnt++;
        if(cnt >= n)
            break;
        idx++;
        idx%=7;
    }
    if(cnt >= n){
        la.emplace_back(st,idx);
        return true;
    }
    return false;
}
main(){
    tran['D'] = 0, tran['R'] = 1, tran['M'] = 2, tran['F'] = 3, tran['S'] = 4, tran['L'] = 5, tran['T'] = 6;
    int t;
    cin >> t;
    while(t--){
        la.clear();
        for(int i=0; i<7; i++)
            me[i] = 0;
        ans = 0;
        cin >> str;
        n = str.size();
        for(int i=0; i<n; i++){
            me[tran[str[i]]]++;
        }
        for(int i=0; i<7; i++){
            //cout << me[i] << " ";
            if(me[i] > 0 and chk(i)){
                ans++;
            }
        }
        if(ans == 0){
            cout << "NO";
        }else{
            cout << "YES ";
            if(la.size() > 1){
                cout << "MANY";
            }else{
                int pr[5];
                pr[0] = la.front().first, pr[1] = la.front().second;
                for(int i=0; i<2; i++){
                    if(pr[i] == 0)
                        cout << "D";
                    else if(pr[i] == 1)
                        cout << "R";
                    else if(pr[i] == 2)
                        cout << "M";
                    else if(pr[i] == 3)
                        cout << "F";
                    else if(pr[i] == 4)
                        cout << "S";
                    else if(pr[i] == 5)
                        cout << "L";
                    else
                        cout << "T";
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
}
