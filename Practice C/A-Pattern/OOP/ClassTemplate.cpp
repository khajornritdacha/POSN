#include<bits/stdc++.h>
using namespace std;


template<typename T1, typename T2>
class Pair{
    public:
        T1 first;
        T2 second;
        Pair();
        Pair(const T1 &x, const T2 &y){
            first = x;
            second = y;
        }
};

template<typename T1>
class DA{
    private:
        int sz;
    public:
        T1* data;

        DA(){
            data = NULL;
            sz = 0;
        }

        void push_back(T1 val){
            T1* chua = new T1[sz+1];
            for(int i=0; i<sz; i++){
                chua[i] = data[i];
            }
            chua[sz] = val;
            sz++;
            delete [] data;
            data = chua;
        }

        int size(){
            return sz;
        }
};

main(){
    ///DIY Pair
    Pair<int, float> pa(10, 3.14);
    pair<int, float> pi(10, 3.998);
    cout << pa.first << " " << pa.second << "\n";
    cout << pi.first << " " << pi.second << "\n";

    ///My vector
    DA<int> vec;
    vec.push_back(5);
    for(int i=0; i<vec.size(); i++){
        cout << vec.data[i] << " ";
    }
}
