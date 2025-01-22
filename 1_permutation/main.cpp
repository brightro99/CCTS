#include <algorithm>
#include <iostream>

void print(int* a, int r) {
    std::cout << "result : ";
    for (int i = 0; i < r; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void makePermutation(int* a, int n, int r, int depth) {
    std::cout << n << " " << r << " " << depth << "\n";
    if (r == depth) {
        print(a, r);
        return;
    }

    for (int i = depth; i < n; i++) {
        std::swap(a[i], a[depth]);
        std::cout << "swap #1: " << a[i] << " " << a[depth] << "\n";
        makePermutation(a, n, r, depth + 1);
        std::swap(a[i], a[depth]); // 원복
        std::cout << "swap #2: " << a[i] << " " << a[depth] << "\n";
    }
    return;
}

int main() {
    int a[] = {1, 2, 3};
    do {
        for (int i : a) std::cout << i << " ";
        std::cout << "\n";
    } while (std::next_permutation(&a[0], &a[0] + 3));
    // while(next_permutation(a, a + 3));
    std::cout << "\n";
    
    std::vector<int> b = {2, 1, 3};
    // std::sort(b.begin(), b.end());
    do {
        for (int i : b) std::cout << i << " ";
        std::cout << "\n";
    } while (next_permutation(b.begin(), b.end()));
    /*
     * 정렬을 안하고 2, 1, 3일 경우에는 2 1 3, 2 3 1, 3 1 2, 3 2 1 이렇게 4가지만 나온다.
     * 순열을 사용시 정렬은 필수이다.
     */
    std::cout << "\n";

    std::vector<int> c = {2, 1, 3};
    std::sort(c.begin(), c.end());
    do {
        for (int i = 0; i < 2; i++) {
            std::cout << c[i] << " ";
        }  // slice
        std::cout << "\n";
    } while (next_permutation(c.begin(), c.end()));
    std::cout << "\n";
    
    int d[3] = {1, 2, 3};
    int n = 3, r = 3;

    makePermutation(a, n, r, 0);
    return 0;
}