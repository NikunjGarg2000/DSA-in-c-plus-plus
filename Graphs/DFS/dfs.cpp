#include<iostream>
#include<stack>
using namespace std;

void DFS(int graph[][8], int n, int start) {
    static int visitedArray[8] = {0};
    int u = start;

    if (visitedArray[u] == 0) {
        cout << u << " ";
        visitedArray[u] = 1;
        for (int j = 1; j <= n; j++) {
            if (graph[u][j] == 1 && visitedArray[j] == 0) {
                DFS(graph, n, j);
            }
        }
    }
}

int main() {

    int graph[][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 1, 1, 1, 0, 0, 0},
                      {0, 1, 0, 0, 1, 0, 0, 0},
                      {0, 1, 0, 0, 0, 1, 0, 0},
                      {0, 1, 1, 0, 0, 1, 0, 0},
                      {0, 0, 0, 1, 1, 0, 1, 1},
                      {0, 0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0, 1, 0, 0}};
    DFS(graph, 8, 1);
    return 0;

    return 0;
}