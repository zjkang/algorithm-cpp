#include <iostream>
#include <vector>

using namespace std;

void print(const int &a)
{
    cout << "[lvalue] " << a << endl;
}

// accept rvalue
void print(int &&a)
{
    cout << "[rvalue] " << a << endl;
}

int main()
{
    // vector<int> a = {1, 2, 3};
    // cout << &a << endl;
    // vector<int> b(std::move(a));
    // cout << &b << endl;

    int a = 1;
    print(a);
    print(2); // rvalue cannot be referenced, int& a does not work, but an exception is const int&

    cout << "Done" << endl;
}