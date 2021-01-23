#include<iostream>
using namespace std;

int knapsack(int value[], int weight[], int n, int w) {

    if (n == 0 || w == 0) {
        return 0;
    }

    if (weight[n - 1] > w) {
        return knapsack(value, weight, n - 1, w);
    }

    return max(knapsack(value, weight, n - 1, w - weight[n - 1]) + value[n - 1], knapsack(value, weight, n - 1, w));

}

int main() {

    int weight[] = {10, 20, 30};
    int value[] = {100, 50, 150};
    int w = 50;

    cout << knapsack(value, weight, 3, w);
    return 0;

}