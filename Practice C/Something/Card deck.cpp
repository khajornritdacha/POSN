#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;
vector<string> vec01()
{
    vector<string>type = {"S","H","D","C"};
    vector<string>num = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    vector<string>decks;
    for(string t : type)
    {
        for(string n : num)
        {
            decks.push_back(n+t);
        }
    }
    return decks;
}
void printd(vector<string> v)
{
    for(string i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}
void findd(vector<string> v,string f)
{
    auto itr = find(v.begin(),v.end(),f);
    itr!=v.end() ? cout << distance(v.begin(),itr) : cout << "Invalid Card";
    cout << endl;
}
main()
{
    vector<string>deck = vec01();
    printd(deck);
    shuffle(deck.begin(),deck.end(),random_device());
    printd(deck);
    string f;
    cin >> f;
    findd(deck,f);
}
