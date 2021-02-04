// make the biggest possible no. from given string

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s = "647687427986427789";

    // usually sort function performs quick sort which has an average time complexity of Θ(nlogn) and worst is O(n2)

    // use #include <algorithm> to use inbuilt sort function
    // sorting in descending order

    sort(s.begin(), s.end(), greater<int>());

    cout << s << endl;

    return 0;
}