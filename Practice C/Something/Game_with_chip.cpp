#include<bits/stdc++.h>
using namespace std;
int x[205],y[205],n,m,k,maxx,maxy,minx,miny,step[5],cnt;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<k;i++){
        int r,c;
        cin >> r >> c;
        int tempx = x[i]-r;
        int tempy = y[i]-c;
        maxx = max(maxx,tempx);
        maxy = max(maxy,tempy);
        if(tempx<0)
            minx = min(minx,tempx);
        if(tempy<0)
            miny = min(miny,tempy);
    }
    if(maxx+maxy-minx-miny>n*m*2)
        cout << "-1\n";
    else{
        cnt+=maxx;
        step[0] = maxx;
        cnt+=maxy;
        step[1] = maxy;
        cnt-=minx;
        step[2] = maxx-minx;
        cnt-=miny;
        step[3] = maxy-miny;
        cout << cnt << "\n";
        for(int i=0;i<step[0];i++)
            cout << "U";
        for(int i=0;i<step[1];i++)
            cout << "L";
        for(int i=0;i<step[2];i++)
            cout << "D";
        for(int i=0;i<step[3];i++)
            cout << "R";
        }
    }

