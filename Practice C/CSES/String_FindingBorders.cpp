#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int pi[N];
char str[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> (str);
    int n = strlen(str);
    for(int idx=0,i=1; i<n; i++){
        while(idx > 0 and str[i] != str[idx]){
            idx = pi[idx-1];
        }
        if(str[idx] == str[i])
            idx++;
        pi[i] = idx;
        //cout << pi[i] << " \n"[i==n-1];
    }

    int now = n-1;
    stack<int> st;
    while(pi[now] > 0){
        st.push(pi[now]);
        //cout << pi[now] << " ";
        now = pi[now]-1;
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
