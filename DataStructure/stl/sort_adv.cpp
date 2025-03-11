// 3 ways to sort data
// 1.Define < operator for a data type
// 2.Create comparator function
// 3.Create lambda function

#include <bits/stdc++.h>
using namespace std;

struct pii{
    int first, second;
    // bool operator < (const pii &other) const {
    //     if(first != other.first){
    //         return (first < other.first);
    //     }
    //     return (second > other.second);
    // }
};

// bool cmp(const pii a, const pii b){
//     if(a.first != b.first){
//         return (a.first < b.first);
//     }
//     return (a.second > b.second);
// }

int main(void){
    vector<pii> vec;
    vec.push_back({1, 3});
    vec.push_back({1, 5});
    vec.push_back({1, 10});
    vec.push_back({2, 1});

    // < operator
    // sort(vec.begin(), vec.end());

    // Comparator Function
    // sort(vec.begin(), vec.end(), cmp);

    // Lambda
    sort(vec.begin(), vec.end(), [&](const pii &a, const pii &b){
        if(a.first != b.first){
            return (a.first < b.first);
        }
        return (a.second > b.second);
    });

    for(auto v : vec){
        cout << v.first << " " << v.second << "\n";
    }
    cout << "\n";


    return 0;
}