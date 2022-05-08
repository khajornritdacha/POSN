#include <bits/stdc++.h>


void ForEach(std::vector<int> values, const std::function<void(int)> &func)
{
    for(int val : values)
        func(val);
}

void PrintAsterik(int rep)
{
    for(int i = 0; i < rep; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
}

int main(void) {
    std::vector<int> values = {1, 5, 4, 2, 3};

    int a = 10;

    // [] is capture which receives variable outside(not in parameter), [=] receieve as a copy, [&] receieve as a reference
    auto lambda = [=](int value) mutable { a++; std::cout << value+a << std::endl; };

    ForEach(values, lambda);

    // Send Function as an argument
    ForEach(values, PrintAsterik);
    
    // Store function inside function pointer
    auto AsterikFunc = PrintAsterik;
    ForEach(values, AsterikFunc);

    std::function<void(int)> Asterik = PrintAsterik;
    ForEach(values, Asterik);

    return 0;
}