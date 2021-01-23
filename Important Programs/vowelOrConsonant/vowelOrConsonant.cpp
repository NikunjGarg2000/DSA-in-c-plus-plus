#include<iostream>
using namespace std;

int main() {

    cout << "Enter an alphabet" << endl;

    char c;
    cin >> c;

    int lowercase_vowel, uppercase_vowel;

    lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercase_vowel || uppercase_vowel) {
        cout << "It is a vowel";
    } else {
        cout << "It is a consonant";
    }    

    return 0;
}