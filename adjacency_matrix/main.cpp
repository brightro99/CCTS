
#include <algorithm>
#include <iostream>
#include <vector>

const int V = 10;

void go(int from, bool matrix[V][V], bool* visited) {
    visited[from] = 1;
    std::cout << from << '\n';
    for (int i = 0; i < V; i++) {
        if (visited[i]) continue;
        if (matrix[from][i]) {
            go(i, matrix, visited);
        }
    }
    return;
}

int main() {
    bool matrix[V][V] = {
        0,
    };
    bool visited[V] = {
        0,
    };

    matrix[1][2] = 1;
    matrix[1][3] = 1;
    matrix[3][4] = 1;
    matrix[2][1] = 1;
    matrix[3][1] = 1;
    matrix[4][3] = 1;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] && visited[i] == 0) {
                go(i, matrix, visited);
            }
        }
    }
    return 0;
}