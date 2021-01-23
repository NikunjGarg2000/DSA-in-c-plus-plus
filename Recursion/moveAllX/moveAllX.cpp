#include<iostream>
using namespace std;

// Move all x to the end
string moveAllX(string s) {

    if (s.length() == 0) {
        return "";
    }

    char ch = s[0];
    string ans = moveAllX(s.substr(1));

    if (ch == 'x') {
        return ans + ch;
    }  

    return ch + ans;

}

int main() {

    string s;
    getline(cin, s);

    cout << moveAllX(s) << endl;

    return 0;
}