#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s = "647687427986427789";

    sort(s.begin(), s.end(), greater<int>());
    
    cout << s << endl;

    return 0;
}