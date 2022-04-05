#include <bits/stdc++.h>
using namespace std;

void maximum_pq(){
    //By default, pq.top() is the maximum element
    priority_queue<int> pq;

    for(int i = 10; i <= 20; i++){
        pq.push(i);
    }

    cout << "Size : " << pq.size() << "\n";
    cout << "Maximum element : " << pq.top() << "\n";
    
    cout << "Iterate through pq (Get element in decreasing order)\n";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

void minimum_pq(){
    //We can modify the comparator inside priority queue so that the top element is the minimum element
    priority_queue<int, vector<int>, greater<int>> pq;
     for(int i = 10; i <= 20; i++){
        pq.push(i);
    }

    cout << "Size : " << pq.size() << "\n";
    cout << "Minimum element : " << pq.top() << "\n";
    
    cout << "Iterate through pq (Get element in ascending order)\n";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(void){
    //push, top, pop, size, empty
    //Priority_queue is a heap
    //By default it is a max heap
    maximum_pq();
    
    cout << "\n------------------------------------------\n";
    
    //We can declare pq in ascending order as well
    //In this case, our pq is min heap
    minimum_pq();
   


    

    
    return 0;
}