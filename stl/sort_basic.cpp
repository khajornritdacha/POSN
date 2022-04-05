#include <bits/stdc++.h>
using namespace std;

void print(const vector<int> &to_print){
    for(int v : to_print) cout << v << " ";
    cout << "\n";
}

void demonstrate_sort_vector(){
    vector<int> vec = {6, 4, 10, 2, 7};

    cout << "Sort in ascending order : ";
    sort(vec.begin(), vec.end());
    print(vec);
    
    cout << "Sort in descending order(with rbegin/ rend) : ";
    sort(vec.rbegin(), vec.rend());
    print(vec);

    //Shuffle does not use in competition. So, no need to remember it
    shuffle(vec.begin(), vec.end(), default_random_engine(0));

    cout << "Sort in descending order(with greater comparator) : ";
    sort(vec.begin(), vec.end(), greater<int>());
    print(vec);

}

void demonstrate_sort_array(){
    int arr[] = {3, 2, 10, 7, 1};
    int n = 5;
    
    cout << "Sort array in ascending order : ";
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) cout << arr[i] << " \n"[i==n-1]; //print new line when i == n-1
    
    cout << "Sort array in descending order : ";
    sort(arr, arr+n, greater<int>());
    for(int i = 0; i < n; i++) cout << arr[i] << " \n"[i==n-1]; //print new line when i == n-1
    
}

int main(void){

    demonstrate_sort_vector();
    cout << "----------------\n";
   
    demonstrate_sort_array();
}