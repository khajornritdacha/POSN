#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,Q,a[N],id[N],num,cmp[N];
bool vi[N];

///https://beta.programming.in.th/tasks/codecube_226

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        if(!vi[i]){
            ++num;
            vi[i] = true;
            id[i] = 1;
            cmp[i] = num;
            int u = a[i], cnt = 2;
            while(u != i){
                vi[u] = true;
                id[u] = cnt++;
                cmp[u] = num;
                u = a[u];
            }
        }
    }

    /*cout << num << "\n";
    for(int i = 1; i <= n; i++){
        cout << cmp[i] << " \n"[i==n];
    }
    for(int i = 1; i <= n; i++){
        cout << id[i] << " \n"[i==n];
    }*/


    while(Q--){
        int S,E,A,B; cin >> S >> E >> A >> B;
        if(cmp[S] == cmp[E] and cmp[A] != cmp[S] and cmp[B] != cmp[S]){ ///They are in the same component and swapping does not relate to them at all
            cout << "DEAD\n";
        }else if(cmp[A] != cmp[B]){ ///After swapping between two different they will merge together into 1 large components
            if((cmp[S] == cmp[A] or cmp[S] == cmp[B]) and (cmp[E] == cmp[A] or cmp[E] == cmp[B])){ ///Nobita will die if and only if he is in the same large components as the Devil
                cout << "DEAD\n";
            }else{
                cout << "SURVIVE\n";
            }
        }else{ ///After swapping within the same component, it will break up into 2 smaller components
            int l = id[A]; ///One consists of nodes id from l+1 to r
            int r = id[B]; ///Another consists of nodes from 1 to l and r+1 to size of the component
            if(l > r) swap(l, r);
            //cout << l << " " << r << "\n";
            if((cmp[S] == cmp[A]) and (cmp[E] == cmp[A]) and ((l+1 <= id[S] and id[S] <= r and l+1 <= id[E] and id[E] <= r) or ((id[S] <= l or id[S] > r) and (id[E] <= l or id[E] > r)))){ ///Check if they are in the same small components
                cout << "DEAD\n";
            }else{
                cout << "SURVIVE\n";
            }
        }
    }

    return 0;
}
