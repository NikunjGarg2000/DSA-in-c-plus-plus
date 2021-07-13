#include<iostream>
using namespace std;

string keypadArray[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "wxyz"};

void keypad(string s, string ans) {

    if (s.length() == 0) { 
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string code = keypadArray[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < code.length(); i++) {
        keypad(ros, ans + code[i]);
    }

}

// approach 2: Assuming rest is done except ch[0];
// vector<string> possibleWords(string digits) {
//     if (digits.length() == 0) {
//             vector<string> temp;
//             temp.push_back("");
//             return temp;
//         }
        
//         char ch = digits[0];
//         vector<string> midRes = possibleWords(digits.substr(1));
        
//         vector<string> ans;
//         string code = keypad[ch - '0'];
//         for (int i = 0; i < code.length(); i++) {
//             char c = code[i];
//             for (int j = 0; j < midRes.size(); j++) {
//                 ans.push_back(c + midRes[j]);
//             }
//         }
//         return ans;
// }

int main() {

    keypad("23", "");

    return 0;
 }