#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
priority_queue < pair<int,int> > pq;
/*class Point
{
    int x;
    int y;
public:
    Point(int _x,int _y){
        x = _x;
        y = _y;
    }
    int getX() const { return x; }
    int getY() const { return y; }
};
class myComparator{
public:
    int operator() (const Point& p1, const Point& p2){
        return p1.getX() > p2.getX();
    }
};*/
main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //priority_queue <Point,vector<Point>, myComparator > pq;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    pq.emplace(a[1]*-1,1);
    for(int i=2; i<=n; i++)
    {
       //cout << pq.top().first << ' ' << pq.top().second << endl;
        while(1)
        {
            if(i-pq.top().second>k)
            {
                //cout << 11 << endl;
                pq.pop();
            }
            else
            {
                break;
            }
        }
        int now = (pq.top().first*-1)+a[i];
        pq.emplace(now*-1,i);
        //vec.emplace_back(now*-1,i);
    }
    while(pq.top().second!=n)
    {
        pq.pop();
    }
    cout << pq.top().first*-1 << endl;
    /*for(int i=0;i<vec.size()-1;i++){
        cout << vec[i].first << ' ' << vec[i].second << endl;
    }*/
    return 0;
}
