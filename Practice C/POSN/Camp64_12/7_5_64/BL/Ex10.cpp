#include<bits/stdc++.h>
using namespace std;

string str;
char want;

main(){
    ///Overall Complexity -> time : O(logN)
    cin >> str >> want;
    sort(str.begin(), str.end());
    int l=0, r=(int)str.size()-1, mid, ans = 1e9;
    ///Find leftmost position that equal to want
    while(l<=r){
        mid = (l+r)/2;
        if(str[mid] >= want){
            r = mid-1;
            ans = min(ans, mid);
        }else if(str[mid] < want){
            l = mid+1;
        }
    }

    if(ans != 1e9 and str[ans] == want){
        ///Find rightmost position that equal to want
        l = ans, r = (int)str.size()-1;
        int ans2=ans;
        while(l<=r){
            mid = (l+r)/2;
            if(str[mid] == want){
                l = mid+1;
                ans2 = max(ans2, mid);
            }else{
                r = mid-1;
            }
        }
        cout << ans2-ans+1;
    }else{
        cout << 0;
    }
}
