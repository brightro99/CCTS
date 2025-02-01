
#include <algorithm>
#include <iostream>
#include <vector>

const int V2 = 10;
std::vector<int> adj2[V2];
int visited[V2];

void go(int idx) {
    std::cout << idx << '\n';
    visited[idx] = 1;
    for (int there : adj2[idx]) {
        if (visited[there]) continue;
        go(there);
    }
    return;
}

int main() {
    const int V1 = 4;
    std::vector<int> adj1[V1];
    adj1[0].push_back(1);
    adj1[0].push_back(2);
    adj1[0].push_back(3);

    adj1[1].push_back(0);
    adj1[1].push_back(2);

    adj1[2].push_back(0);
    adj1[2].push_back(1);

    adj1[3].push_back(0);

    for (int i = 0; i < 4; i++) {
        std::cout << i << " :: ";
        for (int there : adj1[i]) {
            std::cout << there << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    // 아래 방법도 가능
    for (int i = 0; i < 4; i++) {
        std::cout << i << " :: ";
        for (int j = 0; j < adj1[i].size(); j++) {
            std::cout << adj1[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    adj2[1].push_back(2);
    adj2[2].push_back(1);
    adj2[1].push_back(3);
    adj2[3].push_back(1);
    adj2[3].push_back(4);
    adj2[4].push_back(3);
    for (int i = 0; i < V2; i++) {
        if (adj2[i].size() && visited[i] == 0) {
            go(i);
        }
    }
}