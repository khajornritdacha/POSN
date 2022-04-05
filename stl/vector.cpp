#include <bits/stdc++.h>
using namespace std;

void forward_iteration(vector<int> &vec1){
    for(int v : vec1){
        cout << v << " ";
    }
    cout << "\n";

    for(int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << " ";
    }
    cout << "\n";

    for(auto it = vec1.begin(); it != vec1.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
}

void backward_iteration(vector<int> &vec1){
    for(int i = int(vec1.size())-1; i >= 0; i--){
        cout << vec1[i] << " ";
    }
    cout << "\n";

    for(auto it = vec1.rbegin(); it != vec1.rend(); it++){
        cout << *it << " ";
    }
    cout << "\n";
}

int main(void){
    //push_back, size, begin, end, front, back
    vector<int> vec1 = {1, 7, 2, 12, 5};
    vector<int> vec2(5); //declare vector size of 3 and filled with 0, by default. {0, 0, 0, 0, 0}
    vector<int> vec3(3, -1); //declare vector size of 3 and filled with -1 {-1, -1, -1}

    cout << "Forward Iteration\n";
    forward_iteration(vec1);
    
    cout << "\n\nBackward Iteration\n";
    backward_iteration(vec1);

    //Reverse function
    reverse(vec1.begin(), vec1.end());
    cout << "\n\nReverse vector : "; 
    for(int &v : vec1) cout << v << " ";
    cout << "\n";

    cout << "Size : " << vec1.size() << "\n";
    cout << "First element : " << vec1.front() << "\n";
    cout << "Last element : " << vec1.back() << "\n";
    
    vec1.push_back(100);
    cout << "New last element : " << vec1.end()[-1] << "\n";
    return 0;
}