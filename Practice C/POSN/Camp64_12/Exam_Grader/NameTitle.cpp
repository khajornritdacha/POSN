#include<bits/stdc++.h>
using namespace std;

string name,surname;
int sex,age,mar;


main(){
    cin >> name >> surname;
    cin >> sex >> age >> mar;
    if(sex == 0){
        if(age < 15 or !mar)
            cout << "Miss";
        else
            cout << "Mrs.";
    }else{
        if(age >= 15)
            cout << "Mr.";
        else
            cout << "Master";
    }
    cout << " " << name << " " << surname;
}
