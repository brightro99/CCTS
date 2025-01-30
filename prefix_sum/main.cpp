
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    /*
     * 수의 개수 N, 합을 구해야하는 횟수 M
     * N개의 수가 주어지고 수는 100이하의 자연수.
     * M개의 줄에는 합을 구해야하는 구간 A, B가 주어진다.
     */

    int arr[100004], start, end, psum[100004], n, m;
    std::cout << "반복문을 이용한 누적합\n";
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> start >> end;
        int sum = 0;
        for (int j = start; j <= end; j++) {
            sum += arr[j];
        }
        std::cout << sum << '\n';
    }

    std::cout << "누적합을 이용한 누적합\n";
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> n >> m;

    // 누적합 구하기
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> start >> end;
        std::cout << psum[end] - psum[start - 1] << "\n";
    }
    return 0;
}