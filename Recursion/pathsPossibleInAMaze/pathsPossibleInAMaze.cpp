#include<iostream>
using namespace std;

int pathsPossible(int n, int i, int j) {

    if (i == n - 1 || j == n - 1) {
        return 1;
    }

    if (i > n - 1 || j > n - 1) {
        return 0;
    }

    return pathsPossible(n, i + 1, j) + pathsPossible(n, i, j + 1);

}

int main() {

    cout << pathsPossible(3, 0, 0); 
    return 0;

}