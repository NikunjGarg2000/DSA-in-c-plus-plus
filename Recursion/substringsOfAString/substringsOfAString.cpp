#include<iostream>
using namespace std;

void subStrings(string s, string ans) {

    if (s.length() == 0) {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subStrings(ros, ans);
    subStrings(ros, ans + ch);
    subStrings(ros, ans + to_string(code));

}

int main() {

    string s;
    getline(cin, s);

    string ans = "";

    subStrings(s, ans);

    return 0;
}