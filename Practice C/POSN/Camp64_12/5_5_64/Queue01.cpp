#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
queue<char> qq;
int n,m,a[N],b[N];

int main(void){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=m; i++){
        cin >> b[i];
    }
    int i=1, j=1;
    while(i <= n or j <=m){
        if(i <= n and j <= m){
            if(a[i] <= b[j]){
                qq.push('A');
                i++;
            }else{
                qq.push('B');
                j++;
            }
        }else if(i <= n){
            qq.push('A');
            i++;
        }else if(j <= m){
            qq.push('B');
            j++;
        }
    }
    while(!qq.empty()){
        cout << qq.front() << " ";
        qq.pop();
    }
}
