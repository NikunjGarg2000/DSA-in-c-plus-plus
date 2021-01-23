#include<iostream>
using namespace std;

int pathsPossible(int s, int e) {

    if (s == e) {
        return 1;
    }

    if (s > e) {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++) {
        count += pathsPossible(s + i, e);
    }

    return count;
    
}

int main() {

    cout << pathsPossible(0, 3);
    return 0;

}