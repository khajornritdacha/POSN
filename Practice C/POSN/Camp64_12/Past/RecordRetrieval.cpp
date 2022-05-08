#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
struct STU{
    char id[10],name[35],surname[55];
    int year;
};
STU st[N];
int n,cnt,want;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        STU tmp;
        cin >> tmp.id >> tmp.name >> tmp.surname >> tmp.year;
        st[i] = tmp;
    }
    cin >> want;
    for(int i=1; i<=n; i++){
        if(st[i].year == want){
            cnt++;
            cout << st[i].id << " " << st[i].name << " " << st[i].surname << "\n";
        }
    }
    if(cnt == 0)
        cout << "None";
}
