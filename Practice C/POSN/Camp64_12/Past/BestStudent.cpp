#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct STU{
    char id[10],name[35],surname[55];
    float grade;
};
STU mx;
int n;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        STU tmp;
        cin >> tmp.id >> tmp.name >> tmp.surname >> tmp.grade;
        if(tmp.grade > mx.grade){
            mx = tmp;
        }
    }
    cout << setprecision(2) << fixed << mx.id << " " << mx.name << " " << mx.surname << " " << mx.grade << "\n";
}
