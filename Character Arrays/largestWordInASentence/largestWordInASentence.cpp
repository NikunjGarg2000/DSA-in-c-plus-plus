#include<iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    char arr[n + 1];
    
    cin.getline(arr, n+1);
    cin.ignore();

    int currLength = 0, maxLength = 0, i = 0;
    int startIndex = 0, maxIndex = 0;

    while (1) {

        if (arr[i] == ' ' || arr[i]== '\0') {
            if (currLength > maxLength) {
                maxLength = currLength;
                maxIndex = startIndex;
            }
            currLength = 0;
            startIndex = i+1;
        } else {
            currLength++;
        }

        if (arr[i] == '\0') {
            break;
        }
        i++;
    }

    cout << maxLength << endl;
    for (int i = 0; i < maxLength; i++) {
        cout << arr[i + maxIndex];
    }

    return 0;
}