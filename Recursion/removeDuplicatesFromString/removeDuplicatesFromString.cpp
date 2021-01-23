#include<iostream>
using namespace std;

// By myself
// void removeDuplicates(string s) {
//     if(s.length() == 0) {
//         return;
//     }
//     int i = 0;
//     while (s[i+1] == s[i]) {
//         i++;
//     }
//     cout << s[i];
//     removeDuplicates(s.substr(i+1));
// }

string removeDupli(string s) {

    if (s.length() == 0) {
        return "";
    }

    char ch = s[0];
    string ans = removeDupli(s.substr(1)); 

    if (ans[0] == ch) {
        return ans;
    }

    return ch + ans;
 
}

int main() {

    // removeDuplicates("abaagsjaaababbbb");
    cout << removeDupli("aaaabbbbbcddddeeffff") << endl;

    return 0;
}