#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;

int number_slot, number_stores, minimum_slot, arr[N];

bool chk(int expected_answer){
    int current_store = 1, current_sum = 0;
    priority_queue<int, vector<int>, greater<int>> maximum;
    
    for(int i = 1; i <= number_slot; i++){

        if(maximum.size()+1 <= minimum_slot){ //maintain pq so that it contain top-K maximum
            current_sum += arr[i];
            maximum.push(arr[i]);
        } else if(arr[i] > maximum.top()){ //if arr[i] is greater than current top-K maximum
            current_sum -= maximum.top();
            maximum.pop();
            current_sum += arr[i];
            maximum.push(arr[i]);
        }
        
        assert(current_sum <= 2e9);

        if(maximum.size() >= minimum_slot and current_sum >= expected_answer){
            while(!maximum.empty()) maximum.pop(); // clear pq
            current_sum = 0;
            if(++current_store > number_stores){
                return true;
            } 
        }
    }
    return false;    
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> number_slot >> number_stores >> minimum_slot;
    for(int i = 1; i <= number_slot; i++){
        cin >> arr[i];
    }

    int l = 0, r = 2e9, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        
        assert(l+r <= 2e9); //Fail if mid is int
        assert(mid <= 2e9);

        if(chk(mid)){ //Check if answer can be this value. If yes, so do all the values less than mid.
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    assert(ans > -1);

    cout << ans << "\n";

    return 0;
}