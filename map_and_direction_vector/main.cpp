
#include <algorithm>
#include <iostream>
#include <vector>

const int n = 3;
int a[n][n], visited[n][n];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x) {
    visited[y][x] = 1;
    std::cout << "(" << y << ", " << x << ")\n";
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
            continue;  // 언더, 오버 플로우 확인
        }
        if (a[ny][nx] == 0) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        go(ny, nx);
    }
    return;
}

int main() {
    /*
     * 1, 0, 1
     * 1, 0, 1
     * 0, 1, 1
     */
    a[0][0] = 1; a[0][1] = 0; a[0][2] = 1;
    a[1][0] = 1; a[1][1] = 0; a[1][2] = 1;
    a[2][0] = 0; a[2][1] = 1; a[2][2] = 1;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         std::cin >> a[i][j];
    //     }
    // }
    go(0, 0);
}
// 갈 수 있는 곳 : (0, 0)(1, 0)