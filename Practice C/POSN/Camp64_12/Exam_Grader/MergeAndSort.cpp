#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int S,n,T,a[N][N],sz[N];
vector<int> vec;

main(){
    cin >> S >> n >> T;
    vec.emplace_back(2e9);
    for(int i=0; i<S; i++){
        while(sz[i] < n){
            int x;
            cin >> x;
            if(sz[i] != 0 and x < a[i][sz[i]-1])
                break;
            a[i][sz[i]++] = x;
            vec.emplace_back(x);
        }
    }
    sort(vec.rbegin(), vec.rend());
    if(T == 0){
        for(int i=1; i<vec.size(); i++)
            cout << vec[i] << " ";
    }else if(T == 1){
        for(int i=1; i<vec.size(); i+=2)
            cout << vec[i] << " ";
    }else{
        for(int i=2; i<vec.size(); i+=2)
            cout << vec[i] << " ";
    }
}
