#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q;
struct BOOK{
    int id,ts,sp,co;
    char name[55];
};
char dummy[10];
BOOK books[5010];
main(){
    //freopen("input3.txt", "r", stdin);
    //freopen("myout3.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        BOOK tmp;
        tmp.ts=0;
        cin >> tmp.id;

        ///very important
        scanf(" %99[^\n]", tmp.name);
        int namelength = strlen(tmp.name);
        tmp.name[namelength-1] = 0;
        ///

        cin >> tmp.sp >> tmp.co;
        books[i] = tmp;
    }
    cin >> Q;
    for(int tt=1; tt<=Q; tt++){
        int code,idx;
        cin >> code >> idx;
        if(code == 1){
            int qq;
            cin >> qq;
            for(int j=1; j<=n; j++){
                if(books[j].id == idx){
                    books[j].ts+=qq;
                }
            }
        }else{
            bool ok = false;
            for(int j=1; j<=n; j++){
                if(books[j].id == idx){
                    ok = true;
                    cout << books[j].id << " " << books[j].name << " " << books[j].ts << " " << books[j].ts*books[j].sp << " " << books[j].ts*(books[j].sp-books[j].co);
                }
            }
            if(!ok)
                cout << "Error";
            cout << "\n";
        }
    }
}
