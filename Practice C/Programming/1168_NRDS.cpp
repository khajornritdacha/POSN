#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int n;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int a=0;a<=9;a++){
        vec.emplace_back(a);
    }
    for(int b=1;b<=9;b++)
        for(int a=b+1;a<=9;a++){
            vec.emplace_back(b*10+a);
    }
    for(int c=1;c<=9;c++)
        for(int b=c+1;b<=9;b++){
            for(int a=b+1;a<=9;a++)
                vec.emplace_back(c*1e2+b*10+a);
    }
    for(int d=1;d<=9;d++)
    for(int c=d+1;c<=9;c++)
        for(int b=c+1;b<=9;b++){
            for(int a=b+1;a<=9;a++)
                vec.emplace_back(d*1e3+c*1e2+b*10+a);
    }
    for(int e=1;e<=9;e++)
    for(int d=e+1;d<=9;d++)
    for(int c=d+1;c<=9;c++)
        for(int b=c+1;b<=9;b++){
            for(int a=b+1;a<=9;a++)
                vec.emplace_back(e*1e4+d*1e3+c*1e2+b*10+a);
    }
    for(int f=1;f<=9;f++)
    for(int e=f+1;e<=9;e++)
    for(int d=e+1;d<=9;d++)
    for(int c=d+1;c<=9;c++)
        for(int b=c+1;b<=9;b++){
            for(int a=b+1;a<=9;a++)
                vec.emplace_back(f*1e5+e*1e4+d*1e3+c*1e2+b*10+a);
    }
    for(int g=1;g<=9;g++)
    for(int f=g+1;f<=9;f++)
    for(int e=f+1;e<=9;e++)
    for(int d=e+1;d<=9;d++)
    for(int c=d+1;c<=9;c++)
        for(int b=c+1;b<=9;b++){
            for(int a=b+1;a<=9;a++)
                vec.emplace_back(g*1e6+f*1e5+e*1e4+d*1e3+c*1e2+b*10+a);
    }
    for(int h=1;h<=9;h++)
    for(int g=h+1;g<=9;g++)
    for(int f=g+1;f<=9;f++)
    for(int e=f+1;e<=9;e++)
    for(int d=e+1;d<=9;d++)
    for(int c=d+1;c<=9;c++)
        for(int b=c+1;b<=9;b++){
            for(int a=b+1;a<=9;a++)
                vec.emplace_back(h*1e7+g*1e6+f*1e5+e*1e4+d*1e3+c*1e2+b*10+a);
    }
    vec.emplace_back(123456789);
    //cout << vec.size();
    cin >> n;
    for(int i=0;i<n;i++){
        long long q;
        cin >> q;
        if(q>=vec.size())
            cout << "-1";
        else
            cout << vec[q];
        cout << "\n";
    }
}
