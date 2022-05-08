#include<bits/stdc++.h>
using namespace std;
int t,xs,ys,xe,ye;
struct rect{
    int x1,y1,x2,y2;
};
main(){
    cin >> t;
    while(t--){
        rect a,b;
        cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
        cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
        xs=max(a.x1,b.x1);
        ys=max(a.y1,b.y1);
        xe=min(a.x2,b.x2);
        ye=min(a.y2,b.y2);
        if(a.x2<=b.x1||a.y2<=b.y1||b.x2<=a.x1||b.y2<=a.y1)
            cout << "No Overlap\n";
        else
            cout << max(a.x1,b.x1) << " " << max(a.y1,b.y1) << " " << min(a.x2,b.x2) << " " << min(a.y2,b.y2) << "\n";
        if(t!=0)
            cout << "\n";
    }
}
