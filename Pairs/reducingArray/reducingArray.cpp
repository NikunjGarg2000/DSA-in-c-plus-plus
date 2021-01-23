#include<iostream>
#include<vector>
using namespace std;

// Given an array with n distinct elements,
// convert the given array to a form where all elements are in range from 0 to n-1. 
// The order of elements is same, i.e., 0 is placed in place of smallest element, 
// 1 is placed for second smallest element, … n-1 is placed for largest element

bool myCompare(pair <int, int> p1, pair <int, int> p2) {
    return p1.first < p2.first;
} 

int main() {

    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    vector <pair<int, int>> v;
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        // pair <int, int> p;
        // p.first = arr[i];
        // p.second = i;
        // v.push_back(p);
        v.push_back (make_pair(arr[i],i));
    }

    // sort(v.begin(), v.end(), myCompare);
    for (int i = 0; i < v.size(); i++) {
        arr[v[i].second] = i;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}