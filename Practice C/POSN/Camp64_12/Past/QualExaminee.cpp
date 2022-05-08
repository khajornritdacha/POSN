#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
struct ST{
    char name[35];
    double score;
};
ST st[N];
int n,cnt;
double sum;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        ST tmp;
        cin >> tmp.name >> tmp.score;
        st[i] = tmp;
        sum+=tmp.score;
    }
    sum/=n;
    for(int i=1; i<=n; i++){
        if(st[i].score > sum)
            cnt++;
    }
    cout << cnt << '\n';
    for(int i=1; i<=n; i++){
        if(st[i].score > sum){
            cout << st[i].name << "\n";
        }
    }
}
