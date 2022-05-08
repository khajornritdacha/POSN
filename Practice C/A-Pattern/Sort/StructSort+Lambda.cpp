#include <bits/stdc++.h>
using namespace std;

///Comparator inside struct
///Comparator Function
///Lambda
///true -> come first

///Swap Space
///https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5014

const int N = 1e6+10;
using ll = long long;

struct DATA{
    int a,d;

    /*DATA operator + (const DATA &other){ ///C = A+B

    }*/

    bool operator < (const DATA &other){ ///A < B
        if(a > d and other.a <= other.d){ ///A is good and Other is bad
            return true;
        }
        if(other.a > other.d and a <= d){ ///A is bad and Other is good
            return false;
        }
        if(a > d and other.a > other.d){ ///Both A and Other are good
            return d < other.d;
        }
        return a > other.a; ///Both A and Other are bad
    }

};

bool cmp(const DATA &A, const DATA &B){
    if(A.a > A.d and B.a <= B.d){ ///A is good and Other is bad
        return true;
    }
    if(B.a > B.d and A.a <= A.d){ ///A is bad and Other is good
        return false;
    }
    if(A.a > A.d and B.a > B.d){ ///Both A and Other are good
        return A.d < B.d;
    }
    return A.a > B.a; ///Both A and Other are bad
}

DATA a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> a[i].d >> a[i].a;
        }

        ///Stl Sort use '<'
        sort(a+1, a+n+1); ///Comparator inside struct

        sort(a+1, a+n+1, cmp); ///Comparator Funciton

        sort(a+1, a+n+1, [&](const DATA &A, const DATA &B){ ///Lambda
            if(A.a > A.d and B.a <= B.d){ ///A is good and Other is bad
                return true;
            }
            if(B.a > B.d and A.a <= A.d){ ///A is bad and Other is good
                return false;
            }
            if(A.a > A.d and B.a > B.d){ ///Both A and Other are good
                return A.d < B.d;
            }
            return A.a > B.a; ///Both A and Other are bad
        });

        ll now = 0, ans = 1e18;
        for(int i = 1; i <= n; i++){
            now -= a[i].d;
            ans = min(ans, now);
            now += a[i].a;
        }
        cout << -1*ans << "\n";

        /*cout << "--------------\n";
        for(int i = 1; i <= n; i++){
            cout << a[i].a << " " << a[i].d << "\n";
        }
        cout << "--------------\n";*/
    }
    return 0;
}
