
#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<int> formula) {
    for (int i : formula) std::cout << i << " ";
    std::cout << '\n';
}

void combi(int start, int *arr, std::vector<int> &formula, int size, int pick) {
    if (formula.size() == pick) {  // k개 뽑히면 리턴이다.
        print(formula);
        return;
    }
    for (int i = start + 1; i < size; i++) {
        formula.push_back(arr[i]);  // 인덱스로 뽑고 싶으면 i로 바꾸면 된다.
        combi(i, arr, formula, size, pick);
        formula.pop_back();
    }
    return;
}

void pascal_triangle(int n) {
    for (int line = 1; line <= n; line++) {
        int c = 1; // 맨 왼쪽 값
        for (int i = 1; i <= line; i++) {
            std::cout << c << " ";
            c = c * (line - i) / i; // line - 1 = (n - k + 1)
        }
        std::cout << "\n";
    }
    return;
}

int main() {
    int size = 5, pick = 3, a[5] = {1, 2, 3, 4, 5};
    std::vector<int> formula;
    combi(-1, a, formula, size, pick);  // 재귀 함수

    std::cout << "\n";
    // 반복문
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                std::cout << a[i] << " " << a[j] << " " << a[k] << '\n';
            }
        }
    }
    pascal_triangle(5);
    return 0;
}

/* index
0 1 2
0 1 3
0 1 4
0 2 3
0 2 4
0 3 4
1 2 3
1 2 4
1 3 4
2 3 4
*/