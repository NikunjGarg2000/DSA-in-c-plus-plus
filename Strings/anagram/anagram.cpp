// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase
// Assuming both strings have same size and contains only lowercase letters

// using character arrays as string instead of predefined string

#include<iostream>
using namespace std;

int main() {

    char a[] = "decimal";
    char b[] = "medical";

    int check[26] = {0};

    int i = 0;

    for (; a[i] != '\0'; i++) {
        check[a[i] - 'a']++;pr
    }

    for (i = 0; b[i] != '\0'; i++) {
        check[b[i] - 'a']--;
        if (check[b[i] - 'a'] == -1) {
            break;
        } 
    }

    if (b[i] == '\0') {
        cout << "It's anagram";
    } else {
        cout << "It's not anagram";
    }


    return 0;
}