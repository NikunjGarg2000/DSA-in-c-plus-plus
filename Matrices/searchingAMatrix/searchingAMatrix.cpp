#include<iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int array[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
        }
    }

    int key;
    cin >> key;

    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] == key) {
                flag = true;
                break;
            }
        }
    }

    if (flag == true) {
        cout << "Key found!" << endl;
    } else {
        cout << "Key not found!" << endl;
    }

    return 0;
}