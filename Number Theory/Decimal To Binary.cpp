#include <iostream>
using namespace std;

string decToBinary(int n)
{
    string res;
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) res += '1';
        else res += '0';
    }
    return res;
}

// driver code
int main()
{
    int n = 32;
    cout << decToBinary(n) << endl;
}
