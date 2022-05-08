#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int C,R,st,a[N][N];
bool dp[N][N];

int main(void){
    cin >> C >> st >> R;
   
    dp[0][st] = 1;

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
            if(a[i][j] == 0)
                dp[i][j] = dp[i-1][j-1] | dp[i-1][j] | dp[i-1][j+1];
        }
    }

    int ed = -1;
    for(int j = 1; j <= C; j++) if(dp[R][j]) ed = j;

    assert(ed > 0);

    stack<int> st;
    for(int i = R; i >= 1; i--){
        if(dp[i-1][ed-1]) st.push(2), ed--;
        else if(dp[i-1][ed]) st.push(3);
        else st.push(1), ed++;
    }

    while(!st.empty()){
        cout << st.top() << "\n";
        st.pop();
    }

    return 0;
}