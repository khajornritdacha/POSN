#include <bits/stdc++.h>
using namespace std;

void demonstrate_pair(){
    //store a pair of values (does not required to be the same type)
    //The first element is pa.first
    //The second element is pa.second
    pair<int, int> pa = {3, 2};
    pair<int, char> dif_pair = {3, 'a'};

    pa.first = 10; //Change values in pair
    pa.second = 5;

    cout << "PAIR : " << pa.first << " " << pa.second << "\n";
    cout << "DIF : " << dif_pair.first << " " << dif_pair.second << "\n";
    
    //Store every elements in pair with tie keyword
    int fi, se;
    tie(fi, se) = pa;
    cout << fi << " " << se << "\n";

    //Use auto key word instead of tie
    auto [x, y] = pa;
    cout << x << " " << y << "\n";
}

void demonstrate_tuple(){
    cout << "TUPLE\n";
    tuple<int, int, char, float> tu = {1, 3, 'a', 4.5};
    //Access element by its index and change its value
    get<0>(tu)++;
    cout << get<0>(tu) << " " << get<1>(tu) << " " << get<2>(tu) << " " << get<3>(tu) << "\n";

    //Tie key word, a = first values, b = second values, and so on.
    int a, b;
    char c;
    float d;
    tie(a, b, c, d) = tu;
    cout << a << " " << b << " " << c << " " << d << "\n";

    //Use auto keyword instead of tie
    auto [m, n, o, p] = tu;
    cout << m << " " << n << " " << o << " " << p << "\n";
}

int main(void){
    //Pair and Tuple used to store a number of values in the same varaible
    //Pair can store exactly 2 values
    //Tuple can store any number of values, ie. 1, 2, 3, 4, 5, 6, ...

    demonstrate_pair();
    cout << "--------------------------------\n";


    demonstrate_tuple();
    cout << "--------------------------------\n";
   

    //By default, pair and tuple is sorted based on the first element. If the first elements are the same then the second element is compared.
    vector<pair<int, int>> vec = {{1, 5}, {10, 2}, {10, -1}};
    sort(vec.begin(), vec.end());

    cout << "Sort Pair\n";
    for(auto [x, y] : vec){
        cout << x << " " << y << "\n";
    }


    return 0;
}