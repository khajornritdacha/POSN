#include <bits/stdc++.h>
using namespace std;

///https://beta.programming.in.th/tasks/codecube_123

void test_case(){
    string pa,str;
    cin >> str >> pa;
    int lo[pa.size()+5] = {}, idx=0, n = str.size(), m = pa.size();
    for(int i=1; i<m; i++){
        while(idx > 0 and pa[idx] != pa[i])
            idx = lo[idx-1];
        if(pa[idx] == pa[i])
            idx++;
        lo[i] = idx;
    }

    vector<int> vec;
    vector<char> ans;
    idx = 0;
    for(int i=0; i<n; i++){
        while(idx > 0 and str[i] != pa[idx])
            idx = lo[idx-1];
        if(pa[idx] == str[i])
            idx++;
        if(idx == m){
            for(int j=0; j<m-1; j++){ vec.pop_back(), ans.pop_back(); }
            idx = (vec.empty() ? 0 : vec.back());
        }else{
            vec.push_back(idx);
            ans.push_back(str[i]);
        }
    }
    if(ans.empty()){
        cout << "No COI Secret Code\n";
    }else{
        for(char an : ans)
            cout << an;
        cout << "\n";
    }
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
}
