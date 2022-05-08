// Task : https://beta.programming.in.th/tasks/0040
// Sol : Practice lambda and function pointer
// Author : Jo
// Date : 10/4/2022

#include <bits/stdc++.h>


void solve(int last_digit, const std::function<char(int)> checker)
{
    std::cout << checker(last_digit) << "\n";
}

int main(void)
{
    int test_case; 
    std::cin >> test_case;

    while(test_case--)
    {
        std::string str;
        std::cin >> str;

        if(str.size() == 1 and str[0] == '2')
        {
            std::cout << "T\n";
        } else {
            // Extract last element from the string
            // And create lambda function for checking an answer
            solve(str.end()[-1]-'0', [](int x){
                return (x%2) ? 'T' : 'F';
            });
        }


    }

    return 0;
}