#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
string str;
int t;
void solve(int &l, int &r, int want){
    if(l>r)
        return;
    vector<int> add,mul,ex;
    add.emplace_back(l-1), mul.emplace_back(l-1), ex.emplace_back(l-1);
    int pa = 0;
    for(int i=l; i<=r; i++){
        if(str[i] == ')')
            pa--;
        if(str[i] == '(')
            pa++;
        if(pa) continue;
        else if(str[i] == '+')
            add.emplace_back(i);
        else if(str[i] == '*')
            mul.emplace_back(i);
        else if(str[i] == '^')
            ex.emplace_back(i);
    }
    add.emplace_back(r+1), mul.emplace_back(r+1), ex.emplace_back(r+1);
    if(add.size()>2){
        if(want+1 > add.size()){
            l = r+1;
        }else{
            l = add[want-1]+1;
            r = add[want]-1;
        }
    }else if(mul.size()>2){
        if(want+1 > mul.size()){
            l = r+1;
        }else{
            l = mul[want-1]+1;
            r = mul[want]-1;
        }
    }else if(ex.size()>2){
        if(want+1 > ex.size()){
            l = r+1;
        }else{
            l = ex[want-1]+1;
            r = ex[want]-1;
        }
    }else if(str[l] == '(' and str[r] == ')' and want == 1){
        l++, r--;
    }else if(l!=r or want!=1){
        l = r+1;
    }
}
main(){
    cin >> str >> t;
    while(t--){
        vector<int> vec;
        int l=0, r=str.size()-1;
        while(true){
            int x;
            cin >> x;
            if(x==0) break;
            vec.emplace_back(x);
            //cout << "L&R : " << l << " " << r << "\n";
            solve(l, r, x);
        }
        //cout << "L&R : " << l << " " << r << "\n";
        for(int i=vec.size()-1; i>=0; i--)
            cout << "op("<<vec[i]<<",";
        cout << "p";
        for(int v : vec)
            cout << ")";
        cout << "=";
        if(l<=r){
            for(int i=l; i<=r; i++)
                cout << str[i];
        }else{
            cout << "null";
        }
        cout << "\n";
    }
}
