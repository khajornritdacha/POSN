#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+100;
string str;
int n,a[N];
int fc(int x, int y, int cd){
    if(cd == 1) return (x+y)*4/100+x+y;
    if(cd == 2) return (x+y)*8/100+x+y;
    return (x+y)*16/100+x+y;
}
void cal(int l, int r, int cd){
    for(int i=l; i<=r; i++){
        int x=1,y=1;
        if(a[i] == cd){
            while(i-x>=0 and a[i-x] == -1)
                x++;
            while(y+i<n and a[y+i] == -1)
                y++;
            a[i] = fc(a[i-x], a[y+i], cd);
            a[i-x] = a[y+i] = -1;
        }
    }
}
void solve(int l, int r){
    stack<int> par;
    for(int i=l; i<=r; i++){
        if(a[i] == -3){
            par.push(i);
        }else if(a[i] == -4){
            int tmp = par.top();
            a[par.top()] = a[i] = -1;
            par.pop();
            solve(tmp+1, i-1);
        }
    }
    for(int i=3; i>=1; i--){
        cal(l, r, i);
    }
}
main(){
    cin >>  str;
    n = str.size();
    for(int i=0; i<n; i++){
        if(str[i] >= 'A' and str[i] <= 'Z'){
            a[i] = 20;
        }else if(str[i] == '['){
            a[i] = -3;
        }else if(str[i] == ']'){
            a[i] = -4;
        }else{
            a[i] = str[i]-'0';
        }
    }
    solve(0, n-1);
    for(int i=0; i<n; i++)
        if(a[i] > 0){
            cout << a[i] << "\n";
            return 0;
        }
}
