#include <iostream>
using namespace std;

// tiling problem
int tiling(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
        
    return tiling(n - 1) + tiling(n - 2);
}

int main()
{
    cout << tiling(3);
    return 0;
}
